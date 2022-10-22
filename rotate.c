/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:45:37 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/23 00:28:46 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_last(t_stack *s)
{
	if (!s || !s->prev)
		return (s);
	while (s->prev)
		s = s->prev;
	return (s);
}

void	rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *s;
	if (!tmp || !tmp->prev)
		return ;
	*s = (*s)->prev;
	(*s)->next = 0;
	last = stack_last(tmp);
	tmp->prev = 0;
	tmp->next = last;
	last->prev = tmp;
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	r_rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *s;
	if (!tmp || !tmp->prev)
		return ;
	last = stack_last(tmp);
	last->next->prev = 0;
	last->next = 0;
	last->prev = tmp;
	tmp->next = last;
}

void	rrr(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
}