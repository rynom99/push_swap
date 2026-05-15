/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:34:53 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/15 17:04:49 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[argc])
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	if (argc < 2)
		return (0);
	config = init_app(&a, &b, argc - 1, argv + 1);
	if (!config.is_valid)
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	print_stack(a, b);
	if (config.mode == SIMPLE)
		simple_algorithem(&a, &b);
	else if (config.mode == MEDIUM)
		medium_algo(&a, &b);
	else if (config.mode == COMPLEX)
	{
		case3(&a);
	}
	print_stack(a, b);
	return (0);
}
