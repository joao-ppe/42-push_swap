/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:15:13 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/10/11 13:38:45 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*aux_src;

	if (*src == NULL)
		return ;
	aux_src = *src;
	*src = (*src)->next;
	aux_src->prev = NULL;
	aux_src->next = *dest;
	if (*dest != NULL)
		(*dest)->prev = aux_src;
	*dest = aux_src;
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	third = second->next;
	first->next = third;
	if (second->next != NULL)
		second->next->prev = first;
	if (first->prev != NULL)
		second->prev = first->prev;
	else
		second->prev = NULL;
	first->prev = second;
	first->next = third;
	second->next = first;
	*stack = second;
}

void	rotate(t_stack **stack)
{
	t_stack	*aux;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	aux = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	aux->next = NULL;
	aux->prev = last_node(*stack);
	add_node_end(stack, aux);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*penult;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	last = last_node(*stack);
	penult = last->prev;
	penult->next = NULL;
	last->next = head;
	head->prev = last;
	*stack = last;
	(*stack)->prev = NULL;
}

void	other_operations(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp("ss", op, 3))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strncmp("rr", op, 3))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp("rrr", op, 4))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}
