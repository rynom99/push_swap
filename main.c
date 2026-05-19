/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:34:53 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/19 17:47:34 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_bench(t_config *cfg);

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
	if (!config.disorder)
		(void)0;
	else if (config.mode == SIMPLE
		|| (config.mode == ADAPTIVE && config.disorder < 0.2))
		simple_algorithm(&stack_a, &stack_b);
	else if (config.mode == MEDIUM
		|| (config.mode == ADAPTIVE && config.disorder < 0.5))
		medium_algorithm(&stack_a, &stack_b);
	else if (config.mode == COMPLEX || config.mode == ADAPTIVE)
		complex_algorithm(&stack_a, &stack_b);
	if (config.is_bench_mode)
		print_bench(&config);
	return (0);
}

static char	*get_strategy(t_config *cfg)
{
	if (cfg->mode == SIMPLE)
		return ("Simple / O(n2)");
	else if (cfg->mode == MEDIUM)
		return ("Medium / O(n√n)");
	else if (cfg->mode == COMPLEX)
		return ("Complex / O(nlogn)");
	else if (cfg->mode == ADAPTIVE)
	{
		if (cfg->disorder < 0.2)
			return ("Adaptive / O(n2)");
		else if (cfg->disorder < 0.5)
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(nlogn)");
	}
	return ("");
}

static void	print_bench(t_config *cfg)
{
	ft_printf("[bench] disorder:	%i.%i%i%%\n", (int)(cfg->disorder * 100), (((int)(cfg->disorder * 10000) % 100) / 10),((int)(cfg->disorder * 10000) % 10));
	ft_printf("[bench] strategy:	%s\n", get_strategy(cfg));
	ft_printf("[bench] total_ops:	%i\n",
		sa(NULL) + sb(NULL) + ss(NULL, NULL) + pa(NULL, NULL) + pb(NULL, NULL)
		+ ra(NULL) + rb(NULL) + rr(NULL, NULL) + rrb(NULL) + rrr(NULL, NULL));
	ft_printf("[bench] sa:	%i	sb:	%i	ss:	%i	pa:	%i	pb:	%i\n",
		sa(NULL), sb(NULL), ss(NULL, NULL), pa(NULL, NULL), pb(NULL, NULL));
	ft_printf("[bench] ra:	%i	rb:	%i	rr:	%i	rrb:	%i	rrr:	%i\n",
		ra(NULL), rb(NULL), rr(NULL, NULL), rrb(NULL), rrr(NULL, NULL));
}
