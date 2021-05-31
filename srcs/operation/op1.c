/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:01:51 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/29 21:01:51 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../push_swap.h"

void	exe_sa(void)
{
	stack_swap(&run()->a);
	if (run()->sb)
	{
		run()->sb = 0;
		if (run()->call_op)
			print_char("ss\n");
		return ;
	}
	execute_op();
	run()->sa = 1;
}

void	exe_sb(void)
{
	stack_swap(&run()->b);
	if (run()->sa)
	{
		run()->sa = 0;
		if (run()->call_op)
			print_char("ss\n");
		return ;
	}
	execute_op();
	run()->sb = 1;
}

void	exe_ss(void)
{
	execute_op();
	stack_swap(&run()->a);
	stack_swap(&run()->b);
	if (run()->call_op)
		write(1, "ss\n", 3);
}

void	exe_pa(void)
{
	execute_op();
	stack_move(&run()->a, &run()->b);
	if (run()->call_op)
		write(1, "pa\n", 3);
}

void	exe_pb(void)

{
	execute_op();
	stack_move(&run()->b, &run()->a);
	if (run()->call_op)
		write(1, "pb\n", 3);
}
