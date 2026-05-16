/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:41:49 by malshare          #+#    #+#             */
/*   Updated: 2026/05/16 20:18:47 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_tuple	*result;

	if (!stack || stack->size < 2)
		return ;
	result = stack->array[stack->end];
	if (stack->start == 0)
		stack->start = (stack->max_size - 1);
	else
		stack->start = stack->start - 1;
	if (stack->end == 0)
		stack->end = (stack->max_size - 1);
	else
		stack->end = stack->end - 1;
	if (stack->max_size != stack->size)
		stack->array[stack->start] = result;
}

int	rra(t_stack *a)
{
	static int	i;

	if (!a)
		return (i);
	reverse_rotate(a);
	ft_log("rra");
	return (++i);
}

int	rrb(t_stack *b)
{
	static int	i;

	if (!b)
		return (i);
	reverse_rotate(b);
	ft_log("rrb");
	return (++i);
}

int	rrr(t_stack *a, t_stack *b)
{
	static int	i;

	if (!a || !b)
		return (i);
	reverse_rotate(a);
	reverse_rotate(b);
	ft_log("rrr");
	return (++i);
}
