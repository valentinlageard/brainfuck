#ifndef BRAINFUCK_H
#define BRAINFUCK_H

void brainfuck(char *instructions, int memory, int verbose, int speed, int prompt, int decimal_print);
void print_bytes(unsigned char *bytes_start, unsigned int size, int pos, unsigned char *str, char instruction);
void print_help(void);
void decimal_print(char *str);

#endif
