/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delmem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:54:55 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 01:37:05 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delmem(void **ptr)
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
		delmem((void **)&tmp);
	}
	*s = 0;
}

void	piledel(t_pile **p)
{
	delmem((void **)p);
}