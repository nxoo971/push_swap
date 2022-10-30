/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:54:55 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 03:02:26 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	memdel(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}

void	stackdel(t_stack **s)
{
	t_stack	*tmp;

	while (*s)
	{
		tmp = *s;
		*s = (*s)->prev;
		memdel((void **)&tmp);
	}
	*s = 0;
}

void	piledel(t_pile **p)
{
	memdel((void **)p);
}
