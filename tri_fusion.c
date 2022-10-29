/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fusion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:11:07 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/28 21:36:38 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(int *dest, const int *src, int index, int *start, int end)
{
	while (index < end)
	{
		dest[*start] = src[index++];
		*start += 1;
	}
	return (dest);
}

void	fusion(int *a, int start, int middle, int end)
{
	int	l_size = middle - start + 1;
	int	r_size = end - middle;
	int left[l_size];
	int	right[r_size];

	for (int i = 0; i < l_size; i++)
		left[i] = a[start + i];
	for (int i = 0; i < r_size; i++)
		right[i] = a[middle + i + 1];

	int i, j;

	i = 0;
	j = 0;
	while (i < l_size && j < r_size)
		a[start++] = (left[i] <= right[j]) ? left[i++] : right[j++];
	copy_array(a, left, i, &start, l_size);
	copy_array(a, right, j, &start, r_size);
}

void	tri_fusion(int *a, int start, int end)
{
	if (start < end)
	{
		int	middle = (start + end) / 2;
		tri_fusion(a, start, middle);
		tri_fusion(a, middle + 1, end);
		fusion(a, start, middle, end);
	}
}
