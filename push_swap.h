/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:12:16 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/22 02:34:26 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

typedef struct	s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
}	t_stack;

typedef struct	s_pile
{
	t_stack	*a;
	t_stack	*b;
}	t_pile;

// stored_args.c
t_stack		*write_args_in_stack(const int *datas, const int length);
int			*check_args(int ac, const char **av);
//stack_utilities.c
t_stack		*stack_new(int data);
void		stack_add(t_stack **tstack, int data);
// stack_infos.c
void		print_stack(const t_stack *stack);
void		print_all_stack(const t_stack *stack);
// operators
				// sa | sb
void    	swap(const t_stack *s);
				// ss
void		swap_both(const t_stack *a, const t_stack *b);
				// pa | pb
void		push(t_stack **a, t_stack **b);
// rotate.c
void		rotate(t_stack **s);
void		rr(t_stack **a, t_stack **b);
void		r_rotate(t_stack **s);
void		rrr(t_stack **a, t_stack **b);
// algo.c
void		algo(t_stack **a, t_stack **b);

#endif
