/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:58:01 by malshare          #+#    #+#             */
/*   Updated: 2026/05/16 18:44:31 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_idx_minimum_value(
				int idx, t_stack *stack, t_tuple **tuple, void *extra);

/*
Simple Algorithm
get the minimum element in the stack
check if it is closer to top or buttom
push it to the nearest edge
push it to stack b
*/
void	simple_algorithm(t_config *cfg, t_stack *stack_a, t_stack *stack_b)
{
	int	idx;

	if (need_dumb_solution(cfg, stack_a))
	{
		dumb_solution(cfg, stack_a);
		return ;
	}
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
