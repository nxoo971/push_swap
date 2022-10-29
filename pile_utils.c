/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:48:43 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/26 22:03:10 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pile_update(t_pile **pile, t_stack *first, t_stack *last)
{
	t_pile	*tmp;

	if (!first || !last)
		return ;
	if (!*pile) {
		*pile = malloc(sizeof(t_pile));
		(*pile)->length = 0;
	}
	tmp = *pile;
	tmp->first = first;
	tmp->last = last;
}
