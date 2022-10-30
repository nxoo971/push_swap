/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:30:22 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 23:56:14 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX_ACTION	'r' + 'r' + 'a' + 1

int	is_smaller_than_max_action(const char *s, int max)
{
	int	res;

	res = 0;
	while (--max >= 0 && *s)
		res += *s++;
	return (res <= MAX_ACTION);
}

void	exec_args(const char *actions, t_push_swap *ptr)
{
	const char					*tmp;
	t_swapaction				tmpaction;
	static const t_swapaction	swapactions[MAX_ACTION] = {
	['s' + 'a'] = & swap,
	['r' + 'a'] = & rotate,
	['r' + 'r' + 'a'] = & r_rotate,
	};

	tmpaction = 0;
	tmp = ft_strchr(actions, 'a');
	while (tmp && actions[+1] != '\0')
	{
		if (tmp - actions + 1 == 3)
		{
			if (is_smaller_than_max_action(actions, 3))
				tmpaction = swapactions[*actions + actions[+1] + actions[+2]];
		}
		if (tmp - actions + 1 == 2)
		{
			if (is_smaller_than_max_action(actions, 2))
				tmpaction = swapactions[*actions + actions[+1]];
		}
		if (tmpaction)
		{
			ft_putnendl(actions, tmp - actions + 1);
			tmpaction(ptr);
			tmpaction = 0;
		}
		actions = tmp + 1;
		tmp = ft_strchr(actions, 'a');
	}
}
