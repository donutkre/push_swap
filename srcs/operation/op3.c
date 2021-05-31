/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:08:13 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/29 21:08:13 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../push_swap.h"

void	print_char(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	write(1, c, i);
}

void	execute_op(void)
{
	if (run()->call_op)
	{
		if (run()->ra)
			print_char("ra\n");
		if (run()->rb)
			print_char("rb\n");
		if (run()->rra)
			print_char("rra\n");
		if (run()->rrb)
			print_char("rrb\n");
		if (run()->sa)
			print_char("sa\n");
		if (run()->sb)
			print_char("sb\n");
	}
	run()->ra = 0;
	run()->rb = 0;
	run()->rra = 0;
	run()->rrb = 0;
	run()->sa = 0;
	run()->sb = 0;
}

void	exe_rrr(void)
{
	execute_op();
	stack_rev_rotate(&run()->a);
	stack_rev_rotate(&run()->b);
	if (run()->call_op)
		print_char("rrr\n");
}

int	valid_line(int len, const char *b)
{
	if ((len == 2 && ((b[0] == 'p' && (b[1] == 'a' || b[1] == 'b'))
				|| (b[0] == 's' && (b[1] == 'a'
						|| b[1] == 'b' || b[1] == 's'))
				|| (b[0] == 'r' && (b[1] == 'a'
						|| b[1] == 'b' || b[1] == 'r'))))
		|| (len == 3 && b[0] == 'r' && b[1] == 'r'
			&& (b[2] == 'a' || b[2] == 'b' || b[2] == 'r')))
		return (1);
	return (0);
}

int	valid_sort(void)
{
	long			i;
	long			c;
	t_stack_node	*nd;

	i = 0;
	c = 0;
	nd = run()->a.top;
	while (i < run()->a.len - 1)
	{
		if (nd->val < nd->prev->val)
			c++;
		nd = nd->prev;
		i++;
	}
	if (c == run()->a.len - 1)
		return (1);
	return (0);
}
