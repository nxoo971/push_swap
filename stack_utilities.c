/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:15:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/21 05:40:20 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int data)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		stack->prev = 0;
		stack->next = 0;
		stack->data = data;
	}
	return (stack);
}

void	stack_add(t_stack **tstack, int data)
{
	t_stack	*new;
	t_stack	*stack;

	if (!(new = stack_new(data)))
		return ;
	if (!*tstack)
	{
		*tstack = new;
		return ;
	}
	stack = *tstack;
	while (stack->prev)
		stack = stack->prev;
	stack->prev = new;
	new->next = stack;
}
