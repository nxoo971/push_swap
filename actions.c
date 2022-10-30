/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:12:23 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 02:45:27 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_push_swap *src)
{
	if (src->stack && src->stack->prev)
		ft_swap((void *)&src->stack->data, &src->stack->prev->data, sizeof(int));
}

void	push(t_push_swap *dst, t_push_swap *src)
{
	t_stack	*pdst;
	t_stack	*psrc;
	t_stack	*tmp;

	if (!src->pile || !src->stack)
		return ;
	if (!dst->pile)
	{
		*dst = *src;
		tmp = src->pile->first;
		if (src->pile->first->prev)
		{
			src->pile->first = src->pile->first->prev;
			src->pile->first->next = 0;
			src->stack = src->pile->first;
		}
		tmp->next = 0;
		tmp->prev = 0;
		dst->stack = tmp;
		dst->pile = malloc(sizeof(t_pile));
		dst->pile->last = dst->pile->first = dst->stack;
		dst->pile->length = 1;
		src->pile->length--;
		return ;
	}
	pdst = dst->pile->first;
	psrc = src->pile->first;
	if (psrc->prev)
	{
		src->pile->first = src->pile->first->prev;
		src->pile->first->next = 0;
		src->stack = src->pile->first;
	}
	pdst->next = psrc;
	psrc->prev = pdst;
	pdst = pdst->next;
	dst->stack = pdst;
	dst->pile->first = pdst;
	dst->pile->length++;
	src->pile->length--;
	if (src->pile->length <= 0) {
		src->pile->first = src->pile->last = 0;
		src->stack = 0;
	}
}

void	rotate(t_push_swap *a)
{
	t_pile	*pile;
	t_stack	*stack;

	pile = a->pile;
	stack = a->stack;
	if (!stack->prev)
		return ;
	a->stack = a->stack->prev;
	a->stack->next = 0;
	pile->last->prev = stack;
	stack->next = pile->last;
	stack->prev = 0;
	pile_update(&pile, a->stack, stack);
}

void	r_rotate(t_push_swap *a)
{
	t_pile	*pile;
	t_stack	*stack;
	t_stack	*stack_last;

	pile = a->pile;
	stack = a->stack;
	if (!stack->prev)
		return ;
	stack_last = pile->last;
	pile->last = pile->last->next;
	pile->last->prev = 0;
	stack_last->next = 0;
	stack_last->prev = a->stack;
	a->stack->next = stack_last;
	a->stack = a->stack->next;
	pile->first = stack_last;
}
