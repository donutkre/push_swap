/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spect.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:37:40 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:37:40 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	spec_end(void)
{
	char	c;

	c = is_null(parser()->specz.scan)[0];
	if (c == '\0')
		return (validate_s_init(END));
	return (0);
}

int	spec_newl(void)
{
	char	c;

	c = is_null(parser()->specz.scan)[0];
	if (c == '\n')
		return (validate_s_init(NL));
	return (0);
}

int	spec_comma(void)
{
	char	c;

	c = is_null(parser()->specz.scan)[0];
	if (c == ',')
		return (validate_s_init(COM));
	return (0);
}

int	spec_num(void)
{
	char	c;

	if (!spec_int())
		return (0);
	c = is_null(parser()->specz.scan)[0];
	if (c != '.')
		return (read_init(c));
	c = read_all();
	if (ps_digit(c))
		return (loop_d(c));
	else
		return (0);
}

int	spec_name(void)
{
	char	c;

	c = is_null(parser()->specz.scan)[0];
	if (is_lst(c))
	{
		while (1)
		{
			c = read_all();
			if (!is_lst(c))
				break ;
			read_push_char(c);
		}
		return (validate_s(NAME, c));
	}
	return (0);
}
