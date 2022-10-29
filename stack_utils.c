/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:37:43 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/27 18:14:08 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(t_pile **pile, int data)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		pile_update(pile, new, new);
		if (*pile)
		{
			(*pile)->length++;
			new->data = data;
			new->next = 0;
			new->prev = 0;
			return (new);
		}
	}
	return (0);
}

void	stack_add(t_pile **pile, t_stack **stack, int data)
{
	t_stack	*ptr_last;
	t_stack	*last;

	if (!*stack)
		*stack = stack_new(pile, data);
	else
	{
		ptr_last = (*pile)->last;

		last = stack_new(pile, data);
		last->next = ptr_last;
		ptr_last->prev = last;
		pile_update(pile, *stack, last);
	}
}
