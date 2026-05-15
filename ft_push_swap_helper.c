/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 21:47:16 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/15 15:59:48 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		init_stack(t_stack *stack, int size);
static t_config	split_args(
					int argc, char *argv[argc], char ***arr, int *size);
static int		str_to_tuple(int index, t_tuple **tuple, void *arr);
static void		manage_adaptive_mode(t_config *config, t_stack *a);

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
	if (!(init_stack(stack_a, size) != ERROR
		&& init_stack(stack_b, size) != ERROR
		&& ft_foreach_stack(stack_a, str_to_tuple, arr) != ERROR))
	{
		free(stack_a->array);
		if (stack_a->array != NULL)
			free(stack_b->array);
		config.is_valid = FALSE;
		return (config);
	}
	stack_b->size = 0;
	stack_b->end = 0;
	manage_adaptive_mode(&config, stack_a);
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
	*size = 0;
	while (*(*arr + *size))
		*size = *size + 1;
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
	return (1);
}

static void	manage_adaptive_mode(t_config *config, t_stack *a)
{
	float		disorder;

	disorder = ft_disorder(*a);
	if (config->mode == ADAPTIVE || config->is_bench_mode)
		ft_printf("disorder = %d %", 100 * disorder);
	if (config->mode == ADAPTIVE)
	{
		if (disorder == 0)
			config->mode = DUMB;
		else if (disorder < 0.2)
			config->mode = SIMPLE;
		else if (disorder < 0.5)
			config->mode = MEDIUM;
		else
			config->mode = COMPLEX;
	}
}

static int	str_to_tuple(int index, t_tuple **tuple, void *arr)
{
	int			i;
	char		*str;

	i = 0;
	str = ((char **)arr)[index];
	*tuple = malloc(sizeof(t_tuple));
	if (*tuple == NULL)
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
