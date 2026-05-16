/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:41:49 by malshare          #+#    #+#             */
/*   Updated: 2026/05/16 20:20:02 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_tuple	*result;

	if (!stack || stack->size < 2)
		return ;
	result = stack->array[stack->start];
	if (stack->start == (stack->max_size - 1))
		stack->start = 0;
	else
		stack->start = stack->start + 1;
	if (stack->end == (stack->max_size - 1))
		stack->end = 0;
	else
		stack->end = stack->end + 1;
	if (stack->max_size != stack->size)
		stack->array[stack->end] = result;
}

int	ra(t_stack *a)
{
	static int	i;

	if (!a)
		return (i);
	rotate(a);
	ft_log("ra");
	return (i++);
}

int	rb(t_stack *b)
{
	static int	i;

	if (!b)
		return (i);
	rotate(b);
	ft_log("rb");
	return (i++);
}

int	rr(t_stack *a, t_stack *b)
{
	static int	i;

	if (!a || !b)
		return (i);
	rotate(a);
	rotate(b);
	ft_log("rr");
	return (i++);
}
