/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:25:19 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/10/16 16:50:41 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// CASES TO CHECK: 2, 3, 4, 5, 100, 500

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc >= 2 && argv[1][0])
	{
		init_stack(&a, split_args(argc, argv + 1), argc);
		if (a == NULL)
		{
			free_all(&a, &b);
			return (1);
		}
		if (!is_sorted(&a))
			sort_stack(&a, &b, count_nodes(&a));
	}
	else
		write(1, "\n", 1);
	free_all(&a, &b);
	return (0);
}
