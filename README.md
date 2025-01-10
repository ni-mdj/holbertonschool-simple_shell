
# <span style="color:orange;"> THE SIMPLE SHELL</span>
A simple shell is a basic software program that provides a text-based interface between the user and the operating system, allowing users to interact with the computer by typing commands directly.

- [ THE SIMPLE SHELL](#-the-simple-shell)
- [ Function](#-function)
  - [Allowed functions and system calls+](#allowed-functions-and-system-calls)
    - [1. String functions (`string.h`)](#1-string-functions-stringh)
    - [2. Memory management (`stdlib.h`, `malloc.h`)](#2-memory-management-stdlibh-malloch)
    - [3. I/O functions (`stdio.h`)](#3-io-functions-stdioh)
    - [4. File functions (`dirent.h`, `fcntl.h`)](#4-file-functions-direnth-fcntlh)
    - [5. Process management (`process`, `fork`, `signal`)](#5-process-management-process-fork-signal)
    - [6. File status (`sys/stat.h`)](#6-file-status-sysstath)
    - [7. File system (`unistd.h`)](#7-file-system-unistdh)
    - [8. Misc functions](#8-misc-functions)
  - [Functions and Definitions](#functions-and-definitions)
  - [Compilation command](#compilation-command)
  - [Requirements](#requirements)
  - [Usage Examples](#usage-examples)
- [Testing ](#testing-)
- [Flowchart](#flowchart)
- [Authors](#authors)
# <span style="color:yellow;"> Function</span>
## Allowed functions and system calls+

### 1. String functions (`string.h`)
| **Function**  | **Description**                               |
|---------------|-----------------------------------------------|
| `strtok`      | Splits a string into tokens.                  |

### 2. Memory management (`stdlib.h`, `malloc.h`)
| **Function**  | **Description**                               |
|---------------|-----------------------------------------------|
| `malloc`      | Allocates memory.                             |
| `free`        | Frees memory.                                 |
| `_exit`       | Exits without cleanup.                       |

### 3. I/O functions (`stdio.h`)
| **Function**  | **Description**                               |
|---------------|-----------------------------------------------|
| `fflush`      | Flushes a stream.                             |
| `fprintf`     | Formats and writes to a stream.               |
| `printf`      | Formats and writes to standard output.        |
| `sprintf`     | Formats and writes to a string.               |
| `putchar`     | Prints a character.                           |
| `perror`      | Prints error message.                         |
| `getcwd`      | Gets current directory.                       |
| `getline`     | Reads a line from a stream.                   |
| `isatty`      | Checks if a descriptor is a terminal.         |

### 4. File functions (`dirent.h`, `fcntl.h`)
| **Function**  | **Description**                               |
|---------------|-----------------------------------------------|
| `open`        | Opens a file.                                 |
| `close`       | Closes a file.                                |
| `read`        | Reads from a file.                            |
| `write`       | Writes to a file.                             |
| `opendir`     | Opens a directory.                            |
| `readdir`     | Reads a directory entry.                      |
| `closedir`    | Closes a directory.                           |

### 5. Process management (`process`, `fork`, `signal`)
| **System Call** | **Description**                              |
|-----------------|----------------------------------------------|
| `fork`          | Creates a new process.                       |
| `execve`        | Replaces the current process image.          |
| `exit`          | Exits the program.                           |
| `getpid`        | Gets process ID.                             |
| `kill`          | Sends a signal to a process.                 |
| `signal`        | Sets signal handling.                        |
| `wait`          | Waits for child process termination.         |
| `waitpid`       | Waits for a specific child process.          |

### 6. File status (`sys/stat.h`)
| **Function**  | **Description**                               |
|---------------|-----------------------------------------------|
| `stat`        | Gets file status.                             |
| `lstat`       | Gets file status (symlinks treated differently). |
| `fstat`       | Gets file status using file descriptor.      |

### 7. File system (`unistd.h`)
| **System Call** | **Description**                              |
|-----------------|----------------------------------------------|
| `access`        | Checks file access permissions.              |
| `chdir`         | Changes the current directory.               |

### 8. Misc functions
| **Function**  | **Description**                               |
|---------------|-----------------------------------------------|
| `getpid`      | Returns the process ID.                       |



## Functions and Definitions
  - <span style="color:brown;"> Display_shell:</span> *Displays a prompt for the user to enter a command. It typically represents the interactive shell.*
 - <span style="color:brown;"> Execute_command:</span> *Executes a command by searching for its path in PATH, then launches a child process using execve. It also handles special commands like exit and env.*
- <span style="color:brown;"> Read_line:</span> *Reads a line of input entered by the user, usually using fgets or getline to capture standard input.*
- <span style="color:brown;"> Tokenize_command:</span> *Splits a command line into tokens (arguments) separated by spaces or special characters, typically using strtok, to prepare for execution.*
 - <span style="color:brown;"> Execute_fork:</span> *Creates a child process using fork to execute a command. The child process uses execve to run the command, while the parent process waits for the child to finish.*
- <span style="color:brown;"> Main:</span> *The main function of the program, typically responsible for initialization, displaying the prompt, managing the command input loop, and executing commands until exit.*
## <span style="color:green;">Compilation command</span>
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
## <span style="color:pink;">Requirements</span>
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, 
Using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)

## <span style="color:cyan;">Usage Examples</span>
**PID (Process Identifier) and PPID (Parent Process Identifier)**
Are fundamental concepts in operating systems for managing processes.
1. <span style="color:red;">PID</span> (Process Identifier): _A PID is a unique number given to each running program on a
computer. It helps the system track and manage different processes, like giving each running program its own “name tag”_
2. <span style="color:red;">PIDD</span> (Parent Process Identifier): _A PPID is the number (ID) of the parent process that started another process. It shows which process created it. For example, if a program starts another program, the first one is the “parent”, and its ID the PPID of the second one._
PID
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
pid_t pid = fork(); // Create a new process
if (pid < 0)
{
// Error occurred during fork
perror("Error during fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
// Code executed by the child process
printf("I am the child process. My PID is %ld and my parent's PID is %ld.\n", (long)getpid(),
(long)getppid());
} else
 {
// Code executed by the parent process
printf("I am the parent process. My PID is %ld and my child's PID is %ld.\n", (long)getpid(),
(long)pid);
}
return( EXIT_SUCCESS);
}

# <span style="color:yellowgreen;">Testing </span>
![alt text](<Capture d’écran 2025-01-10 à 00.51.15.png>)

# <span style="color:purple;">Flowchart</span>
![alt text](<Image PNG.png>)

# <span style="color:aqua;">Authors</span>
- **MINA SINANI** - [MINS2405](https://github.com/MINS2405)
- **MEDJAHED NOOR** - [ni-mdj](https://github.com/ni-mdj/holbertonschool-simple_shell)