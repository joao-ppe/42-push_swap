/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:26:40 by joao-ppe          #+#    #+#             */
/*   Updated: 2023/10/16 17:33:33 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}

int	count_nodes(t_stack **stack)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

char	**split_args(int argc, char **argv)
{
	char	**args;

	args = NULL;
	if (argc == 2)
		args = ft_split(argv[0], 32);
	else if (argc > 2)
		args = argv;
	if (!args || check_args(args)
		|| count_args(args) < 2)
	{
		ft_printf("Error: Invalid argument(s).\n");
		return (NULL);
	}
	return (args);
}

void	init_stack(t_stack **stack, char **args, int argc)
{
	int		size;
	int		i;

	(void)argc;
	size = count_args(args);
	i = -1;
	if (!args)
		return ;
	while (++i < size)
		push_stack(ft_atoi(args[i]), stack);
	if (argc == 2)
		free_array(args);
}

void	push_stack(int value, t_stack **stack)
{
	t_stack	*node;

	node = create_node((value));
	if (*stack == NULL)
		*stack = node;
	else
		add_node_end(stack, node);
}
