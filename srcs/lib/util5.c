/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:24:58 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:24:58 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_pro(t_array arr, long *small, long *big, t_pt val)
{
	long	i;
	int		c;
	long	li;
	long	ri;

	li = 0;
	ri = arr.len - 1;
	c = 0;
	i = 0;
	while (i < arr.len)
	{
		if (!c && arr.ds[i] > val.min)
		{
			li = i;
			c = 1;
		}
		if (arr.ds[i] > val.max)
		{
			ri = i;
			break ;
		}
		i++;
	}
	*small = arr.ds[li + (long)((double)(ri - li) *0.3333333333)];
	*big = arr.ds[li + (long)((double)(ri - li) *0.66666666667)];
}

void	cal_ab(t_cal *c, long min, long max)
{
	long	ii;
	t_pt	val;

	val.min = min;
	val.max = max;
	get_pro(run()->arr, &c->low, &c->high, val);
	if (c->high < c->low)
	{
		ii = c->high;
		c->high = c->low;
		c->low = ii;
	}
	c->l1 = 0;
	c->l2 = 0;
	c->l3 = 0;
	c->a_len = run()->a.len;
	c->b_len = run()->b.len;
}

int	mem(void *c, size_t s)
{
	void	**pt;

	pt = (void **)c;
	*pt = malloc(s);
	if (*pt == 0)
		return (0);
	return (1);
}

void	frees(void *c)
{
	void	**p;

	p = (void **)c;
	if (*p)
	{
		free(*p);
		*p = 0;
	}
}

void	free_ret(int c)
{
	long	id;

	while (run()->a.top)
		stack_free(&run()->a, &id);
	while (run()->b.top)
		stack_free(&run()->b, &id);
	frees(&run()->arr.ds);
	if (c != 0)
		char_error("Error\n");
	exit(c);
}
