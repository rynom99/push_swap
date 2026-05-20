/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 05:15:08 by malshare          #+#    #+#             */
/*   Updated: 2026/05/20 19:20:56 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_pivot(t_stack *a)
{
	int	min;
	int	max;
	int	i;

	if (a->size == 0)
		return (0);
	min = ft_get_stack(a, 0)->rank;
	max = ft_get_stack(a, 0)->rank;
	i = 0;
	while (i < a->size)
	{
		if (ft_get_stack(a, i)->rank < min)
			min = ft_get_stack(a, i)->rank;
		if (ft_get_stack(a, i)->rank > max)
			max = ft_get_stack(a, i)->rank;
		i++;
	}
	return ((min + max) / 2);
}

static void	partition_to_b(t_stack *a, t_stack *b)
{
	int	pivot;
	int	initial_size;

	while (a->size > 5)
	{
		pivot = get_pivot(a);
		initial_size = a->size;
		while (initial_size-- > 0 && a->size > 3)
		{
			if (ft_get_stack(a, 0)->rank <= pivot)
			{
				pb(a, b);
				if (b->size > 1 && ft_get_stack(b, 0)->rank < (pivot / 2))
					rb(b);
			}
			else
				ra(a);
		}
	}
}

static void	smart_return(t_stack *a, t_stack *b)
{
	int	max_rank;
	int	pos;

	while (b->size > 0)
	{
		max_rank = b->size - 1;
		pos = find_rank_position(b, max_rank);
		if (pos <= b->size / 2)
			while (pos-- > 0)
				rb(b);
		else
		{
			pos = b->size - pos;
			while (pos-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	medium_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_disorder(*stack_a) == 0)
		return ;
	ft_set_ranks(stack_a);
	partition_to_b(stack_a, stack_b);
	case5_algorithm(stack_a, stack_b);
	smart_return(stack_a, stack_b);
}
