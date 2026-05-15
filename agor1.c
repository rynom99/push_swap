/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agor1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:39:33 by malshare          #+#    #+#             */
/*   Updated: 2026/05/15 06:44:24 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int n)
{
	if (n <= 100)
		return (15);
	if (n <= 500)
		return (40);
	return (n / 20);
}


static int	push_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;
	int j = 0;

	i = 0;
	while (a->size > 0 && a->size != 3)
	{

		if (ft_get_stack(a, 0)->rank <= i)
		{
			pb(a, b);
			i++;
			j++;
		}
		else if ((ft_get_stack(a, 0)->rank <= (i + chunk_size))
			&& (ft_get_stack(a, 0)->rank < a->max_size - 3))
		{
			pb(a, b);
			rb(b);
			i++;
			j = j + 2;
		}
		else
		{
			ra(a);
			j++;
		}
	}
	return(j);
}

static int	return_to_a(t_stack *a, t_stack *b)
{
	int	max_rank;
	int	pos;
	int j = 0;

	while (b->size > 0)
	{
		max_rank = b->size - 1;
		pos = find_rank_position(b, max_rank);

		if (pos <= b->size / 2)
			while (pos-- > 0)
			{
				rb(b);
				j++;
			}
		else
			while (pos++ < b->size)
			{
				rrb(b);
				j++;
			}
		pa(a, b);
		j++;
	}
	return (j);
}




void	medium_algo(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int j =0;
	int k = 0;

	if ( ft_disorder( *stack_a) == 0)
		return ;
	ft_set_ranks(stack_a);
	chunk_size = get_chunk_size(stack_a->size);
	j = push_to_b(stack_a, stack_b, chunk_size);
	if (stack_a->size == 3)
		case3(stack_a);
	k = return_to_a(stack_a, stack_b);
	ft_printf("j + k = %d", j + k);

}
