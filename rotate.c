/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:41:49 by malshare          #+#    #+#             */
/*   Updated: 2026/05/14 00:30:17 by mnououal         ###   ########.fr       */
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

static void	reverse_rotete(t_stack *stack)
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

void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}

void	rra(t_stack *a)
{
	reverse_rotete(a);
	ft_putstr("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotete(b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotete(a);
	reverse_rotete(b);
	ft_putstr("rrr\n");
}
