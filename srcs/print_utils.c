#include <stdio.h>
#include <string.h>

void print_bytes(unsigned char *bytes_start, unsigned int size, int pos, unsigned char *str, char instruction)
{
    printf("|");
    for (int i = 0; i < size; i++)
        printf("%2x|", bytes_start[i]);
    printf(" : %s ", str);
    printf("\n");
    for (int i = 0; i < pos; i++)
        printf("   ");
    printf(" /%c\\ ", instruction);
    printf("\n");
}

void print_help(void)
{
  printf("Brainfuck is a brainfuck interpreter written in C.\n");
  printf("Options : \n");
  printf("\t-i \"brainfuck instructions\" : Brainfuck instructions to be interpreted.\n");
  printf("\t-v : Verbose mode. Displays the memory, the head and the executed instruction.\n");
  printf("\t-s \"speed in ms\" : Speed of the verbose mode in ms (50ms by default).\n");
  printf("\t-p : Prompt mode of the verbose mode. You have to press Enter to pass from step to step. Force verbose mode.\n");
  printf("\t-m \"memory in bytes\" : Memory size (20 bytes by default).\n");
  printf("\nTry these instructions for instance : \"++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.\"\n");
  printf("\nDistributed under CC-BY Licence by Valentin Lageard (valentin.lageard.pro@gmail.com).\n");
}

void decimal_print(unsigned char *str)
{
  int i = 0;

  while (str[i])
  {
    printf("%d", str[i]);
    if (i != strlen(str) - 1)
      printf(" ");
    i++;
  }
}
