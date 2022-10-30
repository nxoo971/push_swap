/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:42:19 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 02:54:04 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static \
void	sub_exec_args_according_to_abc(t_push_swap *ptr, int a, int b, int c)
{
	if (a < b && a < c && b > c)
		exec_args("rrasa", ptr);
	else if (a > b && a > c)
	{
		if (b < c)
			exec_args("ra", ptr);
		else
			exec_args("sarra", ptr);
	}
	else
	{
		if (a > c)
			exec_args("rra", ptr);
		else
			exec_args("sa", ptr);
	}
}

void	sort_3(t_push_swap *ptr)
{
	t_pile	*pile;
	t_stack	*stack;
	int		a;
	int		b;
	int		c;

	pile = ptr->pile;
	stack = ptr->stack;
	a = pile->first->data;
	b = pile->first->prev->data;
	c = pile->last->data;
	if (a < b && a < c && b < c)
		return ;
	sub_exec_args_according_to_abc(ptr, a, b, c);
}

void	sort(t_push_swap *a, t_push_swap *b)
{
	int	rotated;

	while (a->pile->length > 3)
		push(b, a);
	sort_3(a);
	while (b->pile->first)
	{
		if (b->pile->first->data > a->pile->last->data)
		{
			push(a, b);
			rotate(a);
		}
		else
		{
			rotated = 0;
			while (b->pile->first->data > a->pile->first->data)
			{
				rotate(a);
				rotated++;
			}
			push(a, b);
			while (--rotated >= 0)
				r_rotate(a);
		}
	}
}
