#ifndef BRAINFUCK_H
#define BRAINFUCK_H

void brainfuck(char *instructions, int memory, int verbose, int speed, int prompt);
void print_bytes(unsigned char *bytes_start, unsigned int size, int pos, char *str, char instruction);
void print_help(void);

#endif
