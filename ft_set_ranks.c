/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ranks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 22:01:26 by malshare          #+#    #+#             */
/*   Updated: 2026/05/19 18:55:32 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(t_tuple **arr, int from_idx, int to_idx);
static void	swap(t_tuple **arr, int idx1, int idx2);
static void	ft_quicksort_tuple(t_tuple **arr, int from_idx, int to_idx);

void	ft_set_ranks(t_stack *a)
{
	t_tuple	**temp_arr;
	int		i;

	temp_arr = malloc(sizeof(t_tuple *) * a->size);
	if (!temp_arr)
		return ;
	i = 0;
	while (i < a->size)
	{
		temp_arr[i] = ft_get_stack(a, i);
		i++;
	}
	ft_quicksort_tuple(temp_arr, 0, i - 1);
	i = 0;
	while (i < a->size)
	{
		temp_arr[i]->rank = i;
		i++;
	}
	free(temp_arr);
	temp_arr = NULL;
}

int	find_rank_position(t_stack *stack, int target_rank)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (ft_get_stack(stack, i)->rank == target_rank)
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_quicksort_tuple(t_tuple **arr, int from_idx, int to_idx)
{
	int	p_idx;

	if (from_idx >= to_idx)
		return ;
	p_idx = partition(arr, from_idx, to_idx);
	ft_quicksort_tuple(arr, from_idx, p_idx - 1);
	ft_quicksort_tuple(arr, p_idx + 1, to_idx);
}

static int	partition(t_tuple **arr, int from_idx, int to_idx)
{
	int	l_idx;
	int	r_idx;

	l_idx = from_idx;
	r_idx = to_idx;
	while (l_idx < r_idx)
	{
		while (arr[l_idx]->value <= arr[from_idx]->value && l_idx <= to_idx - 1)
			l_idx++;
		while (arr[r_idx]->value > arr[from_idx]->value
			&& r_idx >= from_idx + 1)
			r_idx--;
		if (l_idx < r_idx)
			swap(arr, l_idx, r_idx);
	}
	swap(arr, from_idx, r_idx);
	return (r_idx);
}

static void	swap(t_tuple **arr, int idx1, int idx2)
{
	t_tuple	*temp;

	temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}
