/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:28:04 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/09 17:10:09 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static \
void	rearrange(t_push_swap *ptr)
{
	int	min;
	int	index;

	min = find_min(*ptr);
	index = find_index_from_pile(min, ptr);
	if (index > ptr->stack->size / 2)
	{
		while (ptr->stack->first->data != min)
		{
			ft_printf("rra\n");
			r_rotate(ptr);
		}
	}
	else
	{
		while (ptr->stack->first->data != min)
		{
			ft_printf("ra\n");
			rotate(ptr);
		}
	}
}

static \
int	case_pile_size_2(t_push_swap *ptr)
{
	if (ptr->stack->size == 2 && ptr->pile->data > ptr->pile->prev->data)
	{
		s(ptr);
		ft_printf("sa\n");
	}
	return (pile_is_sorted(ptr->pile));
}

void	algo(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	while (ptr_a->stack->size > 3)
	{
		push(ptr_b, ptr_a);
		ft_printf("pb\n");
	}
	sort_3(ptr_a);
	while (ptr_b->stack && ptr_b->stack->size)
		best_move(ptr_a, ptr_b);
}

int	main(int ac, char **av)
{
	static t_push_swap	ptr_a = {.pile = 0, .stack = 0};
	static t_push_swap	ptr_b = {.pile = 0, .stack = 0};
	int					*array_args;
	int					size_args;

	if (ac < 2)
		return (0);
	size_args = 0;
	array_args = 0;
	array_args = parse_args(ac, av, & ptr_a, & size_args);
	if (!array_args || !ptr_a.pile || !ptr_a.pile->prev)
		exit_free_all(ptr_a, ptr_b, array_args);
	if (case_pile_size_2(& ptr_a))
		exit_free_all(ptr_a, ptr_b, array_args);
	bubblesort(array_args, size_args);
	do_median(& ptr_a, & ptr_b, array_args);
	ft_memdel((void **)& array_args);
	algo(& ptr_a, & ptr_b);
	if (!pile_is_sorted(ptr_a.pile))
		rearrange(& ptr_a);
	exit_free_all(ptr_a, ptr_b, 0);
}
