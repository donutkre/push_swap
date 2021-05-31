/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:39:03 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:39:03 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	algo_action2(const char *b)
{
	if (b[0] == 'p')
	{
		if (b[1] == 'a')
			exe_pa();
		else if (b[1] == 'b')
			exe_pb();
	}
	else if (b[0] == 's')
	{
		if (b[1] == 'a')
			exe_sa();
		else if (b[1] == 'b')
			exe_sb();
		else if (b[1] == 's')
			exe_ss();
	}
	else if (b[0] == 'r')
	{
		if (b[1] == 'a')
			exe_ra();
		else if (b[1] == 'b')
			exe_rb();
		else if (b[1] == 'r')
			exe_rr();
	}
}

void	algo_action(int len, const char *b)
{
	if (len == 2)
		algo_action2(b);
	else if (len == 3)
	{
		if (b[2] == 'a')
			exe_rra();
		else if (b[2] == 'b')
			exe_rrb();
		else if (b[2] == 'r')
			exe_rrr();
	}
}

t_str	gnl(int *ans)
{
	t_str	str;
	char	c;
	int		r;

	str = ps_putstr();
	while (1)
	{
		r = read(0, &c, 1);
		if (r == -1)
		{
			ps_strdel(&str);
			free_ret(1);
		}
		if (c == '\n' || r == 0)
			break ;
		push_char(&str, c);
	}
	*ans = r;
	return (str);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_str	s;

	if (argc == 1)
		return (0);
	almost(argc, argv);
	while (1)
	{
		s = gnl(&i);
		if (i == 0)
			break ;
		if (!valid_line(s.len, is_null(s)))
		{
			ps_strdel(&s);
			free_ret(1);
		}
		algo_action(s.len, is_null(s));
		ps_strdel(&s);
	}
	ps_strdel(&s);
	if (valid_sort())
		print_char("OK\n");
	else
		print_char("KO\n");
	return (0);
}
