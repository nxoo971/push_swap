/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:00:31 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/09 15:40:14 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

static \
void	rr2(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	rotate(ptr_a);
	rotate(ptr_b);
}

static \
void	rrr2(t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	r_rotate(ptr_a);
	r_rotate(ptr_b);
}

int	do_cmd(const char *action, t_push_swap *ptr_a, t_push_swap *ptr_b)
{
	if (!ft_strcmp(action, "ra\n"))
		rotate(ptr_a);
	else if (!ft_strcmp(action, "rb\n"))
		rotate(ptr_b);
	else if (!ft_strcmp(action, "rra\n"))
		r_rotate(ptr_a);
	else if (!ft_strcmp(action, "rrb\n"))
		r_rotate(ptr_b);
	else if (!ft_strcmp(action, "rr\n"))
		rr2(ptr_a, ptr_b);
	else if (!ft_strcmp(action, "rrr\n"))
		rrr2(ptr_a, ptr_b);
	else if (!ft_strcmp(action, "sa\n"))
		s(ptr_a);
	else if (!ft_strcmp(action, "sb\n"))
		s(ptr_b);
	else if (!ft_strcmp(action, "ss\n"))
		ss(ptr_a, ptr_b);
	else if (!ft_strcmp(action, "pa\n"))
		push(ptr_a, ptr_b);
	else if (!ft_strcmp(action, "pb\n"))
		push(ptr_b, ptr_a);
	else
		return (-1);
	return (1);
}

static \
void	read_instructions(t_push_swap *ptr_a, t_push_swap *ptr_b, int *display)
{
	char	*str;

	*display = 1;
	while (1)
	{	
		str = get_next_line(0, 0);
		if (!str)
			break ;
		if (!ft_strcmp(str, "print -a\n"))
			print_pile(ptr_a->pile);
		else if (!ft_strcmp(str, "print -b\n"))
			print_pile(ptr_b->pile);
		else
		{
			if (do_cmd(str, ptr_a, ptr_b) == -1)
			{
				ft_putendl_fd("Error", 2);
				--(*display);
				break ;
			}
		}
		ft_memdel((void **)& str);
	}
	ft_memdel((void **)& str);
	get_next_line(0, 1);
}

int	main(int ac, char **av)
{
	static t_push_swap	ptr_a = {.pile = 0, .stack = 0};
	static t_push_swap	ptr_b = {.pile = 0, .stack = 0};
	int					tmp_size;
	int					display;
	int					*tmp;

	if (ac < 2)
		return (0);
	tmp_size = 0;
	tmp = parse_args(ac, av, & ptr_a, & tmp_size);
	if (!tmp)
		return (0);
	read_instructions(& ptr_a, & ptr_b, & display);
	if (display)
	{
		if (ptr_a.pile && pile_is_sorted(ptr_a.pile) \
			&& ptr_a.stack && tmp_size == ptr_a.stack->size)
			ft_putendl("OK");
		else
			ft_putendl("KO");
	}
	exit_free_all(ptr_a, ptr_b, tmp);
}
