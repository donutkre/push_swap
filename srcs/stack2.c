/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:40:07 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:40:07 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack *stack)
{
	t_stack_node	*sec;
	long			swap_tmp;

	if (stack->len <= 1)
		return ;
	sec = stack->top->prev;
	swap_tmp = sec->val;
	sec->val = stack->top->val;
	stack->top->val = swap_tmp;
}

void	stack_move(t_stack *dest, t_stack *src)
{
	t_stack_node	*action;

	if (src->len == 0)
		return ;
	action = stack_pop(src);
	stack_push(dest, action);
}

void	stack_rotate(t_stack *stack)
{
	if (stack->len == 0)
		return ;
	stack->top = stack->top->prev;
	stack->bottom = stack->bottom->prev;
}

void	stack_rev_rotate(t_stack *stack)
{
	if (stack->len == 0)
		return ;
	stack->top = stack->top->next;
	stack->bottom = stack->bottom->next;
}
