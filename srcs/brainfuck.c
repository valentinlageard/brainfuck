#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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

unsigned char *initialize_str(char *instructions)
{
    unsigned char *str;
    int i = 0;
    int char_count = 0;

    while (instructions[i])
    {
        if (instructions[i] == '.')
            char_count++;
        i++;
    }
    if (!(str = (unsigned char *)malloc((char_count + 1) * sizeof(char))))
        str = NULL;
    else
    {
        i = 0;
        while (i <= char_count)
        {
            str[i] = 0;
            i++;
        }
    }
    return (str);
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

void brainfuck(char *instructions, int memory, int verbose, int speed, int prompt)
{
    unsigned char *bytes;
    unsigned char *bytes_start;
    unsigned char *str;
    unsigned int size = memory;
    int i = 0;
    int j = 0;
    int pos = 0;

    bytes = initialize_bytes(size);
    bytes_start = bytes;
    str = initialize_str(instructions);
    while (instructions[i])
    {
        if (instructions[i] == '>')
        {
            pos++;
            if (pos == size)
            {
                printf("Error : Memory overflow.\n");
                return ;
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
                return ;
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
            str[j] = *bytes;
            j++;
        }
        else if (instructions[i] == '[')
        {
            if (*bytes == 0)
                i = find_next_bracket(instructions, i, size);
        }
        else if (instructions[i] == ']')
        {
            if (*bytes != 0)
                i = find_prev_bracket(instructions, i);
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
    printf("%s\n", str);
    free(bytes_start);
    free(str);
}
