/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:37:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/11/04 19:43:13 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_min_(int *datas, const int size, int start, int curr)
{
	int value;

	value = datas[start];
	for (int i = start; i < size; i++)
		if (datas[i] < value && datas[i] > curr)
			return (0);
	return (1);
}

int		*max_suite(int *datas, int size, int *suitelen)
{
	int	**res;
	int	*lengths;

	res = malloc(sizeof(int *) * size);
	for (int i = 0; i < size; i++)
		res[i] = malloc(sizeof(int) * size);

	lengths = malloc(sizeof(int) * size);
	
	/* array created */

	int	index;
	int	curr;
	for (int i = 0; i < size; i++)
	{
		index = 1;
		res[i][0] = curr = datas[i];
		for (int j = i; j < size; j++)
		{
			if (datas[j] > curr && is_min_(datas, size, j, curr)) {
				res[i][index++] = datas[j];
				curr = datas[j];
			}
		}
		lengths[i] = index;
	}

	/* got all suites */

	int bigger = 0;
	for (int i = 1; i < size; i++) {
		if (lengths[i] > lengths[bigger]) {
			bigger = i;
		}
	}
	*suitelen = lengths[bigger];
	return (res[bigger]);
}

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
	int len;
	int *suite = max_suite(datas, ac - 1, &len);
	print_tab(suite, len);
	/*pushswap_a.stack = write_args_in_stack(&pushswap_a.pile, datas, ac - 1);
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
	{
		tri_fusion(datas, 0, ac - 1);
		sort(&pushswap_a, &pushswap_b);
	}*/

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