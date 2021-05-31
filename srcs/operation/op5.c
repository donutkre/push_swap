/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:36:45 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:36:45 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	process_b3(long v1, long v2, long v3)
{
	if (v1 > v2 && v1 > v3)
	{
		if (v2 > v1)
			exe_sb();
		exe_rrb();
	}
	else if (v2 > v1 && v2 > v3)
	{
		if (v1 > v3)
			exe_rb();
		else
			exe_sa();
	}
	exe_pa();
	exe_pa();
	exe_pa();
	if (v3 > v1 && v3 > v2 && v1 > v2)
		exe_sa();
}

void	process_small_b(long len, t_stack_node *top)
{
	long	v1;
	long	v2;
	long	v3;

	v1 = top->prev->prev->val;
	v2 = top->prev->val;
	v3 = top->val;
	if (len == 1)
		return (exe_pa());
	if (len == 2)
	{
		top = run()->b.top;
		if (top->val < top->prev->val)
			exe_sb();
		exe_pa();
		return (exe_pa());
	}
	if (len == 3)
		process_b3(v1, v2, v3);
}

void	process_a3_e(long v1, long v2, long v3)
{
	if (v1 < v2 && v1 < v3)
	{
		if (v2 < v3)
		{
			exe_ra();
			exe_sa();
		}
		else
			exe_rra();
	}
	else if (v1 > v2 && v1 > v3)
	{
		if (v3 > v2)
			exe_sa();
	}
	else if (v3 > v2)
		exe_ra();
	else
	{
		exe_rra();
		exe_sa();
	}
}

void	process_b2(long min, long max, t_cal c)
{
	long	i;

	i = -1;
	while (++i < c.l1)
		exe_rrb();
	process_a_stack(c.l3, c.high, max);
	i = -1;
	while (++i < c.l2)
		exe_rra();
	process_a_stack(c.l2, c.low + 1, c.high - 1);
	process_b(c.l1, min, c.low);
}

void	process_b(long len, long min, long max)
{
	t_stack_node	*top;
	t_cal			c;

	if (len == 0 || len > run()->b.len)
		return ;
	if (len == 1)
		return (exe_pa());
	top = run()->b.top;
	if (len == 2)
	{
		if (top->val < top->prev->val)
			exe_sb();
		exe_pa();
		return (exe_pa());
	}
	if (len == 3)
		return (resolve_btop3(top));
	cal_ab(&c, min, max);
	divide_b_stack(len, &c);
	process_b2(min, max, c);
}
