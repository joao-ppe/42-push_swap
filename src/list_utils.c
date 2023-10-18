/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:59:30 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/10/11 15:30:47 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_node_end(t_stack **list, t_stack *new_node)
{
	t_stack	*last;

	if (!list || !new_node)
		return ;
	if (*list)
	{
		last = last_node(*list);
		new_node->prev = last;
		new_node->next = NULL;
		last->next = new_node;
	}
	else
	{
		*list = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
}

t_stack	*last_node(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

t_stack	*first_node(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list->prev != NULL)
		list = list->prev;
	return (list);
}
