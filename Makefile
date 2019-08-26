NAME		= brainfuck
SRCS 		= srcs/main.c srcs/brainfuck.c srcs/print_utils.c
HEADER	= includes
CFLAGS	= -I./${HEADER}
CC			= gcc
OBJS		= $(SRCS:.c=.o)
RM			= rm -f

all:			${NAME}

${NAME}:	${OBJS}
					${CC} -o ${NAME} ${OBJS}

clean:
					${RM} ${OBJS}
fclean:		clean
					${RM} ${NAME}
re:				fclean all
