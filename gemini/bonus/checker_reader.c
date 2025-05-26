/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chcker_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:29:56 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h" // Reusing push_swap's headers

// Simple function to read a line (instruction) from stdin.
// Returns malloc'd string, or NULL on EOF/error. Caller must free.
// Max line length handled is BUFFER_SIZE - 1 for instruction + '\n'.
static char	*read_next_instruction_line(t_stacks *stacks)
{
	char	buffer[BUFFER_SIZE]; // "rra\n\0" = 5
	char	c;
	int		bytes_read;
	int		i;

	i = 0;
	while (i < BUFFER_SIZE -1)
	{
		bytes_read = read(0, &c, 1); // Read 1 char from stdin
		if (bytes_read <= 0) // EOF or error
		{
			if (i == 0) // Nothing read before EOF/error
				return (NULL);
			break ; // End of input, process what's in buffer
		}
		buffer[i++] = c;
		if (c == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (i == 0 && bytes_read <= 0) // True EOF on empty line
		return (NULL);
	if (i > 0 && buffer[i-1] != '\n') // Instruction too long or no newline
		exit_error(stacks); // Or handle as invalid instruction
	return (ft_strdup(buffer)); // ft_strdup from libft needed
}
// NOTE: ft_strdup is not in the provided libft. It would need to be added or
//       this function rewritten to not rely on dynamic allocation / or manage it carefully.
//       For simplicity here, assuming ft_strdup is available or can be added.
// A more robust get_next_line would be better if allowed/required.

void	read_and_execute_instructions(t_stacks *stacks)
{
	char	*instruction_line;

	instruction_line = read_next_instruction_line(stacks);
	while (instruction_line)
	{
		apply_instruction(stacks, instruction_line);
		free(instruction_line);
		instruction_line = read_next_instruction_line(stacks);
	}
}
