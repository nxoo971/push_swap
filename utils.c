/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:42:42 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/08 17:43:13 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doublon(const int *tab, const int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tab[i] == tab[j])
				return (0);
		}
	}
	return (1);
}

int	*arraynpiledup(t_push_swap *ptr, const int *tab, const int size)
{
	int	*res;
	int	i;

	res = malloc(sizeof(int) * size);
	i = -1;
	if (!res)
		return (0);
	while (++i < size)
	{
		res[i] = tab[i];
		add_elem(ptr, tab[i]);
	}
	return (res);
}
