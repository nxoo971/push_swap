SRCS	=	main.c		parse_args.c	pile_utils.c	print.c	\
			$(addprefix consign/, push.c rotate.c swap.c)		\
			sort.c		count_move.c	median.c		find.c	\
			choice.c	utils.c			free.c

SRCS_B	=	$(addprefix bonus/, main.c)						\
			parse_args.c	pile_utils.c	print.c			\
			$(addprefix consign/, push.c rotate.c swap.c)	\
			choice.c		utils.c			free.c

NAME	= push_swap

NAME_B	= checker

INC		= -I ./

FLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
		make -C ./ft_printf/libft/
		make -C ./ft_printf/
		gcc ${FLAGS} ${INC} $(OBJS) -o $(NAME) ft_printf/libftprintf.a

%.o:%.c
		gcc ${FLAGS} -c $< -o $@

bonus :	${OBJS_B}
		gcc ${FLAGS} ${INC} $(OBJS_B) -o $(NAME_B) ft_printf/libftprintf.a

clean :
		make -C ./ft_printf/ clean
		make -C ./ft_printf/libft/ clean
		rm -rf ${OBJS} ${OBJS_B}

fclean : clean
		rm -rf ${NAME} ${NAME_B} ft_printf/libftprintf.a ft_printf/libft/libft.a

re : fclean all

.PHONY : all bonus clean fclean re