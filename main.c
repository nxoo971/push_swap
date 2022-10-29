/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:37:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/30 00:25:10 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arraydel(int **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}

t_stack	*write_args_in_stack(t_pile **pile, int *datas, int len)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = 0;
	while (i < len)
	{
		stack_add(pile, &stack, datas[i]);
		i++;
	}
	return (stack);
}

int		is_bigger(int a, int b)
{
	return (a > b);
}

int		is_smaller(int a, int b)
{
	return (a < b);
}

void	print_tab(int *tab, int size)
{
	for (int i = 0; i < size; i++)
		ft_printf("%d, ", tab[i]);
	ft_printf("\n");
}

int		is_sorted(int *a, int size, int (*f)(int, int))
{
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (!f(a[i], a[j]))
				return (0);
	return (size > 1);
}

void	max_suite(int *suite, int start, int size, int **find, int *find_size)
{
	if (!(start < size) || size < 0)
		return ;

	for (int i = 1; i < size - start; i++)
	{
		max_suite(suite + start, start + 1, i, find, find_size);
		if (is_sorted(suite, i, & is_smaller))
		{
			*find = suite;
			*find_size = i;
			print_tab(*find, *find_size);
		}
	}
}

int	*find_max_suite(t_pile *pile, int *datas)
{
	int		**suite;
	int		size[pile->length];
	int		indexsuite;

	suite = malloc(sizeof(int *) * pile->length);
	for (int i = 0; i < pile->length; i++)
		suite[i] = malloc(sizeof(int) * pile->length);

	for (int i = 0; i < pile->length; i++)
	{
		indexsuite = 0;
		for (int j = 0; j < pile->length; j++)
		{
			if (datas[i] < datas[j])
				suite[i][indexsuite++] = datas[j];
		}
		size[i] = indexsuite;
	}

	for (int i = 0; i < pile->length; i++)
	{
		ft_printf("Pour le chiffre: {bgred}%d{reset}, il y a: ", datas[i]);
		for (int j = 0; j < size[i]; j++)
		{
			ft_printf("%d, ", suite[i][j]);
		}
		ft_printf("\n");
	}

	int **find = malloc(sizeof(int *) * pile->length);
	int *find_size = malloc(sizeof(int) * pile->length);
	for (int i = 0; i < pile->length; i++) {
		max_suite(suite[i], 0, size[i], &find[i], &find_size[i]);
	}

	ft_printf("\n\t-------- \n");
	for (int i = 0; i < pile->length; i++) {
		print_tab(find[i], find_size[i]);
		ft_printf("\n");
	}
}
/*
	push tout le reste a gauche a part ma suite
	reperer les plus petit du premier elemnt et les push sur a

	tout push sur b et n'en garder que 3 dans a
	trier a
	prendre le plus petit dans b et le foutre dans a et ainsi de suite
*/

int		search_index_by_data(t_pile *pile, int data)
{
	t_stack *stack = pile->first;

	int	index;
	for (index = 0; stack; index++, stack = stack->prev)
		if (index == data)
			break;
	return (stack->data);
}

void	check(t_push_swap *a)
{
	
}

int	find_next_bigger(t_stack *s, int val)
{
	for (; s; s = s->prev)
		if (s->data < val)
			return (0);
	return (1);
}

void	sort_tst(t_push_swap *a, t_push_swap *b, int *tab, int len)
{
	int	pushed;

	for (t_stack *ptr = b->pile->first; ptr; ptr = b->pile->first)
	{
		if (b->pile->first->data > a->pile->first->data)
		{
			pushed = 0;
			for (t_stack *s = a->pile->first; s && b->pile->first->data > a->pile->first->data;)
			{
				rotate(a);
				pushed++;
				s = a->pile->first;
			}
			push(a, b);
			while (--pushed >= 0)
				r_rotate(a);
		} else
			push(a, b);
	}
}

void	push_all_except3(t_push_swap *a, t_push_swap *b)
{
	int	pile_len;

	pile_len = a->pile->length;
	while (pile_len-- > 1)
		push(b, a);
	//sort_3(a, 0);
	
	int max_len = a->pile->last->data;
	int tmp[max_len];

	t_stack *stack = b->stack;
	int	len = 0;

// find indexS
	for (int i = 0; i < max_len && stack; i++, stack = stack->prev) {
		if (stack->data < max_len) {
			tmp[len++] = i;
		}
	}
// set values thanks to indexs
	int	before[len];
	for (int i = 0; i < len; i++)
		before[i] = search_index_by_data(b->pile, tmp[i]);
// sort to push the smaller one by one
	tri_fusion(before, 0, len - 1);
/*
	trouver le plus grand par rapport au premier de la pile A
	si ce n'est pas le premier dans la pile B
	push_a jusqu'à trouver notre valeur
	on souhaite la garder donc on fait un ra pour la placer en bas
	on push ce que l'on vient de push dans A -> dans B
	on fait un rra pour placer le dernier en haut et ensuite on le pusha
*/
	if (before[len - 1] < a->pile->first->data)
	{
		sort_tst(a, b, before, len - 1);
		
		return ;
	}

	int	counter = 0;
	while (counter < len)
	{
		stack = b->pile->first;
		if (!stack)
			counter++;
		sort_tst(a, b, before, len - 1);
	}
}

void	trie(t_push_swap *a, t_push_swap *b)
{
	if (a->pile->length <= 3)
	{
		if (a->pile->length == 2) {
			if (a->pile->first->data > a->pile->last->data)
				swap(a->stack);
		}
		else if (a->pile->length == 3)
			sort_3(a, b);
		return ;
	}
	
// tout push de l'autre côter sauf 3
	while (a->pile->length > 3)
		push(b, a);
// les triés
	sort_3(a, 0);

// tant qu'il y a des elems dans ma pile alors ->
	while (b->pile->length)
	{
		t_stack	*first = b->pile->first;
			// s'il est supérieur au premier de la stack A alors ->
		if (first->data > a->pile->last->data)
		{
			/*
				il est supérieur au dernier de la liste, alors on le push dans A et on le rotate
				afin de le placer en fin de liste
			*/
			if (first->data > a->pile->last->data) {
				push(a, b);
				rotate(a);
			}
		}
		else
		{
			int	rotated = 0;

			while (first->data > a->pile->first->data)
			{
				rotate(a);
				rotated++;
			}
			/* on le place maintenant */
			push(a, b);
			/* on remet en place les rotateds */
			while (--rotated >= 0)
				r_rotate(a);
		}
	}
}

int	main(int ac, char **av)
{
	t_push_swap	pushswap_a;
	t_push_swap	pushswap_b;

	int *datas = parse_av(ac - 1, av);
	pushswap_a.stack = write_args_in_stack(&pushswap_a.pile, datas, ac - 1);

	ft_printf("\n\t {bgred}STACK A{reset}\n\n");
	print_all_stack(pushswap_a.stack);
	ft_printf("\n\t {bggreen}PILE A{reset}\n\n");
	print_pile(pushswap_a.pile);

	/*find_max_suite(pushswap_a.pile, datas); return 0;
	sort(&pushswap_a, &pushswap_b);*/
	//push_all_except3(&pushswap_a, &pushswap_b);
	trie(&pushswap_a, &pushswap_b);
	ft_printf("\n\t {bgred}STACK A{reset}\n\n");
	print_all_stack(pushswap_a.stack);
	ft_printf("\n\t {bggreen}PILE A{reset}\n\n");
	print_pile(pushswap_a.pile);

	//pushswap_b.stack = stack_new(&pushswap_b.pile, 42);
	ft_printf("\n\t {bgred}STACK B{reset}\n\n");
	print_all_stack(pushswap_b.stack);
	ft_printf("\n\t {bggreen}PILE B{reset}\n\n");
	print_pile(pushswap_b.pile);

	/*ft_printf("\n\n\t{bgcyan}PUSH{reset}\n\n\n");

	ft_printf("\n\t {bgred}STACK B{reset}\n\n");
	print_all_stack(pushswap_b.stack);
	ft_printf("\n\t {bggreen}PILE B{reset}\n\n");
	print_pile(pushswap_b.pile);


	ft_printf("\n\t {bgred}STACK A{reset}\n\n");
	print_all_stack(pushswap_a.stack);
	ft_printf("\n\t {bggreen}PILE A{reset}\n\n");
	print_pile(pushswap_a.pile);*/

	arraydel(&datas);
	ft_printf("\n");
	return (0);
}
