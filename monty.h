#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*functions_ProtoTypes*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/*Helper_Functions_ProtoTypes*/
stack_t *add_node(stack_t **stack, int n);
void free_stack(stack_t *stack);
void execute_instruction(stack_t **stack, char *opcode
, unsigned int line_number);
int is_integer(char *str);
void print_stack(stack_t *stack);
size_t stack_len(const stack_t *stack);
char *get_opcode(char *line);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);
void parse_input(FILE *fp);
#endif /* MONTY_H */
