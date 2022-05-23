NAME = 			pipex
NAME_bonus = 	pipex_bonus

SRCS =			man/src/pipex.c \
				man/src/pipex_utils.c \
				man/src/get_commands.c \
				man/src/end_programm.c \

SRCS_bonus =	bonus/src/pipex_bonus.c \
				bonus/src/pipex_utils_bonus.c \
				bonus/src/get_commands.c \
				bonus/src/end_programm.c \
				bonus/src/here_doc_read.c \

OBJS =			${SRCS:.c=.o}
OBJS_bonus =	${SRCS_bonus:.c=.o}

CC 		=		gcc 
RM 		=		rm -f
FLAGS 	=		-Wall -Wextra -Werror
HEAD	=		./inc/pipex.h \
				./inc/pipex_bonus.h
INC		=		-I ./libft
LIB		=		-L ./libft -lft
LFT		=		./libft/libft.a

all:	${LFT} ${NAME}

${NAME}: ${OBJS}
		${CC} -o ${NAME} $^ ${LIB}

${LFT}: 
		make -s -C libft

bonus:	${LFT} ${NAME_bonus}

${NAME_bonus}:	${OBJS_bonus}
				${CC} -o ${NAME_bonus} $^ ${LIB}

%.o:	%.c ${HEAD} Makefile
		${CC} ${FLAGS} ${INC} -c $< -o $@

clean:
		@make -s $@ -C libft
		${RM} ${OBJS} ${OBJS_bonus}


fclean: clean
		@make -s $@ -C libft
		${RM} ${NAME} ${NAME_bonus}

re: fclean all

.PHONY: all clean fclean re bonus