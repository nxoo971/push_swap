/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:17:28 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/09 08:16:08 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*create_elem(int data, t_stack **stack)
{
	t_pile	*pile;

	pile = malloc(sizeof(t_pile));
	if (!pile)
		return (0);
	pile->data = data;
	pile->prev = 0;
	pile->next = 0;
	update(stack, 0, 0);
	(*stack)->size++;
	return (pile);
}

void	update(t_stack **stack, t_pile *first, t_pile *last)
{
	if (!*stack)
	{
		*stack = malloc(sizeof(t_stack));
		if (!*stack)
			return ;
		(*stack)->size = 0;
		(*stack)->first = first;
		(*stack)->last = last;
		return ;
	}
	if (first)
		(*stack)->first = first;
	if (last)
		(*stack)->last = last;
}

void	add_elem(t_push_swap *ptr, int data)
{
	t_pile	*tmp;

	if (!ptr->pile)
	{
		ptr->pile = create_elem(data, & ptr->stack);
		return ;
	}
	tmp = ptr->stack->last;
	if (!tmp)
		tmp = ptr->pile;
	tmp->prev = create_elem(data, & ptr->stack);
	if (!tmp->prev)
		return ;
	tmp->prev->next = tmp;
	update(& ptr->stack, ptr->pile, tmp->prev);
}

int	pile_is_sorted(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	if (!tmp)
		return (0);
	while (tmp->prev)
	{
		if (tmp->data > tmp->prev->data)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}
