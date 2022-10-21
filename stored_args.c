/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stored_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:13:16 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/21 04:09:54 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static \
int	check_doublon(const int *datas, const int search, const int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		if (datas[i] == search)
			return (0);
		i++;
	}
	return (1);
}

int	*check_args(int ac, const char **av)
{
	const char	*start;
	int			*datas;
	int			i;
	int			tmp;

	i = 0;
	datas = malloc(sizeof(int) * ac);
	av++;
	while (*av)
	{
		start = *av;
		while (**av)
		{
			if (!ft_isdigit(**av) && **av != '-' && **av != '+')
			{
				free(datas);
				return (NULL);
			}
			(*av)++;
		}
		tmp = ft_atoi(start);
		if (check_doublon(datas, tmp, i))
			datas[i++] = tmp;
		else
		{
			free(datas);
			return (NULL);
		}
		av++;
	}
	return (datas);
}

t_stack	*write_args_in_stack(const int *datas, const int length)
{
	t_stack	*stack;
	int	i;

	i = -1;
	stack = NULL;
	while (++i < length)
		stack_add(&stack, datas[i]);
	free((void *)datas);
	return (stack);
}
