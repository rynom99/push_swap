/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agor1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:39:33 by malshare          #+#    #+#             */
/*   Updated: 2026/05/13 18:06:38 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;

	i = 0;
	while (a->size > 0)
	{
		if (ft_get_stack(*a, 0)->rank <= i)
		{
			pb(a, b);
			i++;
		}
		else if (ft_get_stack(*a, 0)->rank <= (i + chunk_size))
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void	return_to_a(t_stack *a, t_stack *b)
{
	int	max_rank;
	int	pos;

	while (b->size > 0)
	{
		max_rank = b->size - 1;
		pos = find_rank_position(b, max_rank);

		if (pos <= b->size / 2)
			while (pos--)
				rb(b);
		else
			while (pos++ < b->size)
				rrb(b);

		pa(a, b);
	}
}

int	find_rank_position(t_stack *stack, int target_rank)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (ft_get_stack(*stack, i)->rank == target_rank)
			return (i);
		i++;
	}
	return (-1);
}

int	get_chunk_size(int n)
{
	if (n <= 100)
		return (15);
	if (n <= 500)
		return (40);
	return (n / 20);
}
