/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:34:53 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/13 01:01:52 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static t_config	init(t_stack *a, t_stack *b, int argc, char *argv[argc]);
static t_config	split_args(
					int argc, char *argv[argc], char ***arr, int *size);
static void		set_arr(char ***str, char *value);
static char		**join_arr(
					char **arr1, char **arr2, int size_arr1, int size_arr2);

int	main(int argc, char *argv[argc])
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	config = init(&a, &b, argc - 1, argv + 1);
	return (0);
}

static t_config	init(t_stack *a, t_stack *b, int argc, char *argv[argc])
{
	t_config	config;
	char		**arr;
	int			size;

	config = split_args(argc, argv, &arr, &size);
	a->max_size = size;
	a->size = a->max_size;
	a->array = malloc(size * sizeof(t_tuple));
	a->start = 0;
	a->end = size - 1;
	b->size = 0;
	b->array = malloc(size * sizeof(t_tuple));
	b->start = 0;
	b->end = 0;
	b->max_size = a->max_size;
	return (config);
}

static t_config	split_args(
	int argc, char *argv[argc], char ***arr, int *size)
{
	t_config	config;
	int			i;

	i = 0;
	if (ft_strstr(argv[i], "--bench") && ++i)
		config.is_bench_mode = 1;
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
