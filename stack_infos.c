/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:04:36 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/26 21:06:26 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(const t_stack *stack)
{
	if (!stack)
		return ;
	ft_printf(	"data:	%d\n"
				"act:	%p\n"
				"prev:	%p\n"
				"next:	%p\n", stack->data, stack, stack->prev, stack->next);
	ft_printf("\t-----------------------\n");
}

void	print_pile(const t_pile *pile)
{
	if (!pile)
		return ;
	ft_printf(	"len:	%d\n"
				"first:	%p\n"
				"last:	%p\n", pile->length, pile->first, pile->last);
	ft_printf("\t-----------------------\n");
}

void	print_all_stack(const t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		print_stack(stack);
		stack = stack->prev;
	}
}
