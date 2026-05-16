/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 21:47:16 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/16 21:53:38 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		init_stack(t_stack *stack, int size);
static t_config	split_args(
					int argc, char *argv[argc], char ***arr, int *size);
static int		str_to_tuple(
					int index, t_stack *stack, t_tuple **tuple, void *arr);
static void		manage_adaptive_mode(t_config *config);

t_config	init_app(
	t_stack *stack_a,
	t_stack *stack_b,
	int argc,
	char *argv[argc])
{
	t_config	config;
	char		**arr;
	int			size;

	config = split_args(argc, argv, &arr, &size);
	if (!config.is_valid)
		return (config);
	config.is_valid = init_stack(stack_a, size) != ERROR
		&& init_stack(stack_b, size) != ERROR
		&& ft_foreach_stack(stack_a, str_to_tuple, arr) != ERROR;
	if (!config.is_valid)
	{
		clean_stack(stack_a);
		clean_stack(stack_b);
		return (config);
	}
	config.disorder = ft_disorder(*stack_a);
	stack_b->size = 0;
	stack_b->end = 0;
	manage_adaptive_mode(&config);
	return (config);
}

static t_config	split_args(
	int argc, char *argv[argc], char ***arr, int *size)
{
	t_config	config;
	int			i;

	i = 0;
	config.is_valid = TRUE;
	if (!ft_strcmp(argv[i], "--bench") && ++i)
		config.is_bench_mode = TRUE;
	if (!ft_strcmp(argv[i], "--simple") && ++i)
		config.mode = SIMPLE;
	else if (!ft_strcmp(argv[i], "--medium") && ++i)
		config.mode = MEDIUM;
	else if (!ft_strcmp(argv[i], "--complex") && ++i)
		config.mode = COMPLEX;
	else if (!ft_strcmp(argv[i], "--adaptive") && ++i)
		config.mode = ADAPTIVE;
	else
		config.mode = ADAPTIVE;
	*arr = NULL;
	while (argc - i)
	{
		set_arr(arr, join_arr(*arr, ft_split(argv[i], ' ')));
		i++;
	}
	*size = ft_arr_len(*arr);
	return (config);
}

static int	init_stack(t_stack *stack, int size)
{
	stack->array = malloc(size * sizeof(t_tuple *));
	if (stack->array == NULL)
		return (ERROR);
	stack->size = size;
	stack->start = 0;
	stack->end = size - 1;
	stack->max_size = size;
	while (size--)
		stack->array[size] = NULL;
	return (1);
}

static void	manage_adaptive_mode(t_config *config)
{
	if (!config->is_bench_mode)
		ft_log_ops(TRUE);
	if (config->mode == ADAPTIVE || config->is_bench_mode)
		ft_printf("disorder = %d %", 100 * ((int)config->disorder));
	if (config->mode == ADAPTIVE)
	{
		if (config->disorder < 0.2)
			config->mode = SIMPLE;
		else if (config->disorder < 0.5)
			config->mode = MEDIUM;
		else
			config->mode = COMPLEX;
	}
}

static int	str_to_tuple(int index, t_stack *stack, t_tuple **tuple, void *arr)
{
	int			i;
	char		*str;

	i = 0;
	str = ((char **)arr)[index];
	*tuple = malloc(sizeof(t_tuple));
	if (*tuple == NULL && stack)
		return (ERROR);
	(*tuple)->rank = 0;
	if (ft_str_to_int32(str, &((*tuple)->value)) == ERROR)
	{
		free(*tuple);
		*tuple = NULL;
		return (ERROR);
	}
	return (0);
}
