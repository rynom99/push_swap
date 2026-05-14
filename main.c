/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:34:53 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/14 23:56:52 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_config	init(t_stack *a, t_stack *b, int argc, char *argv[argc]);
static t_config	split_args(
					int argc, char *argv[argc], char ***arr, int *size);
static void		set_arr(char ***str, char **value);
static char		**join_arr(
					char **arr1, char **arr2, int size_arr1, int size_arr2);
static int		str_to_tuple(int index, t_tuple **tuple, void *arr);


int fn(int a, t_tuple** tuple, void *extra)
{
	if(extra || 1)
		ft_printf("{[%d]-> %d}, ", a, (*tuple)->value);
	return (1);
}

void print_stack(t_stack stack_a, t_stack stack_b)
{
	ft_printf("\n--------------\n");
	ft_foreach_stack(&stack_a, fn, NULL);
	ft_printf("\n");
	ft_foreach_stack(&stack_b, fn, NULL);
	ft_printf("\n");
	ft_printf("\n--------------\n");
}

int	main(int argc, char *argv[argc])
{
	t_stack		a;
	t_stack		b;
	t_config	config;
	float		disorder;

	config = init(&a, &b, argc - 1, argv + 1);
	//todo check unique
	if (!config.is_valid)
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	disorder = ft_disorder(a);
	if (config.mode == ADAPTIVE || config.is_bench_mode)
		ft_printf("disorder = %d %", 100 * disorder);
	if (config.mode == ADAPTIVE)
	{
		if (disorder < 0.2)
			config.mode = SIMPLE;
		else if (disorder < 0.5)
			config.mode = MEDIUM;
		else
			config.mode = COMPLEX;
	}
	print_stack(a, b);
	if (config.mode == SIMPLE)
		simple_algo(&a, &b);
	else if (config.mode == MEDIUM)
		medium_algo(&a, &b);
	else if (config.mode == COMPLEX)
	{
		case3(&a);
	}

	print_stack(a, b);
	return (0);
}

static t_config	init(
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
	stack_a->max_size = size;
	stack_a->size = stack_a->max_size;
	stack_a->array = malloc(size * sizeof(t_tuple*));
	stack_a->start = 0;
	stack_a->end = size - 1;
	if (ft_foreach_stack(stack_a, str_to_tuple, arr) == ERROR)
	{
		config.is_valid = FALSE;
		return (config);
	}
	stack_b->size = 0;
	stack_b->array = malloc(size * sizeof(t_tuple*));
	stack_b->start = 0;
	stack_b->end = 0;
	stack_b->max_size = stack_a->max_size;
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
	*arr = ft_split(argv[i], ' ');
	*size = 0;
	while (*(*arr + *size))
		*size = *size + 1;
	if (argc - i)
		set_arr(arr, join_arr(*arr, argv + i + 1, *size, argc - 1 - i));
	*size += (argc - 1 - i);
	return (config);
}

static void	set_arr(char ***str, char **value)
{
	free(*str);
	*str = value;
}

static char	**join_arr(char **arr1, char **arr2, int arr1_size, int arr2_size)
{
	int		i;
	char	**new_arr;

	new_arr = malloc((sizeof(char *) * (arr1_size + arr2_size)) + 1);
	i = 0;
	while (i < arr1_size)
	{
		new_arr[i] = arr1[i];
		i++;
	}
	i = 0;
	while (i < arr2_size)
	{
		new_arr[arr1_size + i] = arr2[i];
		i++;
	}
	new_arr[arr1_size + i] = 0;
	return (new_arr);
}

static int	str_to_tuple(int index, t_tuple **tuple, void *arr)
{
	int		i;
	char	*str;

	i = 0;
	str = ((char **)arr)[index];
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+') )
			return (ERROR);
		i++;
	}
	*tuple = malloc(sizeof(t_tuple));
	(*tuple)->rank = 0;
	(*tuple)->value = ft_atoi(str);
	return (0);
}
