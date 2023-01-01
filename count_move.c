/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:02:47 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/08 17:33:51 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static \
int	ft_dieri(int data[4])
{
	bubblesort(data, 4);
	return (data[0]);
}

static \
void	set_parameters(t_push_swap *ptr_a, t_push_swap *ptr_b, \
		const int data, t_bestmove *bestmove)
{
	bestmove -> rb = find_index_from_pile(data, ptr_b);
	bestmove -> isrra = (ptr_a -> stack -> size - bestmove -> ra);
	bestmove -> isrrb = (ptr_b -> stack -> size - bestmove -> rb);
	bestmove -> is_ra_rb = bestmove -> ra + bestmove -> rb;
	bestmove -> isrra_rrb = (ptr_a -> stack -> size - bestmove -> ra)
		+ ((ptr_b -> stack -> size - bestmove -> rb));
	bestmove -> isrra_rb = (ptr_a -> stack -> size - bestmove -> ra)
		+ bestmove -> rb;
	bestmove -> isrrb_ra = (ptr_b -> stack -> size - bestmove -> rb)
		+ bestmove -> ra;
	bestmove -> maxmove = ft_dieri((int [4]){bestmove -> is_ra_rb,
			bestmove -> isrra_rrb,
			bestmove -> isrra_rb,
			bestmove -> isrrb_ra});
	bestmove -> isrr = -1;
	bestmove -> isrrr = -1;
	bestmove -> value = data;
}

void	best_move(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	t_pile		*pileb;
	t_bestmove	*bestmove;
	t_bestmove	minbestmove;
	int			tmpdata;
	int			i;

	pileb = ptr_b->pile;
	bestmove = malloc(sizeof(t_bestmove) * ptr_b->stack->size);
	if (!bestmove)
		return ;
	i = -1;
	while (++i < ptr_b->stack->size && pileb)
	{
		tmpdata = pileb->data;
		find_pair_from_pile(tmpdata, ptr_a, & bestmove[i]);
		set_parameters(ptr_a, ptr_b, tmpdata, & bestmove[i]);
		pileb = pileb->prev;
	}
	minbestmove = find_min_from_struct(bestmove, ptr_b->stack->size);
	best(&minbestmove);
	set_choice_rr(& minbestmove);
	set_choice_rrr(& minbestmove);
	exec_move(ptr_a, ptr_b, minbestmove);
	free(bestmove);
}

static \
void	do_action(const char *print, int counter, \
		t_push_swap *ptr, void f(t_push_swap *p))
{
	while (--counter >= 0)
	{
		f(ptr);
		ft_putendl(print);
	}
}

void	exec_move(t_push_swap *ptr_a, t_push_swap *ptr_b, t_bestmove bestmove)
{
	while (--bestmove.isrrr >= 0)
		rrr(ptr_a, ptr_b);
	while (--bestmove.isrr >= 0)
		rr(ptr_a, ptr_b);
	do_action("rra", bestmove.isrra, ptr_a, & r_rotate);
	do_action("rrb", bestmove.isrrb, ptr_b, & r_rotate);
	do_action("ra", bestmove.ra, ptr_a, & rotate);
	do_action("rb", bestmove.rb, ptr_b, & rotate);
	push(ptr_a, ptr_b);
	ft_printf("pa\n");
}
