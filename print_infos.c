/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:04:36 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 03:21:06 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_printf("%d, ", tab[i++]);
	ft_printf("\n");
}

void	print_stack(const t_stack *stack)
{
	if (!stack)
		return ;
	ft_printf("data:	%d\n", stack->data);
	ft_printf("act:	%p\n", stack);
	ft_printf("prev:	%p\n", stack->prev);
	ft_printf("next:	%p\n", stack->next);
	ft_printf("\t-----------------------\n");
}

void	print_pile(const t_pile *pile)
{
	if (!pile)
		return ;
	ft_printf("len:	%d\n", pile->length);
	ft_printf("first:	%p\n", pile->first);
	ft_printf("last:	%p\n", pile->last);
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
