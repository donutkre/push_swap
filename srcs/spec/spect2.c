/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spect2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:37:46 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:37:46 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	spec_int(void)
{
	char	c;

	c = is_null(parser()->specz.scan)[0];
	if (c == '0')
		return (validate_s_init(INT));
	if (c == '-')
	{
		c = read_all();
		read_push_char(c);
	}
	if (not_zero(c))
	{
		while (1)
		{
			c = read_all();
			if (!ps_digit(c))
				break ;
			read_push_char(c);
		}
		return (validate_s(INT, c));
	}
	else if (c == '0')
		return (validate_s_init(INT));
	return (0);
}

int	loop_d(char c)
{
	t_str	tmp;
	t_specz	*specz;

	specz = &parser()->specz;
	read_push_char(c);
	while (1)
	{
		c = read_all();
		if (!ps_digit(c))
			break ;
		read_push_char(c);
	}
	tmp = ps_strjoin(specz->current_spec.str);
	ps_strcpy(&tmp, specz->scan);
	validate_svalue(DOUBLE, c, tmp);
	ps_strdel(&tmp);
	return (1);
}

void	skip_emp(void)
{
	char		c;

	c = is_null(parser()->specz.scan)[0];
	if (c == ' ')
	{
		while (1)
		{
			c = read_all();
			if (c != ' ')
				break ;
		}
	}
	read_init(c);
}

int	single_argc(char *a1)
{
	run()->input = a1;
	if (!parse_single())
		free_ret(1);
	return (0);
}

int	argcs(int argc, char *argv[])
{
	long	i;
	long	num;

	i = 1;
	while (i < argc)
	{
		if (!ps_num(argv[i]))
			free_ret(1);
		num = ps_itoa(argv[i]);
		if (num >= INT_MAX)
			free_ret(1);
		new_stack(&run()->b, ps_itoa(argv[i]));
		i++;
	}
	return (0);
}
