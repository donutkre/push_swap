/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:24:33 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:24:33 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_str	ps_putstr(void)
{
	t_str	str;

	str.len = 0;
	str.max = 10;
	str.ptr = (char *)malloc(sizeof(char) * 10);
	if (!str.ptr)
		exit(105);
	return (str);
}

t_str	ps_strjoin(t_str str)
{
	t_str	ns;
	t_un	i;

	ns.max = str.max;
	ns.len = str.len;
	ns.ptr = (char *)malloc(sizeof(char) * str.max);
	if (!ns.ptr)
		exit(105);
	i = 0;
	while (i < str.len)
	{
		(ns.ptr)[i] = (str.ptr)[i];
		i++;
	}
	return (ns);
}

void	ps_strcpy(t_str *target, t_str source)
{
	t_un		i;
	const char	*rs;

	rs = is_null(source);
	i = 0;
	while (i < source.len)
	{
		push_char(target, rs[i]);
		i++;
	}
}

t_str	ps_strjoin_num(t_str str, t_un start, t_un end)
{
	t_str		ns;
	t_un		i;
	t_un		bb;
	const char	*tr;

	tr = is_null(str);
	bb = end;
	if (bb > str.len)
		bb = str.len;
	i = start;
	ns = ps_putstr();
	while (i < bb)
	{
		push_char(&ns, tr[i]);
		i++;
	}
	return (ns);
}

void	ps_strdel(t_str *str)
{
	if (str->ptr)
		free(str->ptr);
	str->ptr = 0;
	str->len = 0;
	str->max = 0;
}
