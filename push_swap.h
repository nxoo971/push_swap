/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:43:44 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 02:08:23 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct	s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
}	t_stack;

typedef	struct	s_pile
{
	t_stack	*first;
	t_stack	*last;
	int		length;
}	t_pile;

typedef struct	s_push_swap
{
	t_stack	*stack;
	t_pile	*pile;
}	t_push_swap;

typedef void	(*t_swapaction)(t_push_swap *);

//	pile_utils.c
void		pile_update(t_pile **pile, t_stack *first, t_stack *last);
// stack_utils.c
t_stack		*stack_new(t_pile **pile, int data);
void		stack_add(t_pile **pile, t_stack **stack, int data);
//	parser.c
int			*parse_av(int ac, char **av);
t_stack		*write_args_in_stack(t_pile **pile, int *datas, int len);
//	print_infos.c
void		print_stack(const t_stack *stack);
void		print_pile(const t_pile *pile);
void		print_all_stack(const t_stack *stack);
//	actions.c
void		swap(t_push_swap *src);
void		push(t_push_swap *dst, t_push_swap *src);
void		rotate(t_push_swap *a);
void		r_rotate(t_push_swap *a);
//	exec_args.c
void		exec_args(const char *actions, t_push_swap *ptr);
//	sort.c
void		sort(t_push_swap *ptr_a, t_push_swap *ptr_b);
//	memdel.c
void		memdel(void **ptr);
void		stackdel(t_stack **s);
void		piledel(t_pile **p);

#endif
