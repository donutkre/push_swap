/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:37:24 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:37:24 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../push_swap.h"

void	spec_init(void)
{
	char	c;

	c = read_all();
	push_char(&parser()->specz.scan, c);
}

t_specz	specz_create(void)
{
	t_specz	specz;

	specz.current_spec = spec_create();
	specz.scan = ps_putstr();
	return (specz);
}

t_spec	spec_create(void)
{
	t_spec	ttt;

	ttt.str = ps_putstr();
	ttt.type = UNSPECIFIED;
	ttt.file_col = 0;
	ttt.file_row = 0;
	return (ttt);
}

void	spec_use(void)
{
	t_specz	*specz;

	specz = &parser()->specz;
	if (specz->current_spec.type == END)
		return ;
	skip_emp();
	specz->current_spec.file_col = parser()->fr.col;
	specz->current_spec.file_row = parser()->fr.row;
	if (spec_num())
		return ;
	if (spec_name())
		return ;
	if (spec_end())
		return ;
	if (spec_newl())
		return ;
	if (spec_comma())
		return ;
	spec_del();
}

t_spec	spec_next(void)
{
	t_specz	*specz;

	specz = &parser()->specz;
	if (specz->current_spec.type == UNSPECIFIED)
		spec_use();
	return (specz->current_spec);
}
