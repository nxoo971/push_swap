/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:11:07 by jewancti          #+#    #+#             */
/*   Updated: 2022/12/09 15:17:51 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef INT_MAX
# define INT_MAX	2147483647
#endif

#ifndef INT_MIN
# define INT_MIN	-2147483648
#endif

void	print_error_exit_free(const char *print, char **destroy)
{
	ft_putnendl_fd(print, ft_strlen(print), 2);
	if (destroy)
		ft_arraydel((void **)destroy);
	exit(0);
}

void	set_int(char *s, char **destroy, int **tab, int *size)
{
	int			i;
	int			isneg;
	intptr_t	overflow;

	i = 0;
	isneg = 1;
	overflow = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] == ' ' || s[i] == '\0')
			print_error_exit_free("Error", destroy);
		if (s[i] == '-' || s[i] == '+')
			isneg *= -(1 && ++i);
		if (s[i] == '-' || s[i] == '+')
			print_error_exit_free("Error", destroy);
		while (ft_isdigit(s[i]))
			overflow = overflow * 10 + s[i++] - '0';
		overflow *= isneg;
		if (s[i] != '\0' || overflow > INT_MAX || overflow < INT_MIN)
			print_error_exit_free("Error", destroy);
		(*tab)[(*size)++] = ft_atoi(s);
	}
}

void	parse_int(char **s, int *tab, int *size)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i][0]) && s[i][1] == '\0')
			print_error_exit_free("Error", s);
		set_int(s[i], s, & tab, size);
	}
}

int	*parse_args(int ac, char **av, t_push_swap *ptr, int *size)
{
	int		tab[10000];
	char	**split;
	int		index;

	index = 1;
	while (index < ac)
	{
		if (av[index][0] == '\0')
			print_error_exit_free("Error", 0);
		split = ft_split(av[index], ' ');
		if (!split || !split[0])
			print_error_exit_free("Error", split);
		parse_int(split, tab, size);
		ft_arraydel((void **)split);
		index++;
	}
	if (!check_doublon(tab, *size))
	{
		ft_putnendl_fd("Error", 5, 2);
		return (0);
	}
	return (arraynpiledup(ptr, tab, *size));
}
