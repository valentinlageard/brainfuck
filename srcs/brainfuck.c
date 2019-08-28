#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "brainfuck.h"

unsigned char *initialize_bytes(unsigned int size)
{
    unsigned int i = 0;
    unsigned char *bytes;

    if (!(bytes = (unsigned char *)malloc(size * sizeof(char))))
        bytes = NULL;
    while (i < size)
    {
        bytes[i] = 0;
        i++;
    }
    return (bytes);
}

char *append_alloc(char *str, char c)
{
    size_t len = strlen(str);
    char *str2 = malloc(len + 1 + 1 ); /* one for extra char, one for trailing zero */
    strcpy(str2, str);
    str2[len] = c;
    str2[len + 1] = '\0';
    free(str);
    return (str2);
}

int find_next_bracket(char *instructions, int i, unsigned int size)
{
    int brackets_count = 0;
    while (i < (signed)size)
    {
        if (instructions[i] == '[')
            brackets_count++;
        else if (instructions[i] == ']')
        {
            brackets_count--;
            if (brackets_count == 0)
                return (i);
        }
        i++;
    }
    return (-1);
}

int find_prev_bracket(char *instructions, int i)
{
    int brackets_count = 0;
    while (i >= 0)
    {
        if (instructions[i] == ']')
            brackets_count++;
        else if (instructions[i] == '[')
        {
            brackets_count--;
            if (brackets_count == 0)
                return (i);
        }
        i--;
    }
    return (-1);
}

void brainfuck(char *instructions, int memory, int verbose, int speed, int prompt, int d_print)
{
    unsigned char *bytes;
    unsigned char *bytes_start;
    unsigned char *str = (char *)malloc(1);
    str[0] = 0;
    unsigned int size = memory;
    int i = 0;
    int j = 0;
    int pos = 0;
    int error = 0;

    bytes = initialize_bytes(size);
    bytes_start = bytes;
    while (instructions[i])
    {
        if (instructions[i] == '>')
        {
            pos++;
            if (pos == size)
            {
                printf("Error : Memory overflow.\n");
                error = 1;
                break;
            }
            else
                bytes++;
        }
        else if (instructions[i] == '<')
        {
            pos--;
            if (pos < 0)
            {
                printf("Error : Memory underflow.\n");
                error = 1;
                break;
            }
            else
                bytes--;
        }
        else if (instructions[i] == '+')
            *bytes += 1;
        else if (instructions[i] == '-')
            *bytes -= 1;
        else if (instructions[i] == '.')
        {
            str = append_alloc(str, *bytes);
            j++;
        }
        else if (instructions[i] == '[')
        {
            if (*bytes == 0)
                i = find_next_bracket(instructions, i, size);
                if (i == -1)
                {
                  printf("Error : Uncomplete bracket\n");
                  error = 1;
                  return ;
                }
        }
        else if (instructions[i] == ']')
        {
            if (*bytes != 0)
                i = find_prev_bracket(instructions, i);
                if (i == -1)
                {
                  printf("Error : Uncomplete bracket\n");
                  error = 1;
                  return ;
                }
        }
        if (verbose)
        {
          print_bytes(bytes_start, size, pos, str, instructions[i]);
          if (prompt)
            getchar();
          else
            usleep(speed * 1000);
        }
        i++;
    }
    if (!error)
    {
      if (d_print)
        decimal_print(str);
      else
        printf("%s", str);
    }
    free(bytes_start);
    free(str);
}
