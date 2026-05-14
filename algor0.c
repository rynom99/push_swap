/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:58:01 by malshare          #+#    #+#             */
/*   Updated: 2026/05/14 19:35:34 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  first algorithem : check for the minimum element in the stak 
// chek if it is closer to top or buttom
// push it to the nearest eadge
//  push it to stake b


static int	find_rank_position(t_stack *stack, int target_rank)
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

static void	return_to_a(t_stack *a, t_stack *b)
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
			while (pos++ < b->size)
				rrb(b);

		pa(a, b);
	}
}

void	simple_algo(t_stack *stack_a, t_stack *stack_b)
{
	int	max_rank;
	int	pos;
	ft_set_ranks(stack_a);
	while (stack_a->size > 0)
	{
		max_rank = stack_a->size - 1;
		pos = find_rank_position(stack_a, max_rank);

		if (pos <= stack_a->size / 2)
			while (pos-- > 0)
				ra(stack_a);
		else
			while (pos++ < stack_a->size)
				rra(stack_a);

		pb(stack_a, stack_b);
	}
	return_to_a(stack_a, stack_b);
}
