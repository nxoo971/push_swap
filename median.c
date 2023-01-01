/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 04:07:15 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/08 17:37:10 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static \
int	get_median(t_push_swap ptr_a, t_push_swap ptr_b, int *array_args)
{
	t_pile	*a;
	int		*res;
	int		tmpmedian;
	int		i;

	i = 0;
	a = ptr_a.pile;
	res = malloc(sizeof(int) * ptr_a.stack->size);
	if (!res)
		exit_free_all(ptr_a, ptr_b, array_args);
	while (a)
	{
		res[i] = a->data;
		a = a->prev;
		i++;
	}
	bubblesort(res, ptr_a.stack->size);
	tmpmedian = res[(33 * (ptr_a.stack->size) / 100)];
	free(res);
	return (tmpmedian);
}

void	do_median(t_push_swap *ptr_a, t_push_swap *ptr_b, int *array_args)
{
	int	median;

	median = array_args[(33 * (ptr_a->stack->size) / 100)];
	while (ptr_a->stack->size > 3)
	{
		if (ptr_a->pile->data > median)
		{
			rotate(ptr_a);
			ft_printf("ra\n");
		}
		else
		{
			push(ptr_b, ptr_a);
			ft_printf("pb\n");
			median = get_median(*ptr_a, *ptr_b, array_args);
		}
	}
}
