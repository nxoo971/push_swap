/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:17:44 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/08 17:18:15 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best(t_bestmove *bestmove)
{
	if (bestmove -> maxmove == bestmove -> is_ra_rb)
	{
		bestmove -> isrra = -1;
		bestmove -> isrrb = -1;
	}
	else if (bestmove -> maxmove == bestmove -> isrra_rrb)
	{
		bestmove -> ra = -1;
		bestmove -> rb = -1;
	}
	else if (bestmove -> maxmove == bestmove -> isrra_rb)
	{
		bestmove -> ra = -1;
		bestmove -> isrrb = -1;
	}
	else
	{
		bestmove -> rb = -1;
		bestmove -> isrra = -1;
	}
}

void	set_choice_rrr(t_bestmove *bestmove)
{
	if (bestmove -> isrra > 0 && bestmove -> isrrb > 0)
	{
		if (bestmove -> isrra > bestmove -> isrrb)
		{
			bestmove -> isrrr = bestmove -> isrrb;
			bestmove -> isrra -= bestmove -> isrrb;
			bestmove -> isrrb = -1;
		}
		else if (bestmove -> isrra < bestmove -> isrrb)
		{
			bestmove -> isrrr = bestmove -> isrra;
			bestmove -> isrrb -= bestmove -> isrra;
			bestmove -> isrra = -1;
		}
		else
		{
			bestmove -> isrrr = bestmove -> isrra;
			bestmove -> isrra = -1;
			bestmove -> isrrb = -1;
		}
	}
}

void	set_choice_rr(t_bestmove *bestmove)
{
	if (bestmove -> ra > 0 && bestmove -> rb > 0)
	{
		if (bestmove -> ra > bestmove -> rb)
		{
			bestmove -> isrr = bestmove -> rb;
			bestmove -> ra -= bestmove -> rb;
			bestmove -> rb = -1;
		}
		else if (bestmove -> ra < bestmove -> rb)
		{
			bestmove -> isrr = bestmove -> ra;
			bestmove -> rb -= bestmove -> ra;
			bestmove -> ra = -1;
		}
		else
		{
			bestmove -> isrr = bestmove -> ra;
			bestmove -> ra = -1;
			bestmove -> rb = -1;
		}
	}
}
