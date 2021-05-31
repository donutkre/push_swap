/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:21:55 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:21:55 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	not_zero(char c)
{
	return (c >= '1' && c <= '9');
}

int	ps_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_lst(char c)
{
	return (ps_alpha(c) || util1(c, "_"));
}

int	util1(char c, const char *list)
{
	int	i;

	i = 0;
	while (list[i] != '\0')
	{
		if (list[i] == c)
			return (1);
		i++;
	}
	return (0);
}
