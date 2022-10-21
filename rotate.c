/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:45:37 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/22 00:44:37 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **s)
{
	t_stack	*tmp;

	tmp = *s;
	if (tmp)
	{
		while (tmp->prev)
		{
			ft_swap((void *)&tmp->data, &tmp->prev->data, sizeof(int));
			tmp = tmp->prev;
		}
	}
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	r_rotate(t_stack **s)
{
	t_stack	*tmp;

	tmp = *s;
	if (tmp)
	{
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp->next)
		{
			ft_swap((void *)&tmp->data, &tmp->next->data, sizeof(int));
			tmp = tmp->next;
		}
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
}