/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:24:48 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:24:48 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

const char	*is_null(t_str str)
{
	str.ptr[str.len] = '\0';
	return (str.ptr);
}

void	allocate_str(t_str *str, t_str other)
{
	t_str	tmp;

	tmp = ps_strjoin(other);
	ps_strdel(str);
	*str = tmp;
}

void	allocate_char(t_str *str, const char *raw)
{
	ps_strdel(str);
	*str = newstr(raw);
}

t_str	newstr(const char *raw)
{
	t_str	str;
	int		i;

	str = ps_putstr();
	i = 0;
	while (raw[i] != '\0')
	{
		push_char(&str, raw[i]);
		i++;
	}
	return (str);
}

int	ps_num(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
