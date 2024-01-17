/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:49:46 by joao-ppe          #+#    #+#             */
/*   Updated: 2024/01/17 14:14:35 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_args(char **args)
{
	if (!args || check_elements(args))
		return (1);
	return (0);
}

int	check_elements(char **args)
{
	int		i;
	int		j;

	i = -1;
	while (args[++i] != NULL)
	{
		j = -1;
		while (args[i][++j] != '\0')
		{
			if (args[i][j] == '+' || args[i][j] == '-')
				j++;
			if (!ft_isdigit(args[i][j]))
				return (1);
		}
		if ((ft_atol(args[i]) > INT_MAX
				|| ft_atol(args[i]) < INT_MIN)
			|| check_repetition(args, args[i], i))
			return (1);
	}
	return (0);
}

int	check_repetition(char **args, char *value, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	if (args == NULL)
		return (0);
	while (i < n)
	{
		if (ft_atoi(value) == ft_atoi(args[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*head;
	int		n;
	int		i;

	i = 0;
	n = count_nodes(stack);
	head = *stack;
	while (i++ < n)
	{
		if (i != 1)
		{
			if (head->value < head->prev->value)
				return (0);
		}
		head = head->next;
	}
	return (1);
}
