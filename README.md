# Monty Interpreter

This is a program that interprets Monty byte code files and executes the operations specified in them on a unique stack data structure.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Files](#files)
- [Data Structures](#data-structures)
- [Operations](#operations)
- [Examples](#examples)
- [Authors](#authors)

## Introduction

Monty is a scripting language that relies on a unique stack data structure to manipulate data. A Monty byte code file is a file containing Monty byte codes, which are instructions to be executed by the interpreter. Each instruction is represented by a keyword and, optionally, an argument. Instructions are executed in the order they appear in the file. The interpreter reads a Monty byte code file and performs the specified operations on the stack. The program also handles error conditions, such as invalid instructions or stack underflow.

## Usage

To use the Monty interpreter, run the following command:

```
$ ./monty <file>
```

Where `<file>` is the path to the file containing the Monty byte code.

## Files

The Monty interpreter consists of the following files:

- `monty.c`: The main file that reads the Monty byte code file and executes the instructions.
- `parse.c`: Functions to parse the Monty byte code file and extract the instructions and arguments.
- `stack.c`: Functions to manipulate the stack data structure, such as push, pop, and swap.
- `queue.c`: Functions to manipulate the queue data structure, such as enqueue and dequeue.
- `opcodes.c`: Functions that implement the Monty byte code instructions.
- `monty.h`: The header file that defines the data structures and function prototypes.

## Data Structures

The Monty interpreter uses the following data structures:

- `stack_t`: A doubly linked list representation of a stack or queue element, with an integer value `n` and pointers to the previous and next elements.
- `instruction_t`: A structure that associates a Monty byte code instruction with its corresponding function.

## Operations

The following operations are supported by the Monty interpreter:

- `push`: Pushes an integer onto the stack.
- `pall`: Prints all the values on the stack, starting from the top.
- `pint`: Prints the value at the top of the stack.
- `pop`: Removes the top element of the stack.
- `swap`: Swaps the top two elements of the stack.
- `add`: Adds the top two elements of the stack.
- `nop`: Does nothing.
- `sub`: Subtracts the top element of the stack from the second top element.
- `div`: Divides the second top element of the stack by the top element.
- `mul`: Multiplies the second top element of the stack with the top element.
- `mod`: Computes the remainder of the division of the second top element of the stack by the top element.
- `pchar`: Prints the ASCII character of the value at the top of the stack.
- `pstr`: Prints the ASCII string starting at the top of the stack.
- `rotl`: Rotates the stack to the top.
- `rotr`: Rotates the stack to the bottom.
- `queue`: Sets the format of the data structure to a queue.
- `stack`: Sets the format of the data structure to a stack.

## Examples

Here are some examples of valid Monty byte code files:

```
push 1
push 2
push 3
pall
pop
pall
```

This program pushes the integers
