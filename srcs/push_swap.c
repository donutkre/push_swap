/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:39:22 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:39:22 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	almost(argc, argv);
	run()->call_op = 1;
	if (valid_sort())
		free_ret(0);
	process_a_stack(run()->a.len, LONG_MIN, LONG_MAX);
	execute_op();
	free_ret(0);
	return (0);
}
