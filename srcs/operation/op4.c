/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:36:36 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:36:36 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	loop_divide_a(t_stack_node *cmp, t_cal *c)
{
	exe_pb();
	if (c->b_len)
	{
		if (cmp->val > c->low)
		{
			exe_rb();
			c->l2++;
		}
		else
			c->l1++;
	}
	else
	{
		if (cmp->val > c->low)
			c->l2++;
		else
		{
			exe_rb();
			c->l1++;
		}
	}
}

void	divide_a_stack(long len, t_cal *c)
{
	t_stack_node	*cmp;
	long			i;

	i = -1;
	cmp = run()->a.top;
	while (++i < len)
	{
		if (cmp->val < c->high)
			loop_divide_a(cmp, c);
		else
		{
			exe_ra();
			c->l3++;
		}
		cmp = run()->a.top;
	}
}

void	move_a_stack(t_cal c)
{
	long	i;

	i = 0;
	while (i < c.l2 || i < c.l3)
	{
		if (i < c.l2 && c.b_len)
			exe_rrb();
		if (i < c.l3 && c.l3 != run()->a.len)
			exe_rra();
		i++;
	}
}

void	process_a_stack(long len, long min, long max)
{
	t_stack_node	*top;
	t_cal			c;

	if (len == 0 || len == 1 || len > run()->a.len)
		return ;
	top = run()->a.top;
	if (len == 2)
	{
		if (top->val > top->prev->val)
			exe_sa();
		return ;
	}
	cal_ab(&c, min, max);
	if (len == 3)
		return (process_a3(top, c));
	divide_a_stack(len, &c);
	move_a_stack(c);
	process_a_stack(c.l3, c.high, max);
	if (run()->b.len == c.l2 + c.l1 && run()->b.len <= 3)
		process_small_b(run()->b.len, run()->b.top);
	else
	{
		process_b(c.l2, c.low, c.high - 1);
		process_b(c.l1, min, c.low - 1);
	}
}

void	process_a3(t_stack_node *top, t_cal c)
{
	long	v1;
	long	v2;
	long	v3;

	v1 = top->prev->prev->val;
	v2 = top->prev->val;
	v3 = top->val;
	if (c.a_len == 3)
		return (process_a3_e(v1, v2, v3));
	if (v1 > v2 && v1 > v3)
	{
		if (v2 < v3)
			exe_sa();
		return ;
	}
	if (v2 < v3 && v1 < v3)
		exe_sa();
	exe_pb();
	exe_sa();
	exe_pa();
	if (v1 < v2 && v1 < v3)
		exe_sa();
}
