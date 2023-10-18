/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:17:20 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/10/16 16:55:25 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head != NULL)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	t_stack	*head;
	int		max_bits;
	int		size;
	int		i;
	int		j;

	index_stack(a);
	max_bits = get_max_bits(a);
	size = count_nodes(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head = *a;
			if (((head->index >> i) & 1) == 1)
				operation(a, NULL, "ra");
			else
				operation(a, b, "pb");
		}
		while (count_nodes(b) != 0)
			operation(a, b, "pa");
		i++;
	}
}
