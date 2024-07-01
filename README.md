
<h1 align="center">
	Minishell :As beautiful as a shell  :shell:
</h1>


<p align="center">
<b><i>A lightweight command-line interface</i></b><br>
</p>
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/lamiae-sadiq/Minishell?color=green" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/lamiae-sadiq/Minishell?color=red" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/lamiae-sadiq/Minishell?color=violet" />
</p>

## 💡 Summary
This project involves creating a simple shell, akin to a mini bash. The aim is to gain a deeper understanding of processes and file descriptors.

## Project Overview
Minishell is a project designed to emulate the functionalities of a Unix shell. By building this project, you will dive into the workings of processes, file descriptors, and system calls. The shell will support interactive command execution, script execution, and built-in commands.

## Features
### Interactive Shell: 
- Display a prompt and wait for user input.
### Command Execution: 
  - Execute commands by searching for the right executable based on the PATH variable or using a relative/absolute path.
### Built-in Commands: 
  - Implement built-in commands such as ```echo```, ```cd```, ```pwd```, ```export```, ```unset```, ```env```, and ```exit```.
### Redirections: 
  - Handle input and output redirections using ```<```, ```>```, ```<<```, and ```>>```.
### Pipes: 
  - Implement pipelines using the ```|``` character.
### Environment Variables:
  - Expand environment variables prefixed with $.
### Signal Handling: 
  - Handle ```ctrl-C```, ```ctrl-D```, and ```ctrl-\``` similar to bash.
