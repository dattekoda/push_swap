/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:12:45 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h" // Includes stdlib.h, unistd.h, limits.h
# include <stdbool.h>    // For bool type, if not using int

// Node structure for the stack
typedef struct s_node
{
	int				value;
	int				index; // Normalized index (0 to N-1)
	struct s_node	*next;
}	t_node;

// Main structure to hold both stacks and their sizes
typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
}	t_stacks;

// --- Error Handling ---
void	exit_error(t_stacks *stacks);
void	free_stacks_and_exit(t_stacks *stacks, int exit_code); // General exit

// --- Parsing ---
void	parse_arguments(int argc, char **argv, t_stacks *stacks);
void	validate_duplicates(t_stacks *stacks);

// --- Stack Initialization ---
t_node	*new_node(int value);
void	add_node_front(t_node **stack, t_node *node); // For building initial stack
void	add_node_to_list_back(t_node **stack, t_node *node);
void	init_stacks(t_stacks *stacks);

// --- Stack Utilities ---
int		get_stack_size(t_node *stack);
bool	is_sorted(t_node *stack);
void	free_stack_nodes(t_node **stack);
int		find_smallest_index_pos(t_node *stack);
int		get_node_value_at_pos(t_node *stack, int pos);


// --- Stack Operations ---
// sa, sb, ss
void	sa(t_stacks *stacks, bool print);
void	sb(t_stacks *stacks, bool print);
void	ss(t_stacks *stacks, bool print);
// pa, pb
void	pa(t_stacks *stacks, bool print);
void	pb(t_stacks *stacks, bool print);
// ra, rb, rr
void	ra(t_stacks *stacks, bool print);
void	rb(t_stacks *stacks, bool print);
void	rr(t_stacks *stacks, bool print);
// rra, rrb, rrr
void	rra(t_stacks *stacks, bool print);
void	rrb(t_stacks *stacks, bool print);
void	rrr(t_stacks *stacks, bool print);

// --- Sorting Algorithms ---
void	sort_logic(t_stacks *stacks);
// Small sorts
void	sort_three(t_stacks *stacks);
void	sort_four(t_stacks *stacks);
void	sort_five(t_stacks *stacks);
// Radix sort
void	assign_indexes(t_stacks *stacks);
void	radix_sort(t_stacks *stacks);

// --- Checker specific (bonus) ---
# define BUFFER_SIZE 5 // For reading instructions like "rra\n" + null
void	apply_instruction(t_stacks *stacks, char *instruction);
void	read_and_execute_instructions(t_stacks *stacks);


#endif
