/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:03:11 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/23 00:29:44 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, const char **av)
{
	t_pile	pile;
	t_stack *tmp;
	int		*datas;

	if ((datas = check_args(ac - 1, av)) != NULL) {
			// 2 1 3 6 5 8
		if ((pile.a = write_args_in_stack(datas, ac - 1)) != NULL)
		{
			tmp = pile.a;
			ft_printf("\n\t{bggreen}Before {yellow}Stack {red}A{reset}\n\n");
			print_all_stack(tmp);

			algo(&tmp, &pile.b);

			/*swap(tmp);
			push(&pile.b, &tmp);
			push(&pile.b, &tmp);
			push(&pile.b, &tmp);
			rotate(&tmp);
			rotate(&pile.b);
			r_rotate(&tmp);
			r_rotate(&pile.b);
			swap(tmp);
			push(&tmp, &pile.b);
			push(&tmp, &pile.b);
			push(&tmp, &pile.b);*/

			ft_printf("\n\t{yellow}Stack {red}A{reset}\n\n");
			print_all_stack(tmp);
			ft_printf("\n\t{yellow}Stack {cyan}B{reset}\n\n");
			print_all_stack(pile.b);
			return (0);
		}
	}
	ft_putstr_fd("Error\n", 2);
	return (0);
}
