/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:01:07 by joao-ppe          #+#    #+#             */
/*   Updated: 2024/01/17 16:07:12 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	operation(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp("pa", op, 3))
		push(a, b);
	else if (!ft_strncmp("pb", op, 3))
		push(b, a);
	else if (!ft_strncmp("sa", op, 3))
		swap(a);
	else if (!ft_strncmp("sb", op, 3))
		swap(b);
	else if (!ft_strncmp("ss", op, 3))
		other_operations(a, b, op);
	else if (!ft_strncmp("ra", op, 3))
		rotate(a);
	else if (!ft_strncmp("rb", op, 3))
		rotate(b);
	else if (!ft_strncmp("rr", op, 3))
		other_operations(a, b, op);
	else if (!ft_strncmp("rra", op, 4))
		reverse_rotate(a);
	else if (!ft_strncmp("rrb", op, 4))
		reverse_rotate(b);
	else if (!ft_strncmp("rrr", op, 4))
		other_operations(a, b, op);
	ft_printf("%s\n", op);
}

t_stack	*biggest_node(t_stack **stack)
{
	t_stack	*head;
	t_stack	*biggest;

	head = *stack;
	biggest = head;
	while (head != NULL)
	{
		if (biggest->value < head->value)
			biggest = head;
		head = head->next;
	}
	return (biggest);
}

t_stack	*smallest_node(t_stack **stack)
{
	t_stack	*head;
	t_stack	*smallest;

	head = *stack;
	smallest = head;
	while (head != NULL)
	{
		if (smallest->value > head->value)
			smallest = head;
		head = head->next;
	}
	return (smallest);
}
