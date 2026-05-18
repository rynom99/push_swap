/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:39:33 by malshare          #+#    #+#             */
/*   Updated: 2026/05/18 22:23:06 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int n);
static void	push_to_b(t_stack *a, t_stack *b, int chunk_size);
static void	return_to_a(t_stack *a, t_stack *b);

void	medium_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;

	if (stack_a->size == 3)
	{
		case3_algorithm(stack_a, stack_b);
		return ;
	}
	if (stack_a->size == 2)
	{
		case2_algorithm(stack_a, stack_b);
		return ;
	}
	ft_set_ranks(stack_a);
	chunk_size = get_chunk_size(stack_a->size);
	push_to_b(stack_a, stack_b, chunk_size);
	if (stack_a->size == 3)
		case3_algorithm(stack_a, stack_b);
	return_to_a(stack_a, stack_b);
	ft_execute(LAST, stack_a, stack_b);
}

static int	get_chunk_size(int n)
{
	if (n <= 100)
		return (15);
	if (n <= 500)
		return (40);
	return (n / 20);
}

static void	push_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;

	i = 0;
	while (a->size > 0 && a->size != 3)
	{
		// ft_printf("a.rank =  %i,i = %i, chunk= %i\n",ft_get_stack(a, 0)->rank, i,chunk_size  );

		if (ft_get_stack(a, 0)->rank <= i)
			(ft_execute(PB, a, b) && i++);
		else if ((ft_get_stack(a, 0)->rank <= (i + chunk_size))
			&& (ft_get_stack(a, 0)->rank < a->max_size - 3))
			(ft_execute(PB, a, b) && ft_execute(RB, a, b) && i++ );
		else
			ft_execute(RA, a, b);
	}
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
				ft_execute(RB, a, b);
		else
			while (pos++ < b->size)
				ft_execute(RRB, a, b);
		ft_execute(PA, a, b);
	}
}
