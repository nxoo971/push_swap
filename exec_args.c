/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:30:22 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 00:46:18 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static \
void	exec_push(const char specifier, t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (specifier == 'a')
		push(ptr_a, ptr_b);
	if (specifier == 'b')
		push(ptr_b, ptr_a);
}

static \
void	exec_swap(const char specifier, t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (specifier == 'a')
		swap(ptr_a->stack);
	if (specifier == 'b')
		swap(ptr_b->stack);
}

static \
void	exec_rotate(const char specifier, t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (specifier == 'a')
		rotate(ptr_a);
	if (specifier == 'b')
		rotate(ptr_b);
}

static \
void	exec_r_rotate(const char specifier, t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (specifier == 'a')
		r_rotate(ptr_a);
	if (specifier == 'b')
		r_rotate(ptr_b);
}

void	exec_args(const char *actions, t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	while (*actions)
	{
		if (*actions == 'p')
			exec_push(*++actions, ptr_a, ptr_b);
		if (*actions == 's')
			exec_swap(*++actions, ptr_a, ptr_b);
		if (*actions == 'r') {
			if (*++actions == 'r')
				exec_r_rotate(*++actions, ptr_a, ptr_b);
			else
				exec_rotate(*actions, ptr_a, ptr_b);
		}
		actions++;
	}
}

