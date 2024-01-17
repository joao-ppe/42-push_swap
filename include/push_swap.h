/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-ppe <joao-ppe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:20:39 by joao-ppe          #+#    #+#             */
/*   Updated: 2024/01/17 15:47:09 by joao-ppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*------------- Includes ---------------*/
# include "../libs/libft/libft.h"
# include <limits.h>

/*------------- Variables ---------------*/

/*------------- Structures ---------------*/
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				index;
}					t_stack;

/*------------- Functions ---------------*/
/// DEBUG ///
void		print_array(char **string);
void		print_stack(t_stack *stack, char *message);
void		print_links(t_stack *stack);
/// MAIN ///
int			main(int argc, char **argv);
/// UTILS ///
void		init_stack(t_stack **stack, char **args, int argc);
char		**split_args(int argc, char **argv);
int			count_args(char **args);
int			count_nodes(t_stack **stack);
void		push_stack(int value, t_stack **stack);
/// STACK/LIST UTILS ///
t_stack		*create_node(int value);
void		add_node_end(t_stack **list, t_stack *new_node);
t_stack		*last_node(t_stack *list);
t_stack		*first_node(t_stack *list);
/// VERIFICATIONS ///
int			check_args(char **args);
int			check_elements(char **args);
int			check_repetition(char **args, char *value, int n);
int			is_sorted(t_stack **a);
/// FREE UTILS ///
void		free_all(t_stack **a, t_stack **b);
void		free_stack(t_stack **stack);
/// OPERATIONS ///
void		push(t_stack **dest, t_stack **src);
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
void		other_operations(t_stack **a, t_stack **b, char *op);
/// ALGORITHM ///
void		sort_stack(t_stack **a, t_stack **b, int argc);
void		sort_3(t_stack **a);
void		sort_4(t_stack **a, t_stack **b);
void		sort_5(t_stack **a, t_stack **b);
/// ALGORITHM UTILS ///
void		operation(t_stack **a, t_stack **b, char *op);
t_stack		*biggest_node(t_stack **stack);
t_stack		*smallest_node(t_stack **stack);
/// RADIX ///
void		radix_sort(t_stack **a, t_stack **b);
int			get_max_bits(t_stack **stack);
/// RADIX UTILS ///
t_stack		**duplicate_stack(t_stack **a);
void		sort_dup_stack(t_stack **stack);
void		swap_nodes(t_stack *node);
void		index_stack(t_stack **stack);
void		index_nodes(t_stack **stack, t_stack **dup);

#endif