/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:30:22 by nxoo              #+#    #+#             */
/*   Updated: 2022/11/02 17:54:19 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX_ACTION	'r' + 'r' + 'a' + 1

static \
int	sum(const char *s, int len)
{
	int	res;

	res = 0;
	while (*s && len-- > 0)
		res += *s++;
	return (res);
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
		if (sum(actions, tmp - actions + 1) <= MAX_ACTION)
			tmpaction = swapactions[sum(actions, tmp - actions + 1)];
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
