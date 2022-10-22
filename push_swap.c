/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:15:20 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/22 03:19:27 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* equiv. to sa/sb */
void    swap(const t_stack *s)
{
    if (!s || !s->prev)
        return ;
    ft_swap((void *)&s->data, &s->prev->data, sizeof(int));
}

void    swap_both(const t_stack *a, const t_stack *b)
{
    swap(a);
	swap(b);
}

/* equiv. to pa/pb */
void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	if (!*a)
	{
		*a = *b;
		if ((*b)->prev)
		{
			*b = (*b)->prev;
			(*b)->next = 0;
		}
		(*a)->next = 0;
		(*a)->prev = 0;
		return ;
	}
	tmp = *a;
	tmp->next = *b;
	if ((*b)->prev)
	{
		*b = (*b)->prev;
		(*b)->next = 0;
	}
	tmp->next->prev = *a;
	*a = (*a)->next;
}
