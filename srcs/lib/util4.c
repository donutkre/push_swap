/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:24:54 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:24:54 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_str(t_str str)
{
	write(1, is_null(str), str.len);
}

void	push_long(t_str *str, long num)
{
	if (num < 0)
	{
		push_char(str, '-');
		num *= -1;
	}
	if (num >= 10)
		push_long(str, num / 10);
	push_char(str, (num % 10) + '0');
}

void	push_double(t_str *str, double num, unsigned int round)
{
	long			n;
	double			small;
	long			neg;
	unsigned int	i;

	neg = 1;
	if (num < 0)
		neg = -1;
	n = (long)num;
	small = (num - n) * neg;
	push_long(str, n);
	if (small > 0)
		push_char(str, '.');
	i = 0;
	while (small > 0)
	{
		small *= 10;
		n = (long)small;
		push_char(str, n + '0');
		small -= n;
		i++;
		if (i >= round)
			break ;
	}
}

void	push_chars(t_str *str, const char *s)
{
	t_un	i;

	i = 0;
	while (s[i])
	{
		push_char(str, s[i]);
		i++;
	}
}

void	push_char(t_str *str, char c)
{
	t_un	i;
	char	*nptr;

	str->ptr[str->len] = c;
	str->len += 1;
	if (str->len > str->max / 2)
	{
		str->max *= 2;
		nptr = (char *)malloc(sizeof(char) * str->max);
		if (!nptr)
			exit(106);
		i = 0;
		while (i < str->len)
		{
			nptr[i] = str->ptr[i];
			i++;
		}
		free(str->ptr);
		str->ptr = nptr;
	}
}
