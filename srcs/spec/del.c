/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:37:07 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:37:07 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../push_swap.h"

void	conv_del(const char *c, int err)
{
	t_spec	spec;
	t_str	s;

	s = ps_putstr();
	spec = spec_next();
	push_chars(&s, c);
	push_chars(&s, ": '");
	push_chars(&s, is_null(spec.str));
	push_chars(&s, "' (");
	push_chars(&s, parser()->fr.path);
	push_char(&s, ':');
	push_long(&s, spec.file_row);
	push_char(&s, ':');
	push_long(&s, spec.file_col);
	push_chars(&s, ")\n");
	print_str(s);
	doneconv();
	ps_strdel(&s);
	if (parser()->error_hand)
		parser()->error_hand(parser()->argc_err);
	else
		exit(err);
}

void	conv_range_del(double min, double max)
{
	t_str	s;

	s = ps_putstr();
	push_chars(&s, "num must be >= ");
	push_double(&s, min, 1);
	push_chars(&s, ", <= ");
	push_double(&s, max, 1);
	conv_del(is_null(s), 104);
	ps_strdel(&s);
	if (parser()->error_hand)
		parser()->error_hand(parser()->argc_err);
	else
		exit(104);
}

void	conv_type_del(t_spect type)
{
	if (type == COM)
		conv_del("expected comma", 104);
	else if (type == DOUBLE)
		conv_del("expected double", 104);
	else if (type == INT)
		conv_del("expected integer", 104);
	else if (type == NAME)
		conv_del("expected name", 104);
	else if (type == NL)
		conv_del("expected newline", 104);
	else
		conv_del("unexpected token type", 104);
}

void	spec_del(void)
{
	t_str	s;
	t_specz	specz;

	specz = parser()->specz;
	s = ps_putstr();
	push_chars(&s, "Unexpected Token '");
	push_char(&s, specz.sort_c);
	push_chars(&s, "' at ");
	push_chars(&s, parser()->fr.path);
	push_char(&s, ':');
	push_long(&s, specz.sort_row);
	push_char(&s, ':');
	push_long(&s, specz.sort_col);
	push_char(&s, '\n');
	print_str(s);
	ps_strdel(&s);
	if (parser()->error_hand)
		parser()->error_hand(parser()->argc_err);
	else
		exit(107);
}

void	error_handle(void (*func)(void *), void *argc_err)
{
	parser()->error_hand = func;
	parser()->argc_err = argc_err;
}
