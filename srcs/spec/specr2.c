/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specr2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:37:30 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:37:30 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../push_swap.h"

int	read_init(char c)
{
	t_specz	*specz;

	specz = &parser()->specz;
	ps_strdel(&specz->scan);
	specz->scan = ps_putstr();
	push_char(&specz->scan, c);
	return (1);
}

char	read_all(void)
{
	char		ans;
	t_specz		*specz;

	specz = &parser()->specz;
	ans = reference();
	specz->sort_row = parser()->fr.row;
	specz->sort_col = parser()->fr.col;
	specz->sort_c = ans;
	return (ans);
}

void	read_push_char(char c)
{
	push_char(&parser()->specz.scan, c);
}

int	read_next(void)
{
	return (read_init(read_all()));
}
