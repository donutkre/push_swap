/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:25:03 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:25:03 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ps_ltoi(t_str str)
{
	const char	*s;
	t_un		i;
	int			neg;
	long		ans;

	ans = 0;
	neg = 1;
	s = is_null(str);
	i = 0;
	if (s[0] == '-')
	{
		neg = -1;
		i = 1;
	}
	while (i < str.len)
	{
		ans = ans * 10 + (s[i] - '0');
		i++;
	}
	return (ans * neg);
}

double	ps_lltoi(t_str str)
{
	(void)str;
	return (0.0);
}

long	ps_itoa(const char *s)
{
	t_un	i;
	int		neg;
	long	ans;
	long	trans;

	ans = 0;
	neg = 1;
	i = 0;
	if (s[0] == '-')
	{
		neg = -1;
		i = 1;
	}
	while (s[i])
	{
		trans = ans * 10 + (s[i] - '0');
		if (trans > INT_MAX || trans * neg < INT_MIN)
			free_ret(1);
		ans = trans;
		i++;
	}
	return (ans * neg);
}

int	conv_nb(void)
{
	t_spec	spec;
	long	num;

	while (1)
	{
		spec = next_spec();
		if (spec.type == NL)
			continue ;
		else if (spec.type == INT)
		{
			num = ps_ltoi(spec.str);
			new_stack(&run()->b, num);
			if (num < INT_MIN || num > INT_MAX)
				return (0);
		}
		else if (spec.type == END)
			break ;
		else
			conv_error();
	}
	return (1);
}

void	conv_error(void)
{
	doneconv();
	free_ret(1);
}
