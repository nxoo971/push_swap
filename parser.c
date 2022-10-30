/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:50:05 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 03:03:01 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*write_args_in_stack(t_pile **pile, int *datas, int len)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = 0;
	while (i < len)
	{
		stack_add(pile, &stack, datas[i]);
		i++;
	}
	return (stack);
}

int	*parse_av(int ac, char **av)
{
	char	*start;
	int		*res;
	int		index;

	if (!av || !*av)
		return (0);
	res = malloc(sizeof(int) * ac);
	if (!res)
		return (0);
	index = 0;
	while (*++av)
	{
		start = *av;
		while (*start)
		{
			if (!ft_isdigit(*start))
			{
				memdel((void **)&res);
				return (0);
			}
			start++;
		}
		res[index++] = ft_atoi(*av);
	}
	return (res);
}
