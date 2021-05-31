/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:39:39 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:39:39 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_stack(t_stack *stack, long val)
{
	t_stack_node	*allo;

	if (!mem(&allo, sizeof(t_stack_node)))
		return (0);
	allo->val = val;
	stack_push(stack, allo);
	return (1);
}

int	stack_free(t_stack *stack, long *val)
{
	t_stack_node	*node;

	node = stack_pop(stack);
	if (!node)
		return (0);
	*val = node->val;
	frees(&node);
	return (1);
}

t_stack_node	*stack_pop(t_stack *stack)
{
	t_stack_node	*node;

	if (stack->len == 0)
		return (0);
	node = stack->top;
	if (stack->len == 1)
	{
		stack->top = 0;
		stack->bottom = 0;
		stack->len = 0;
		return (node);
	}
	stack->top = stack->top->prev;
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->len -= 1;
	return (node);
}

void	stack_push(t_stack *stack, t_stack_node *item)
{
	if (stack->len == 0)
	{
		item->prev = item;
		item->next = item;
		stack->top = item;
		stack->bottom = item;
		stack->len = 1;
		return ;
	}
	item->prev = stack->top;
	item->next = stack->bottom;
	stack->top->next = item;
	stack->bottom->prev = item;
	stack->top = item;
	stack->len += 1;
}
