/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:47:45 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/08 17:10:37 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

static \
void	update_size(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (ptr_b->stack->size != 0)
		ptr_b->stack->size--;
	if (!ptr_b->stack->size)
	{
		ptr_b->stack->first = 0;
		ptr_b->stack->last = 0;
		ptr_b->pile = 0;
	}
	ptr_a->stack->size++;
}

static \
void	is_empty(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	t_pile	*to_add;

	to_add = ptr_b->pile;
	if (ptr_b->pile->prev)
		ptr_b->pile = ptr_b->pile->prev;
	ptr_b->pile->next = 0;
	to_add->prev = 0;
	to_add->next = 0;
	ptr_a->pile = to_add;
	update(& ptr_b->stack, ptr_b->pile, ptr_b->stack->last);
	update(& ptr_a->stack, ptr_a->pile, 0);
	update_size(ptr_a, ptr_b);
}

void	push(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	t_pile	*to_add;

	if (!ptr_b->pile)
		return ;
	if (!ptr_a->pile)
	{
		is_empty(ptr_a, ptr_b);
		return ;
	}
	to_add = ptr_b->pile;
	to_add->next = 0;
	if (ptr_b->pile->prev)
	{
		ptr_b->pile = to_add->prev;
		ptr_b->pile->next = 0;
	}
	to_add->prev = ptr_a->pile;
	to_add->prev->next = to_add;
	ptr_a->pile = to_add;
	update(& ptr_b->stack, ptr_b->pile, ptr_b->stack->last);
	if (!ptr_a->stack->last)
		update(& ptr_a->stack, to_add, to_add->prev);
	else
		update(& ptr_a->stack, to_add, 0);
	update_size(ptr_a, ptr_b);
}
