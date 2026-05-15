/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:58:01 by malshare          #+#    #+#             */
/*   Updated: 2026/05/15 03:09:15 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  first algorithem : check for the minimum element in the stak
// chek if it is closer to top or buttom
// push it to the nearest eadge
//  push it to stake b




void	simple_algorithem(t_stack *stack_a, t_stack *stack_b)
{
	int temp;
	int min;
	int min_indx;
	int j;
	int i;

	i = 0;
	while (2 < stack_a->size && stack_a->size != 3)
	{
		min_indx = 0;
		min = ft_get_stack(stack_a, 0)->value;
		j = 1;
		while (j < stack_a->size)
		{
			temp = ft_get_stack(stack_a, j)->value;
			if (min > temp)
			{
				min = temp;
				min_indx = j;
			}
			j++;
		}
		// now the min is in min and we know the index want to see its position
		if (min_indx < (stack_a->size / 2))
		{
			while (min_indx--)
			{
				ra(stack_a);
				i++;
			}
			pb(stack_a, stack_b);
		}
		else
		{
			j = stack_a->size - min_indx;
			while (j--)
			{
				rra(stack_a);
				i++;
			}
			pb(stack_a, stack_b);
		}
	}
	if (stack_a->size == 3)
		case3(stack_a);
	i = i +3;
	j = stack_b->size;
	while (j--)
	{
		pa(stack_a, stack_b);
		i++;
	}
	ft_printf("i = %d", i);
}

// static void	return_to_a(t_stack *a, t_stack *b)
// {
// 	int	max_rank;
// 	int	pos;

// 	while (b->size > 0)
// 	{
// 		max_rank = b->size - 1;
// 		pos = find_rank_position(b, max_rank);

// 		if (pos <= b->size / 2)
// 			while (pos-- > 0)
// 				rb(b);
// 		else
// 			while (pos++ < b->size)
// 				rrb(b);

// 		pa(a, b);
// 	}
// }

// void	simple_algo(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	max_rank;
// 	int	pos;
// 	ft_set_ranks(stack_a);
// 	while (stack_a->size > 0)
// 	{
// 		max_rank = stack_a->size - 1;
// 		pos = find_rank_position(stack_a, max_rank);

// 		if (pos <= stack_a->size / 2)
// 			while (pos-- > 0)
// 				ra(stack_a);
// 		else
// 			while (pos++ < stack_a->size)
// 				rra(stack_a);

// 		pb(stack_a, stack_b);
// 	}
// 	return_to_a(stack_a, stack_b);
// }
// void    simple_algorithm1(t_stack *stack_a, t_stack *stack_b)
// {
// 	int min;
// 	int min_indx;
// 	int j;

// 	while (stack_a->size > 0)
// 	{
// 		// 1. Reset for every search!
// 		min_indx = 0;
// 		min = ft_get_stack(stack_a, 0)->value;

// 		j = 1;
// 		while (j < stack_a->size)
// 		{
// 			// Get the value at logical index j
// 			int current_val = ft_get_stack(stack_a, j)->value;
// 			if (current_val < min) // Finding the smallest
// 			{
// 				min = current_val;
// 				min_indx = j;
// 			}
// 			j++;
// 		}
// 		if (min_indx <= stack_a->size / 2)
// 			while (min_indx > 0)
// 			{
// 				ra(stack_a);
// 				min_indx--;
// 			}
// 		else
// 		{
// 			int rra_moves = stack_a->size - min_indx;
// 			while (rra_moves > 0)
// 			{
// 				rra(stack_a);
// 				rra_moves--;
// 			}
// 		}
// 		pb(stack_a, stack_b);
// 	}
// 	while (stack_b->size > 0)
// 		pa(stack_a, stack_b);
// }
