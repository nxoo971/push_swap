/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 05:42:22 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/09 04:57:47 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	ft_printf("{red}Size:	%d{reset}\n", stack->size);
	ft_printf("{red}First:	%p{reset}\n", stack->first);
	ft_printf("{red}Last:	%p{reset}\n\n", stack->last);
}

void	print_pile(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	while (tmp)
	{
		ft_printf("{blue}Data:	{red}%d{reset}\n", tmp->data);
		ft_printf("{cyan}Act:	%p{reset}\n", tmp);
		ft_printf("{cyan}Prev:	%p{reset}\n", tmp->prev);
		ft_printf("{cyan}Next:	%p{reset}\n", tmp->next);
		ft_printf("\t -------------------\n");
		tmp = tmp->prev;
	}
}

void	print_struct(t_bestmove bestmove)
{
	ft_printf("\n\t\t{yellow}PRINT MIN STRUCT{reset}\n");
	ft_printf("\npair: %d\n", bestmove.pair);
	ft_printf("\nIndex: %d\n", bestmove.index);
	ft_printf("\nMaxmove: %d\n", bestmove.maxmove);
	ft_printf("\nisrra %d\n", bestmove.isrra);
	ft_printf("\nisrrb %d\n", bestmove.isrrb);
}

void	print_all_struct(t_bestmove *bestmove, const int size)
{
	int	i;

	i = -1;
	ft_printf("\n\t\t{yellow}PRINT {red}ALL{reset} MIN STRUCT{reset}\n");
	while (++i < size)
		print_struct(bestmove[i]);
}

void	print_tab(const int *tab, const int size)
{
	int	i;

	i = -1;
	ft_printf("\n\t\t{yellow}PRINT TAB{reset}\n");
	ft_printf("{\n");
	while (++i < size)
		ft_printf("\t[%d] = %d\n", i, tab[i]);
	ft_printf("}\n");
	ft_printf("\n\t{gray}-----------------{reset}\n");
}
