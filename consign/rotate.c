/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:47:58 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/08 18:29:52 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	rotate(t_push_swap *ptr)
{
	t_pile	*first;
	t_pile	*last;

	if (!ptr->pile || !ptr->pile->prev)
		return ;
	first = ptr->stack->first;
	last = ptr->stack->last;
	ptr->pile = ptr->pile->prev;
	ptr->pile->next = 0;
	first->prev = 0;
	first->next = last;
	last->prev = first;
	update(& ptr->stack, ptr->pile, first);
}

void	r_rotate(t_push_swap *ptr)
{
	t_pile	*first;
	t_pile	*last;
	t_pile	*save;

	if (!ptr->pile || !ptr->pile->prev)
		return ;
	first = ptr->stack->first;
	last = ptr->stack->last;
	last->next->prev = 0;
	last->prev = first;
	save = last->next;
	last->next = 0;
	first->next = last;
	ptr->pile = last;
	update(& ptr->stack, last, save);
}

void	rr(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (ptr_a->stack->size >= 2 && ptr_b->stack->size >= 2)
	{
		rotate(ptr_a);
		rotate(ptr_b);
		ft_printf("rr\n");
	}
}

void	rrr(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (ptr_a->stack->size >= 2 && ptr_b->stack->size >= 2)
	{
		r_rotate(ptr_a);
		r_rotate(ptr_b);
		ft_printf("rrr\n");
	}
}
