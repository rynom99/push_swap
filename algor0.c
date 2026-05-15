/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:58:01 by malshare          #+#    #+#             */
/*   Updated: 2026/05/15 20:40:01 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_idx_minimum(
				int idx, t_stack *stack, t_tuple **tuple, void *extra);

/*
first algorithem : check for the minimum element in the stack
check if it is closer to top or buttom
push it to the nearest edge
push it to stake b
*/
void	simple_algorithem(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	idx_with_min;
	int	i;

	while (stack_a->size > 3)
	{
		idx_with_min = 0;
		ft_foreach_stack(stack_a, get_idx_minimum, &idx_with_min);
		if (idx_with_min < (stack_a->size / 2))
			while (idx_with_min--)
				ra(stack_a);
		else
		{
			i = stack_a->size - idx_with_min;
			while (i--)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	if (stack_a->size == 3)
		case3(stack_a);
	//TODO case 2
	i = stack_b->size;
	while (i--)
		pa(stack_a, stack_b);
}

static int	get_idx_minimum(
	int idx, t_stack *stack, t_tuple **tuple, void *extra)
{
	int			*idx_with_min;

	idx_with_min = extra;
	if (idx == 0)
	{
		*idx_with_min = idx;
		return (1);
	}
	if (ft_get_stack(stack, idx_with_min) > (*tuple)->value)
	{
		*idx_with_min = idx;
	}
	return (1);
}
