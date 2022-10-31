/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:37:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/31 01:46:02 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	pushswap_a;
	t_push_swap	pushswap_b;
	int			*datas;

	datas = parse_av(ac - 1, av);
	if (!datas)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	pushswap_a.stack = write_args_in_stack(&pushswap_a.pile, datas, ac - 1);
	if (pushswap_a.pile->length <= 3)
	{
		if (pushswap_a.pile->length == 2)
		{
			if (pushswap_a.pile->first->data > pushswap_a.pile->last->data)
				swap(&pushswap_a);
		}
		else if (pushswap_a.pile->length == 3)
			sort_3(&pushswap_a);
	}
	else
		sort(&pushswap_a, &pushswap_b);

	// ft_printf("\n\t {bgred}STACK A{reset}\n\n");
	// print_all_stack(pushswap_a.stack);
	// ft_printf("\n\t {bggreen}PILE A{reset}\n\n");
	// print_pile(pushswap_a.pile);

	// ft_printf("\n\t {bgred}STACK B{reset}\n\n");
	// print_all_stack(pushswap_b.stack);
	// ft_printf("\n\t {bggreen}PILE B{reset}\n\n");
	// print_pile(pushswap_b.pile);

	memdel((void **)&datas);
	stackdel(&pushswap_a.stack);
	piledel(&pushswap_a.pile);
	piledel(&pushswap_b.pile);
	return (0);
}
// 126925