/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:34:06 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	apply_swap_push(t_stacks *stacks, char *instr_no_nl)
{
	if (ft_strcmp(instr_no_nl, "sa") == 0)
		sa(stacks, false);
	else if (ft_strcmp(instr_no_nl, "sb") == 0)
		sb(stacks, false);
	else if (ft_strcmp(instr_no_nl, "ss") == 0)
		ss(stacks, false);
	else if (ft_strcmp(instr_no_nl, "pa") == 0)
		pa(stacks, false);
	else if (ft_strcmp(instr_no_nl, "pb") == 0)
		pb(stacks, false);
	else
		exit_error(stacks); // Invalid instruction
}

static void	apply_rotate_rev_rotate(t_stacks *stacks, char *instr_no_nl)
{
	if (ft_strcmp(instr_no_nl, "ra") == 0)
		ra(stacks, false);
	else if (ft_strcmp(instr_no_nl, "rb") == 0)
		rb(stacks, false);
	else if (ft_strcmp(instr_no_nl, "rr") == 0)
		rr(stacks, false);
	else if (ft_strcmp(instr_no_nl, "rra") == 0)
		rra(stacks, false);
	else if (ft_strcmp(instr_no_nl, "rrb") == 0)
		rrb(stacks, false);
	else if (ft_strcmp(instr_no_nl, "rrr") == 0)
		rrr(stacks, false);
	else
		apply_swap_push(stacks, instr_no_nl); // Check other group
}

// instruction_line includes the newline from read_next_instruction_line
void	apply_instruction(t_stacks *stacks, char *instruction_line)
{
	size_t	len;

	if (!instruction_line || instruction_line[0] == '\0')
		exit_error(stacks); // Empty line is an error here
	len = ft_strlen(instruction_line);
	if (len > 0 && instruction_line[len - 1] == '\n')
		instruction_line[len - 1] = '\0'; // Remove newline for ft_strcmp
	else // No newline, might be an error or last line without newline
		exit_error(stacks); // Strict: instructions must end with \n
	apply_rotate_rev_rotate(stacks, instruction_line);
}
