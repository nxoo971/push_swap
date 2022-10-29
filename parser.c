/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:50:05 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 01:37:36 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_av(int ac, char **av)
{
	char	*start;
	int		*res;
	int		index;

	if (!av || !*av)
		return (0);
	if (!(res = malloc(sizeof(int) * ac)))
		return (0);
	index = 0;
	while (*++av)
	{
		start = *av;
		while (*start)
		{
			if (!ft_isdigit(*start))
			{
				delmem((void **)&res);
				return (0);
			}
			start++;
		}
		res[index++] = ft_atoi(*av);
	}
	return (res);
}
