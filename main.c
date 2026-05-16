/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:34:53 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/16 18:03:28 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[argc])
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_config	config;

	if (argc < 2)
		return (0);
	config = init_app(&stack_a, &stack_b, argc - 1, argv + 1);
	if (!config.is_valid)
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	print_stack(stack_a, stack_b);
	if (config.mode == SIMPLE)
		simple_algorithm(&config, &stack_a, &stack_b);
	else if (config.mode == MEDIUM)
		medium_algorithm(&config, &stack_a, &stack_b);
	else if (config.mode == COMPLEX)
		medium_algorithm(&config, &stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	return (0);
}
