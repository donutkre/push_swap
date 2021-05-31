/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:37:12 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:37:12 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../push_swap.h"

int	open_f(int *fd, const char *p)
{
	(void)fd;
	(void)p;
	return (0);
}

int	ret0(void)
{
	return (0);
}

t_fr	fr(const char *p)
{
	t_fr	fr;

	fr.path = p;
	fr.eof = 0;
	fr.file_len = 0;
	fr.pos = 100;
	fr.row = 1;
	fr.col = 0;
	fr.fd = -1;
	return (fr);
}

void	buff_read(t_fr *fr)
{
	int		r;
	int		i;

	fr->pos = 0;
	r = read(fr->fd, fr->buf, BUF_SIZE);
	if (r == -1)
		conv_del("Error occurred when reading", 101);
	if (r < BUF_SIZE)
	{
		fr->eof = 1;
		fr->file_len = r;
		i = r - 1;
		while (++i < BUF_SIZE)
			fr->buf[i] = '\0';
	}
}

int	safe(t_fr *fr)
{
	int	xx;

	if (fr->eof)
		xx = fr->file_len;
	else
		xx = BUF_SIZE;
	if (fr->eof && fr->pos >= xx)
		return (0);
	if (fr->pos >= xx)
		buff_read(fr);
	return (1);
}
