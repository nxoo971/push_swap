/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:47:48 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/09 17:19:28 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	s(t_push_swap *ptr)
{
	if (ptr->pile && ptr->pile->prev)
		ft_swap(& ptr->pile->data, & ptr->pile->prev->data, sizeof(int));
}

void	ss(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (ptr_a->pile && ptr_a->pile->prev && ptr_b->pile && ptr_b->pile->prev)
	{
		ft_swap(& ptr_a->pile->data, & ptr_a->pile->prev->data, sizeof(int));
		ft_swap(& ptr_b->pile->data, & ptr_b->pile->prev->data, sizeof(int));
	}
}
