/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 05:53:25 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/09 07:49:48 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static \
void	free_stack(t_stack *stack)
{
	ft_memdel((void **)& stack);
}

void	free_pile(t_push_swap ptr)
{
	t_pile	*tmp;

	tmp = ptr.stack->first;
	while (ptr.pile)
	{
		tmp = ptr.pile;
		ptr.pile = ptr.pile->prev;
		ft_memdel((void **)& tmp);
	}
}

void	exit_free_all(t_push_swap ptr_a, t_push_swap ptr_b, void *ptr)
{
	if (ptr_a.pile)
		free_pile(ptr_a);
	if (ptr_a.stack)
		free_stack(ptr_a.stack);
	if (ptr_b.pile)
		free_pile(ptr_b);
	if (ptr_b.stack)
		free_stack(ptr_b.stack);
	if (ptr)
		ft_memdel((void **)& ptr);
	exit(0);
}
