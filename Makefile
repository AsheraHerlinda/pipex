NAME = 			pipex

SRCS =			./src/pipex.c \
				./src/pipex_utils.c \
				./src/get_commands.c \
				./src/end_programm.c \

OBJS =			${SRCS:.c=.o}

CC 		=	gcc 
RM 		=	rm -f
FLAGS 	=	-Wall -Wextra -Werror
HEAD	=	./inc/pipex.h
INC		=	-I ./libft
LIB		=	-L ./libft -lft
LFT		=	./libft/libft.a

all:	${LFT} ${NAME}

${NAME}: ${OBJS}
		${CC} -o ${NAME} $^ ${LIB}

${LFT}: 
		make -s -C libft

%.o:	%.c ${HEAD} Makefile
		${CC} ${FLAGS} ${INC} -c $< -o $@

clean:
		@make -s $@ -C libft
		${RM} ${OBJS}

fclean: clean
		@make -s $@ -C libft
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re