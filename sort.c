/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:58:21 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/08 20:30:29 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX_SIZE	'r' + 'r' + 'a' + 1

static \
int	sum(const char *actions)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (actions[i])
	{
		if (actions[i] != 's' && actions[i] != 'a' \
			&& actions[i] != 'r')
			return (-1);
		sum += actions[i];
		if (actions[i] == 'a')
			break ;
		i++;
	}
	return (sum);
}

//static
int	exec_actions(const char *actions, t_push_swap *ptr)
{
	static const t_move	move[MAX_SIZE] = {
	['s' + 'a'] = & s,
	['r' + 'a'] = & rotate,
	['r' + 'r' + 'a'] = & r_rotate,
	};
	const char			*tmp;
	int					index;

	while (actions)
	{
		tmp = ft_strchr(actions, 'a');
		if (!tmp)
			break ;
		index = sum(actions);
		if (index >= MAX_SIZE || index == -1)
			return (-1);
		move[index](ptr);
		ft_putnendl(actions, tmp - actions + 1);
		actions = tmp + 1;
	}
	return (0);
}

int	sort_3(t_push_swap *ptr)
{
	t_pile	*pile;
	int		a;
	int		b;
	int		c;

	pile = ptr->stack->first;
	if (ptr->stack->size != 3)
		return (-1);
	a = pile->data;
	b = pile->prev->data;
	c = pile->prev->prev->data;
	if (b > a && c > b)
		return (0);
	if (a < b && b > c && c > a)
		return (exec_actions("rrasa", ptr));
	if (a > b && b < c && c > a)
		return (exec_actions("sa", ptr));
	if (a < b && b > c && c < a)
		return (exec_actions("rra", ptr));
	if (a > b && b < c && c < a)
		return (exec_actions("ra", ptr));
	return (exec_actions("sarra", ptr));
}

void	bubblesort(const int *tab, const int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tab[i] > tab[j])
				ft_swap((void *)& tab[i], (void *)& tab[j], sizeof(int));
		}
	}
}
