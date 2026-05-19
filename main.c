/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:34:53 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/19 22:59:49 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stack(t_stack *stack);
static void	print_bench(t_config *cfg);
static void	apply_algorithm(t_config *cfg, t_stack *stack_a, t_stack *stack_b);

int	main(int argc, char *argv[argc])
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_config	config;

	if (argc < 2)
		return (0);
	init_stack(&stack_a);
	init_stack(&stack_b);
	config = init_app(&stack_a, &stack_b, argc - 1, argv + 1);
	if (!config.is_valid)
	{
		clean_stack(&stack_a);
		clean_stack(&stack_b);
		ft_printf("Error\n");
		return (ERROR);
	}
	apply_algorithm(&config, &stack_a, &stack_b);
	if (config.is_bench_mode)
		print_bench(&config);
	clean_stack(&stack_a);
	clean_stack(&stack_b);
	return (0);
}

static int	init_stack(t_stack *stack)
{
	stack->array = NULL;
	stack->start = 0;
	stack->end = 0;
	stack->size = 0;
	stack->max_size = 0;
	return (SUCCESS);
}

static void	apply_algorithm(t_config *cfg, t_stack *stack_a, t_stack *stack_b)
{
	if (!cfg->disorder)
		(void)0;
	else if (cfg->mode == SIMPLE
		|| (cfg->mode == ADAPTIVE && cfg->disorder < 0.2))
		simple_algorithm(stack_a, stack_b);
	else if (cfg->mode == MEDIUM
		|| (cfg->mode == ADAPTIVE && cfg->disorder < 0.3))
		medium_algorithm(stack_a, stack_b);
	else if (cfg->mode == COMPLEX || cfg->mode == ADAPTIVE)
		complex_algorithm(stack_a, stack_b);
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
		else if (cfg->disorder < 0.3)
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(nlogn)");
	}
	return ("");
}

static void	print_bench(t_config *cfg)
{
	ft_printf("[bench] disorder:	%i.%i%i%%\n", (int)(cfg->disorder * 100),
		(((int)(cfg->disorder * 10000) % 100) / 10),
		((int)(cfg->disorder * 10000) % 10));
	ft_printf("[bench] strategy:	%s\n", get_strategy(cfg));
	ft_printf("[bench] total_ops:	%i\n",
		sa(NULL) + sb(NULL) + ss(NULL, NULL) + pa(NULL, NULL) + pb(NULL, NULL)
		+ ra(NULL) + rb(NULL) + rr(NULL, NULL) + rrb(NULL) + rrr(NULL, NULL));
	ft_printf("[bench] sa:	%i	sb:	%i	ss:	%i	pa:	%i	pb:	%i\n",
		sa(NULL), sb(NULL), ss(NULL, NULL), pa(NULL, NULL), pb(NULL, NULL));
	ft_printf("[bench] ra:	%i	rb:	%i	rr:	%i	rrb:	%i	rrr:	%i\n",
		ra(NULL), rb(NULL), rr(NULL, NULL), rrb(NULL), rrr(NULL, NULL));
}
