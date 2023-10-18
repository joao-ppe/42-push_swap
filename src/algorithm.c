/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:09:00 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/10/16 16:48:10 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	(void)b;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			rotate(a);
		ft_printf("ra");
		return ;
	}
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else if (size > 5)
		radix_sort(a, b);
}

void	sort_3(t_stack **a)
{
	t_stack	*biggest;

	biggest = biggest_node(a);
	while (!is_sorted(a))
	{
		if (biggest == *a)
			operation(a, NULL, "rra");
		else if (biggest == (*a)->next)
			operation(a, NULL, "rra");
		if ((*a)->value > (*a)->next->value)
			operation(a, NULL, "sa");
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*biggest;

	biggest = biggest_node(a);
	if (biggest == *a)
		operation(a, b, "pb");
	else if (biggest == (*a)->next)
	{
		operation(a, NULL, "sa");
		operation(a, b, "pb");
	}
	else if (biggest == last_node(*a))
	{
		operation(a, NULL, "rra");
		operation(a, b, "pb");
	}
	else
	{
		operation(a, NULL, "rra");
		operation(a, NULL, "rra");
		operation(a, b, "pb");
	}
	sort_3(a);
	operation(a, b, "pa");
	operation(a, NULL, "ra");
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*biggest;

	biggest = biggest_node(a);
	if (biggest == *a)
		operation(a, b, "pb");
	else if (biggest == (*a)->next)
	{
		operation(a, NULL, "sa");
		operation(a, b, "pb");
	}
	else if (biggest == last_node(*a))
	{
		operation(a, NULL, "rra");
		operation(a, b, "pb");
	}
	else
	{
		operation(a, NULL, "rra");
		operation(a, NULL, "rra");
		operation(a, b, "pb");
	}
	sort_4(a, b);
	operation(a, b, "pa");
	operation(a, NULL, "ra");
}
