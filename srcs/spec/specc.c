/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:37:17 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:37:17 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	validate_svalue(t_spect type, char next, t_str value)
{
	t_specz	*specz;

	specz = &parser()->specz;
	specz->current_spec.type = type;
	allocate_str(&specz->current_spec.str, value);
	return (read_init(next));
}

int	validate_s(t_spect type, char next)
{
	return (validate_svalue(type, next, parser()->specz.scan));
}

int	validate_s_init(t_spect type)
{
	return (validate_s(type, read_all()));
}

t_fun	*run(void)
{
	static t_fun	c;

	return (&c);
}

int	parse_single(void)
{
	int	i;

	conv_fd_init(0, "stdin");
	i = conv_nb();
	doneconv();
	return (i);
}
