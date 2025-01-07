![simple_shell](image.png)

[document simple shell](vscode-local:/c%3A/Users/selve/Downloads/simple%20shell%20noor%20mina.pdf)

![description](https://img.shields.io/badge/description-1.9.0-yellow)

![features](https://img.shields.io/badge/features-MA-black)

![compilation](https://img.shields.io/badge/compilation-MA-green)

![usage](https://img.shields.io/badge/usage-MA-blue)

![examples](https://img.shields.io/badge/examples-MA-red)

![authors](https://img.shields.io/badge/authors-MA-pink)

![license](https://img.shields.io/badge/license-MA-orange)


# Simple Shell
A basic UNIX command interpreter written in C.

# Table of Contents

## Introduction
Overview of Unix Shell and Its Importance.

Purpose of the Project.

### Background Information
History of Unix and the Thompson Shell.

Ken Thompson and the Creation of Unix.

The First Version of the UNIX Shell.

The B Programming Language.

Development and Influence on C.

### Learning Objectives
Key Concepts to Understand.

What is a Shell?

Understanding PID and PPID.

Environment Manipul.

### Requirements
General Guidelines for Coding

Compilation Instructions

Style and Documentation Requirements

### Output Specifications
Expected Behavior in Interactive Mode

Expected Behavior in Non-Interactive Mode

### Allowed Functions and System Calls
List of Functions to Use

Explanation of Each Function's Purpose

### Testing and Validation
Testing Methodology

Importance of Collaborative Testing

### Conclusion
Summary of Key Takeaways

Future Directions for Learning

## Project Overview
This project aims to develop a custom Unix shell, inspired by the original Thompson shell created by Ken Thompson in 1971. The shell will function similarly to the standard sh shell, providing users with a command-line interface to execute commands, manage processes, and manipulate the environment.

## Objectives
By the end of this project, participants will be able to
### Understand Unix History:
 Explain the design and implementation of the original Unix operating system and identify its key contributors, particularly Ken Thompson.

### Shell Functionality:
 Describe how a shell operates, including process management, input/output redirection, and command execution.

### Process Identification:
 Define what a process identifier (PID) and parent process identifier (PPID) are, and how they are utilized in Unix systems.

### Environment Manipulation:
 Learn how to manipulate the environment of the current process using environment variables like PATH.
System Calls vs. Functions: Differentiate between functions and system calls, and understand when to use each in programming.

### Process Creation: 
Create new processes using system calls such as fork and execve.

### EOF Handling: 
Recognize what EOF (end-of-file) signifies in a command-line context.

## Requirements
Participants are expected to adhere to specific coding standards and guidelines:

Use editors such as vi, vim, or emacs.
Code must be compiled on Ubuntu 20.04 LTS using gcc with strict flags for error checking.

All files should end with a newline, and a README.md file must be included at the project root.

Code should follow the Betty style guide to ensure readability and maintainability.

The shell must be free of memory leaks and have no more than five functions per file.


## Authorized Functions and Macros
For this project, the following functions and macros are authorized for use in your shell implementation. These functions are essential for process management, input/output operations, and string manipulation within a Unix environment.

### String Manipulation:
All functions from string.h (e.g., strlen, strcpy, strcat, etc.)

## Man Page

### NAME:
hsh - a simple Unix shell implementation in C

hsh is a command-line interpreter that allows users to execute commands and manage processes in a Unix-like environment, replicating the behavior of the standard Unix shell (sh).

### Interactive Mode:
 Start the shell with:

./hsh

### Non-Interactive Mode:
 Pipe commands into the shell:

 echo "/bin/ls" | ./hsh

### EXIT STATUS:
Returns "0" on success.

Returns "1" on failure.


## Description
This project is a simple implementation of a UNIX shell. It allows the execution of basic commands and offers features such as process management and basic input/output redirection.

## Features
Execution of simple commands
Path handling (PATH)
Child process management
Basic input/output redirection
Signal handling (Ctrl+C)

## Compilation
### To compile the shell, use the following command
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Usage
### Launch the shell in interactive mode
./hsh

### Or use it in non-interactive mode
echo "/bin/ls" | ./hsh

## Examples
$ ./hsh
/bin/ls
hsh main.c shell.c
exit
$

## Authors
MINS2405
ni-mdj

## License
This project is licensed under the MIT License. See the LICENSE file for details.

