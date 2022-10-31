/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:42:19 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/31 01:49:33 by nxoo             ###   ########.fr       */
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

int		start_toporbottom(t_pile *tosearch, t_pile *tofind)
{
	t_stack	*stack;
	int	index;
	int	data;

	index = 0;
	data = tofind->first->data;
	stack = tosearch->first;
	while (stack)
	{
		if (stack->data == data)
			break ;
		stack = stack->prev;
		index++;
	}
	return (tosearch->length / 2 > index);
}

int		exec_ra_rra(t_push_swap *a, t_push_swap *b, void (f)(t_push_swap *))
{
	int	rotated;

	rotated = 0;
	while (b->pile->first->data > a->pile->first->data)
	{
		f(a);
		rotated++;
	}
	return (rotated);
}

int		is_minimum(int data, t_stack *stack)
{
	while (stack)
	{
		if (stack->data < data)
			return (0);
		stack = stack->prev;
	}
	return (1);
}

void	sort(t_push_swap *a, t_push_swap *b)
{
	int	rotated;
	int	already; // to avoid starting is_minimum function and his search in the entire Pile B ..

	while (a->pile->length > 3)
		push(b, a);
	sort_3(a);
	already = 0;
	while (b->pile->first)
	{
		if (b->pile->first->data > a->pile->last->data)
		{
			push(a, b);
			rotate(a);
		}// tous les autres "cas" ici
		else
		{
			if (!already && is_minimum(b->pile->first->data, b->pile->first->prev) && b->pile->first->data > a->pile->first->data)
			{
				already++;
				push(a, b);
				swap(a);
			}
			else
			{
				if (!start_toporbottom(a->pile, b->pile))
					rotated = exec_ra_rra(a, b, & rotate);
				else
					rotated = exec_ra_rra(a, b, & r_rotate);

				push(a, b);
				while (--rotated >= 0)
					r_rotate(a);
			}
			
		}
	}
}
