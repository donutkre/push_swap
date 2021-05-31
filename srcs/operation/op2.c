/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:07:48 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/29 21:07:48 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exe_ra(void)
{
	stack_rotate(&run()->a);
	if (run()->rb)
	{
		run()->rb = 0;
		if (run()->call_op)
			print_char("rr\n");
		return ;
	}
	execute_op();
	run()->ra = 1;
}

void	exe_rb(void)
{
	stack_rotate(&run()->b);
	if (run()->ra)
	{
		run()->ra = 0;
		if (run()->call_op)
			print_char("rr\n");
		return ;
	}
	execute_op();
	run()->rb = 1;
}

void	exe_rr(void)
{
	execute_op();
	stack_rotate(&run()->a);
	stack_rotate(&run()->b);
	if (run()->call_op)
		print_char("rr\n");
}

void	exe_rra(void)
{
	stack_rev_rotate(&run()->a);
	if (run()->rrb)
	{
		run()->rrb = 0;
		if (run()->call_op)
			print_char("rrr\n");
		return ;
	}
	execute_op();
	run()->rra = 1;
}

void	exe_rrb(void)
{
	stack_rev_rotate(&run()->b);
	if (run()->rra)
	{
		run()->rra = 0;
		if (run()->call_op)
			print_char("rrr\n");
		return ;
	}
	execute_op();
	run()->rrb = 1;
}
