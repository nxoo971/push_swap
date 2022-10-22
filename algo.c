/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:20:20 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/22 04:49:18 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	2 1 3 6 5 8
	sa =
	1 2 3 6 5 8
	pb pb pb =
	A = 6 5 8
	b = 3 2 1

*/

static \
void	check_swap(t_stack **a, int is_a)
{
	t_stack *start;

	start = *a;
	if (!start->prev)
		return ;
	if (start->data > start->prev->data || start->prev->data < start->data) {
		swap(start);
		ft_printf("%s\n", is_a ? "sa" : "sb");
	}
}

void	transfert(t_stack **a, t_stack **b, const int data)
{
	t_stack	*tmp;

	while ((*a)->prev && (*a)->data != data)
	{
		tmp = *a;
		*a = (*a)->prev;
		push(b, &tmp);
		ft_printf("pb\n");
	}
}

int		is_bigger(int a, int b)
{
	return (a > b);
}

int		is_smaller(int a, int b)
{
	return (a < b);
}

int		is_sorted(t_stack *a, int (*f)(int, int))
{
	while (a->prev)
	{
		if (f(a->data, a->prev->data))
			return (0);
		a = a->prev;
	}
	return (1);
}

void	push_all(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp->prev)
	{
		push(a, b);
		ft_printf("pa\n");
		tmp = tmp->prev;
	}
}

void	algo(t_stack **a, t_stack **b)
{
	t_stack *start;

	start = *a;
	if (!start->prev)
		return ;

/* * Check first element */
	check_swap(a, 1);
/* ********************* */

	while ((*a)->prev)
	{
		if ((*a)->data > (*a)->prev->data)
			transfert(&start, b, (*a)->data);
		check_swap(a, 1);
		if (is_sorted(*a, &is_bigger) && is_sorted(*b, &is_smaller))
		{
			push_all(a, b);
			return ;
		}
		if (*b && (*b)->prev)
			check_swap(b, 0);
		*a = (*a)->prev;
		if (!*a)
			*a = start;
	}
	*a = start;
}
