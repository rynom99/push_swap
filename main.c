/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:34:53 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/13 16:27:30 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_config	init(t_stack *a, t_stack *b, int argc, char *argv[argc]);
static t_config	split_args(
					int argc, char *argv[argc], char ***arr, int *size);
static void		set_arr(char ***str, char *value);
static char		**join_arr(
					char **arr1, char **arr2, int size_arr1, int size_arr2);
static int		str_to_tuple(int index, t_tuple **tuple, void *arr);

int	main(int argc, char *argv[argc])
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	config = init(&a, &b, argc - 1, argv + 1);
	if (!config.is_valid)
	{
		ft_printf("Error\n");
		return (1);
	}
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
	stack_a->array = malloc(size * sizeof(t_tuple));
	stack_a->start = 0;
	stack_a->end = size - 1;
	if (ft_foreach_stack(stack_a, str_to_tuple, arr) == ERROR)
	{
		config.is_valid = FALSE;
		return (config);
	}
	stack_b->size = 0;
	stack_b->array = malloc(size * sizeof(t_tuple));
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

	config.is_valid = TRUE;
	i = 0;
	if (ft_strstr(argv[i], "--bench") && ++i)
		config.is_bench_mode = TRUE;
	if (ft_strstr(argv[i], "--simple") && ++i)
		config.mode = SIMPLE;
	else if (ft_strstr(argv[i], "--medium") && ++i)
		config.mode = MEDIUM;
	else if (ft_strstr(argv[i], "--complex") && ++i)
		config.mode = COMPLEX;
	else if (ft_strstr(argv[i], "--adaptive") && ++i)
		config.mode = ADAPTIVE;
	else
		config.mode = ADAPTIVE;
	*arr = ft_split(argv[i], ' ');
	*size = 0;
	while (*(arr + *size))
		*size = *size + 1;
	if (argc - i)
		set_arr(arr, *join_arr(*arr, argv + i + 1, *size, argc - 1 - i));
	*size += (argc - 1 - i);
	return (config);
}

static void	set_arr(char ***str, char *value)
{
	free(**str);
	**str = value;
}

static char	**join_arr(char **arr1, char **arr2, int size_arr1, int size_arr2)
{
	int		i;
	char	**new_arr;

	new_arr = malloc((sizeof(char) * size_arr1 * size_arr2) + 1);
	i = 0;
	while (i < size_arr1)
	{
		new_arr[i] = arr1[i];
		i++;
	}
	i = 0;
	while (i < size_arr2)
	{
		new_arr[size_arr1 + i] = arr2[i];
		i++;
	}
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
		if (!ft_isdigit(str[i]))
			return (ERROR);
		i++;
	}
	*tuple = malloc(sizeof(t_tuple));
	(*tuple)->rank = 0;
	(*tuple)->value = ft_atoi(str);
	ft_atoi(str);
	return (0);
}
