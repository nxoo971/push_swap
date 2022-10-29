/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:42:19 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 00:51:57 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static \
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

void	sort(t_push_swap *a, t_push_swap *b)
{
	if (a->pile->length <= 3)
	{
		if (a->pile->length == 2) {
			if (a->pile->first->data > a->pile->last->data)
				swap(a->stack);
		}
		else if (a->pile->length == 3)
			sort_3(a, b);
		return ;
	}
	
// tout push de l'autre côter sauf 3
	while (a->pile->length > 3)
		push(b, a);
// les triés
	sort_3(a, 0);

// tant qu'il y a des elems dans ma pile alors ->
	while (b->pile->length)
	{
		t_stack	*first = b->pile->first;
			// s'il est supérieur au premier de la stack A alors ->
		if (first->data > a->pile->last->data)
		{
			/*
				il est supérieur au dernier de la liste, alors on le push dans A et on le rotate
				afin de le placer en fin de liste
			*/
			push(a, b);
			rotate(a);
		}
		else
		{
			int	rotated = 0;

			while (first->data > a->pile->first->data)
			{
				rotate(a);
				rotated++;
			}
			/* on le place maintenant */
			push(a, b);
			/* on remet en place les rotateds */
			while (--rotated >= 0)
				r_rotate(a);
		}
	}
}