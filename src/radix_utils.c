/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:38:32 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/10/16 18:16:34 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	**duplicate_stack(t_stack **a)
{
	t_stack	**dup;
	t_stack	*head;
	t_stack	*node;

	head = *a;
	dup = (t_stack **)malloc(sizeof(t_stack *));
	if (!dup)
		return (NULL);
	*dup = NULL;
	while (head != NULL)
	{
		node = create_node((head->value));
		if (*dup == NULL)
			*dup = node;
		else
			add_node_end(dup, node);
		head = head->next;
	}
	return (dup);
}

void	sort_dup_stack(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (!is_sorted(stack))
	{
		while (head->next != NULL)
		{
			if (head->value > head->next->value)
				swap_nodes(head);
			head = head->next;
		}
		head = *stack;
	}
}

void	index_stack(t_stack **stack)
{
	t_stack	**dup;

	dup = duplicate_stack(stack);
	sort_dup_stack(dup);
	index_nodes(stack, dup);
	free_stack(dup);
	free(dup);
}

void	index_nodes(t_stack **stack, t_stack **dup)
{
	t_stack	*head;
	t_stack	*head_dup;
	int		i;

	i = 0;
	head_dup = *dup;
	while (head_dup != NULL)
	{
		head = *stack;
		while (head != NULL)
		{
			if (head->value == head_dup->value)
			{
				head->index = i;
				break ;
			}
			head = head->next;
		}
		i++;
		head_dup = head_dup->next;
	}
}

void	swap_nodes(t_stack *node)
{
	int	aux;

	if (node == NULL || node->next == NULL)
		return ;
	aux = node->value;
	node->value = node->next->value;
	node->next->value = aux;
}
