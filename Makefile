SRCS	= main.c pile_utils.c stack_utils.c print_infos.c parser.c actions.c sort.c exec_args.c delmem.c

NAME	= push_swap

INC		= -I ./

FLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

${NAME} : ${OBJS}
		make -C ./ft_printf/ fclean
		make -C ./ft_printf/
		gcc -o $(NAME) $(INC) $(SRCS) ./ft_printf/libftprintf.a
		

all : ${NAME}
	ar rcs ${NAME} ${OBJS}

clean :
		rm -f ${OBJS} ${OBJS_BONUS}

fclean : clean
		rm -f ${NAME}

re : fclean all
