/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:15:11 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/21 22:24:51 by nxoo             ###   ########.fr       */
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
