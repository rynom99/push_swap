/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:34:53 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/12 22:17:08 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_arr(char ***str, char *value)
{
	free(**str);
	**str = value;
}

static t_config	split_args(
	int argc, char *argv[argc], char ***arr, int *size)
{
	t_config	config;
	int			i;

	i = 1;
	if (ft_strstr(argv[i - 1], "--simple"))
		config.mode = SIMPLE;
	else if (ft_strstr(argv[i - 1], "--medium"))
		config.mode = MEDIUM;
	else if (ft_strstr(argv[i - 1], "--complex"))
		config.mode = COMPLEX;
	else if (ft_strstr(argv[i - 1], "--adaptive"))
		config.mode = ADAPTIVE;
	else
		i--;
	i++;
	*arr = ft_split(argv[argc - i], ' ');
	*size = 0;
	while (*(arr + *size))
		*size = *size + 1;
	if (argc - i)
		set_arr(*arr, join_arr(*arr, argv + i + 1, *size, argc - 1 - i));
	*size += (argc - 1 - i);
	return (config);
}

static t_config	init(t_stack *a, t_stack *b, int argc, char *argv[argc])
{
	t_config	mode;
	char		**arr;
	int			size;

	mode = split_args(argc, argv, arr, &size);
	a->size = size;
	a->array = malloc(size);
	a->start = 0;
	a->end = size - 1;
	b->size = 0;
	b->array = malloc(size);
	b->start = 0;
	b->end = 0;
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

int	main(int argc, char *argv[argc])
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	config = init(&a, &b, argc - 1, argv);
	return (0);
}
