/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:58:01 by malshare          #+#    #+#             */
/*   Updated: 2026/05/16 19:21:08 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_idx_minimum_value(
				int idx, t_stack *stack, t_tuple **tuple, void *extra);

/*
Simple Algorithm
get the minimum element in the stack
push it to stack b until reach size 3
sort stack a
push it back all stack a
*/
void	simple_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int	idx;

	while (stack_a->size > 3)
	{
		idx = 0;
		ft_foreach_stack(stack_a, get_idx_minimum_value, &idx);
		if (idx < (stack_a->size / 2))
			while (idx--)
				ra(stack_a);
		else
		{
			idx = stack_a->size - idx;
			while (idx--)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	if (stack_a->size == 3)
		case3_algorithm(stack_a);
	else
		case2_algorithm(stack_a);
	idx = stack_b->size;
	while (idx--)
		pa(stack_a, stack_b);
}

static int	get_idx_minimum_value(
	int idx, t_stack *stack, t_tuple **tuple, void *extra)
{
	int			*idx_with_min;

	idx_with_min = extra;
	if (idx == 0)
	{
		*idx_with_min = idx;
		return (1);
	}
	if (ft_get_stack(stack, *idx_with_min)->value > (*tuple)->value)
	{
		*idx_with_min = idx;
	}
	return (1);
}
