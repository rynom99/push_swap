/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:34:53 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/16 19:50:23 by mnououal         ###   ########.fr       */
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
	if (config.mode == SIMPLE && config.disorder)
		simple_algorithm(&stack_a, &stack_b);
	else if (config.mode == MEDIUM && config.disorder)
		medium_algorithm(&stack_a, &stack_b);
	else if (config.mode == COMPLEX && config.disorder)
		medium_algorithm(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	return (0);
}
