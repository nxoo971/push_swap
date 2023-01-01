/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 05:19:48 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/07 08:02:19 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(const t_push_swap ptr)
{
	t_pile	*pile;
	int		max;

	pile = ptr.pile;
	max = pile->data;
	pile = pile->prev;
	while (pile)
	{
		if (pile->data > max)
			max = pile->data;
		pile = pile->prev;
	}
	return (max);
}

int	find_min(const t_push_swap ptr)
{
	t_pile	*pile;
	int		min;

	pile = ptr.pile;
	min = pile->data;
	pile = pile->prev;
	while (pile)
	{
		if (pile->data < min)
			min = pile->data;
		pile = pile->prev;
	}
	return (min);
}

int	find_index_from_pile(const int value, t_push_swap *ptr)
{
	int		index;
	t_pile	*pile;

	index = 0;
	pile = ptr->pile;
	while (pile)
	{
		if (value == pile->data)
			break ;
		pile = pile->prev;
		index++;
	}	
	return (index);
}

void	find_pair_from_pile(const int value, t_push_swap *ptr, \
								t_bestmove *bestmove)
{
	int		old;
	t_pile	*a;

	a = ptr->pile;
	old = find_max(*ptr);
	while (a)
	{
		if (a->data > value && a->data < old)
			old = a->data;
		a = a->prev;
	}
	if (value > old)
		bestmove -> ra = find_index_from_pile(find_min(*ptr), ptr);
	else
		bestmove -> ra = find_index_from_pile(old, ptr);
}

t_bestmove	find_min_from_struct(t_bestmove *bestmove, int size)
{
	int	i;
	int	min;
	int	minindex;

	min = bestmove[0].maxmove;
	minindex = 0;
	i = -1;
	while (++i < size)
	{
		if (bestmove[i].maxmove < min)
		{
			minindex = i;
			min = bestmove[i].maxmove;
		}
	}
	return (bestmove[minindex]);
}
