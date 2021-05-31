/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op6.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:36:55 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:36:55 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	resolve_btop3(t_stack_node *top)
{
	long	v1;
	long	v2;
	long	v3;

	v1 = top->prev->prev->val;
	v2 = top->prev->val;
	v3 = top->val;
	if (v1 > v2 && v1 > v3)
	{
		if (v2 > v3)
			exe_sb();
		exe_pa();
		exe_rr();
		exe_pa();
		exe_rrr();
		return (exe_pa());
	}
	if (v2 > v1 && v2 > v3)
		exe_sb();
	exe_pa();
	exe_pa();
	exe_pa();
	if ((v1 < v2 && v1 > v3) || (v1 > v2 && v1 < v3))
		exe_sa();
}

void	divide_b_stack(long len, t_cal *c)
{
	long			i;
	t_stack_node	*cmp;

	i = -1;
	cmp = run()->b.top;
	while (++i < len)
	{
		if (cmp->val > c->low)
		{
			exe_pa();
			if (cmp->val < c->high)
			{
				exe_ra();
				c->l2++;
			}
			else
				c->l3++;
		}
		else
		{
			exe_rb();
			c->l1++;
		}
		cmp = run()->b.top;
	}
}

void	conv_init(const char *c)
{
	t_con	*p;
	int		fd;

	p = parser();
	p->specz = specz_create();
	p->fr = fr(c);
	open_f(&fd, c);
	p->fr.fd = fd;
	p->error_hand = 0;
	spec_init();
}

void	conv_fd_init(int fd, const char *c)
{
	t_con	*p;

	p = parser();
	p->specz = specz_create();
	p->fr = fr(c);
	p->fr.fd = fd;
	p->error_hand = 0;
	spec_init();
}

char	reference(void)
{
	char	c;

	c = run()->input[run()->input_next];
	if (c)
	{
		run()->input_next++;
	}
	return (c);
}
