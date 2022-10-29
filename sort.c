/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:30:22 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/27 19:01:04 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1	1	2	2	3	3
// 2	3	1	3	1	2
// 3	2	3	1	2	1

void	exec_push(const char specifier, t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (specifier == 'a')
		push(ptr_a, ptr_b);
	if (specifier == 'b')
		push(ptr_b, ptr_a);
}

void	exec_swap(const char specifier, t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (specifier == 'a')
		swap(ptr_a->stack);
	if (specifier == 'b')
		swap(ptr_b->stack);
}

void	exec_rotate(const char specifier, t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (specifier == 'a')
		rotate(ptr_a);
	if (specifier == 'b')
		rotate(ptr_b);
}

void	exec_r_rotate(const char specifier, t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (specifier == 'a')
		r_rotate(ptr_a);
	if (specifier == 'b')
		r_rotate(ptr_b);
}

void	exec_args(const char *actions, t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	while (*actions)
	{
		if (*actions == 'p')
			exec_push(*++actions, ptr_a, ptr_b);
		if (*actions == 's')
			exec_swap(*++actions, ptr_a, ptr_b);
		if (*actions == 'r') {
			if (*++actions == 'r')
				exec_r_rotate(*++actions, ptr_a, ptr_b);
			else
				exec_rotate(*actions, ptr_a, ptr_b);
		}
		actions++;
	}
}

// 1	1	2	2	3	3
// 2	3	1	3	1	2
// 3	2	3	1	2	1

void	sort_3(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	t_pile	*pile;
	t_stack	*stack;
	int		a;
	int		b;
	int		c;

	pile = ptr_a->pile;
	stack = ptr_a->stack;
	a = pile->first->data;
	b = pile->first->prev->data;
	c = pile->last->data;
	if (a < b && a < c)
	{
		if (b < c)
			return ;
		exec_args("rrasa", ptr_a, ptr_b);
	}
	else if (a > b && a > c)
	{
		if (b < c)
			exec_args("ra", ptr_a, ptr_b);
		else
			exec_args("sarra", ptr_a, ptr_b);
	}
	else
	{
		if (a > c)
			exec_args("rra", ptr_a, ptr_b);
		else
			exec_args("sa", ptr_a, ptr_b);
	}
}

int		getmin(t_stack *s)
{
	int	min;

	min = s->data;
	s = s->prev;
	while (s)
	{
		if (s->data < min)
			min = s->data;
		s = s->prev;
	}
	return (min);
}

void	sort(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	t_pile	*pile;
	t_stack	*stack;
	int		len;

	pile = ptr_a->pile;
	stack = ptr_a->stack;
	len = pile->length;

	int min = getmin(ptr_a->stack);
	while (len > 3)
	{
		push(ptr_b, ptr_a);
		len--;
	}
	sort_3(ptr_a, ptr_b);
}
