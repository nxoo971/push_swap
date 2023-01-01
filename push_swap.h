/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:35:35 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/09 07:18:29 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct s_pile
{
	int				data;
	struct s_pile	*prev;
	struct s_pile	*next;
}	t_pile;

typedef struct s_stack
{
	t_pile	*first;
	t_pile	*last;
	int		size;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*stack;
	t_pile	*pile;
}	t_push_swap;

typedef struct s_bestmove
{
	int	pair;
	int	index;
	int	maxmove;
	int	value;
	int	ra;
	int	rb;
	int	is_ra_rb;
	int	isrra_rrb;
	int	isrr;
	int	isrrr;
	int	isrra_rb;
	int	isrrb_ra;
	int	isrrb;
	int	isrra;
}	t_bestmove;

typedef void	(*t_move)(t_push_swap *ptr);
typedef void	(*t_cmd)(t_push_swap *ptr_a, t_push_swap *ptr_b);

//	pile_utils.c
t_pile		*create_elem(int data, t_stack **stack);
void		update(t_stack **stack, t_pile *first, t_pile *last);
void		add_elem(t_push_swap *ptr, int data);
int			pile_is_sorted(t_pile *pile);
//	parse_args.c
int			*parse_args(int ac, char **av, t_push_swap *ptr, int *size);
//	consign/*.c
void		push(t_push_swap *ptr_a, t_push_swap *ptr_b);
void		ss(t_push_swap *ptr_a, t_push_swap *ptr_b);
void		s(t_push_swap *ptr);
void		rotate(t_push_swap *ptr);
void		r_rotate(t_push_swap *ptr);
void		rr(t_push_swap *ptr_a, t_push_swap *ptr_b);
void		rrr(t_push_swap *ptr_a, t_push_swap *ptr_b);
//	sort.c
int			sort_3(t_push_swap *ptr);
void		bubblesort(const int *tab, const int size);
//	median.c
void		do_median(t_push_swap *ptr_a, t_push_swap *ptr_b, int *array_args);
//	count_move.c
void		best_move(t_push_swap *ptr_a, t_push_swap *ptr_b);
void		exec_move(t_push_swap *ptr_a, t_push_swap *ptr_b, \
						t_bestmove bestmove);
//	choice.c
void		best(t_bestmove *bestmove);
void		set_choice_rr(t_bestmove *bestmove);
void		set_choice_rrr(t_bestmove *bestmove);
//	find.c
int			find_max(const t_push_swap ptr);
int			find_min(const t_push_swap ptr);
int			find_index_from_pile(const int value, t_push_swap *ptr);
void		find_pair_from_pile(const int value, t_push_swap *ptr, \
								t_bestmove *bestmove);
t_bestmove	find_min_from_struct(t_bestmove *bestmove, int size);
//	utils.c
int			check_doublon(const int *tab, const int size);
int			*arraynpiledup(t_push_swap *ptr, const int *tab, const int size);
//	print.c
void		print_stack(t_stack *stack);
void		print_pile(t_pile *pile);
void		print_struct(t_bestmove bestmove);
void		print_all_struct(t_bestmove *bestmove, const int size);
void		print_tab(const int *tab, const int size);
//	free.c
void		free_pile(t_push_swap ptr);
void		exit_free_all(t_push_swap ptr_a, t_push_swap ptr_b, void *ptr);
//	main.c

//	bonus/*.c
int			exec_cmd(const char *actions, \
				t_push_swap *ptr_a, t_push_swap *ptr_b);

#endif
