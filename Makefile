SRCS	= main.c stored_args.c stack_infos.c stack_utilities.c push_swap.c rotate.c 

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
