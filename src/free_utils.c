/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:44:15 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/10/16 18:02:29 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_all(t_stack **a, t_stack **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}

void	free_stack(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*head;

	head = *stack;
	if (!stack)
		return ;
	while (head)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
