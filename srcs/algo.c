/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:38:57 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:38:57 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	resolve_mini(long *arr, long left, long right)
{
	long	i;
	long	j;
	long	small;

	i = left;
	while (i < right)
	{
		small = i;
		j = i + 1;
		while (j <= right)
		{
			if (arr[small] > arr[j])
				small = j;
			j++;
		}
		swap_arr(arr, i, small);
		i++;
	}
	return (1);
}

int	algo2(long *arr, long *left_c, long *right_c, t_merge *c)
{
	c->lb = c->mid - c->left;
	c->rb = c->right - c->mid - 1;
	c->li = 0;
	c->ri = 0;
	if (!algo(left_c, 0, c->lb) || !algo(right_c, 0, c->rb))
	{
		frees(&left_c);
		frees(&right_c);
		return (0);
	}
	c->i = c->left - 1;
	while (++c->i <= c->right)
		if ((left_c[c->li] < right_c[c->ri] && c->li <= c->lb)
			|| c->ri > c->rb)
			arr[c->i] = left_c[c->li++];
	else if ((left_c[c->li] >= right_c[c->ri]
			&& c->ri <= c->rb) || c->li > c->lb)
		arr[c->i] = right_c[c->ri++];
	frees(&left_c);
	frees(&right_c);
	return (1);
}

int	algo(long *arr, long left, long right)
{
	long	mid;
	long	*left_c;
	long	*right_c;
	t_merge	c;

	left_c = 0;
	right_c = 0;
	if (right - left < 5)
		return (resolve_mini(arr, left, right));
	mid = (right + left) / 2;
	if (!copy_arr(&left_c, arr, left, mid))
		return (0);
	if (!copy_arr(&right_c, arr, mid + 1, right))
	{
		frees(&left_c);
		return (0);
	}
	c.mid = mid;
	c.left = left;
	c.right = right;
	return (algo2(arr, left_c, right_c, &c));
}
