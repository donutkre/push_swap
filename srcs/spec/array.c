/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 20:47:51 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/29 20:47:51 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_array	stack_arr(t_stack stack)
{
	t_array			arr;
	long			i;
	t_stack_node	*node;

	mem(&arr.ds, sizeof(long) * stack.len);
	if (!arr.ds)
	{
		arr.len = 0;
		arr.ds = 0;
		return (arr);
	}
	arr.len = stack.len;
	node = stack.bottom;
	i = 0;
	while (i < stack.len)
	{
		arr.ds[i] = node->val;
		node = node->next;
		i++;
	}
	return (arr);
}

void	sorted_a_arr(void)
{
	long	len;

	len = run()->a.len;
	if (len == 0)
		return ;
	run()->arr = stack_arr(run()->a);
	if (run()->arr.ds == 0)
		free_ret(1);
	algo(run()->arr.ds, 0, len - 1);
}

void	swap_arr(long *arr, long a, long b)
{
	long	tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int	copy_arr(long **r, long *arr, long left, long right)
{
	long	nl;
	long	i;

	nl = right - left + 1;
	if (!mem(r, sizeof(long) * nl))
		return (0);
	i = 0;
	while (i < nl)
	{
		(*r)[i] = arr[left + i];
		i++;
	}
	return (1);
}

int	sorted_arr(t_array arr)
{
	long	i;
	long	len;
	long	*ds;

	i = 0;
	len = arr.len;
	ds = arr.ds;
	while (i < len - 1)
	{
		if (ds[i] == ds[i + 1])
			return (1);
		i++;
	}
	return (0);
}
