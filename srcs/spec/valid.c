/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:37:54 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 11:37:54 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
t_str	valid_type(t_spect type)
{
	t_spec	spec;

	spec = next_spec();
	if (spec.type != type)
		conv_type_del(type);
	return (spec.str);
}

long	valid_int(long min, long max)
{
	t_str	str;
	long	r;

	str = valid_type(INT);
	r = ps_ltoi(str);
	if (r < min || r > max)
		conv_range_del((double)min, (double)max);
	return (r);
}

double	valid_num_range(double min, double max)
{
	double	num;

	num = valid_num();
	if (num < min || num > max)
		conv_range_del(min, max);
	return (num);
}

double	valid_num(void)
{
	t_spec	spec;
	double	num;

	spec = next_spec();
	if (spec.type != DOUBLE && spec.type != INT)
		conv_del("expected number", 104);
	if (spec.type == DOUBLE)
		num = (ps_lltoi(spec.str));
	else
		num = (double)(ps_ltoi(spec.str));
	return (num);
}

void	almost(int argc, char *argv[])
{
	long	i;
	long	len;

	if (argc == 2)
		single_argc(argv[1]);
	else if (argc >= 3)
		argcs(argc, argv);
	i = -1;
	len = run()->b.len;
	while (++i < len)
		stack_move(&run()->a, &run()->b);
	sorted_a_arr();
	if (sorted_arr(run()->arr))
		free_ret(1);
}
