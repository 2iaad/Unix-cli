<div align="center">

# Minishell

**As beautiful as a shell**

Minishell is a project aimed at creating a simple shell, similar to Bash. This project will enhance your understanding of processes and file descriptors in Unix-like operating systems. 

</div>

## How to use it
```bash
git clone https://github.com/2iaad/Mini-Shell 2iaad && cd 2iaad && make && ./minishell
```

## Contents

- [I. Introduction](#i-introduction)
- [II. Mandatory Part](#ii-mandatory-part)
- [III. Bonus Part](#iii-bonus-part)

## I. Introduction
The existence of shells is fundamental to the field of computing. They provide a way for users to interact with computers through command lines rather than low-level hardware manipulations. Minishell allows you to step back in time and tackle the challenges faced before modern GUI environments, providing a hands-on experience with shell programming.

- **Program Name**: `minishell`
- **Turn In Files**: `Makefile`, `*.h`, `*.c`
- **Arguments**: 
  - Use external functions like `readline`, `printf`, `malloc`, etc.
- **Libft Authorized**: Yes
- **Description**: Implement a shell that:
  - Displays a prompt when waiting for a command.
  - Maintains a command history.
  - Searches and executes commands based on the `PATH` variable or relative/absolute paths.
  - Avoids using more than one global variable for signal handling.
  - Implements quote handling for both single (`'`) and double (`"`) quotes.
  - Implements input/output redirection and piping.
  - Expands environment variables and the exit status of the last command.
  - Handles control signals (`ctrl-C`, `ctrl-D`, `ctrl-\`) appropriately.
    
- **Builtins to Implement**:
  - `echo` (with `-n`)
  - `cd` (with paths)
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`