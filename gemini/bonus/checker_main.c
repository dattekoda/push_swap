/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:00:00 by normok            #+#    #+#             */
/*   Updated: 2025/05/26 15:17:43 by khanadat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h" // Reusing push_swap's headers

// Checker does not print operations, so the 'print' flag is false.
// Stack operations (sa, pb, etc.) must be callable with print=false.

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	init_stacks(&stacks);
	parse_arguments(argc, argv, &stacks); // Reuse parsing
	validate_duplicates(&stacks);       // Reuse validation
	read_and_execute_instructions(&stacks);
	if (is_sorted(stacks.a) && stacks.size_b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stacks_and_exit(&stacks, 0);
	return (0);
}
