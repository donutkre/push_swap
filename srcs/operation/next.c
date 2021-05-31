/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:36:22 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:36:22 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../push_swap.h"

void	char_error(const char *c)
{
	long	len;

	len = 0;
	while (c[len])
		len++;
	write(2, c, len);
}

void	doneconv(void)
{
	ret0();
	ps_strdel(&parser()->specz.scan);
	ps_strdel(&parser()->specz.current_spec.str);
}

t_con	*parser(void)
{
	static t_con	p;

	return (&p);
}

t_spec	next_spec(void)
{
	spec_use();
	return (spec_next());
}
