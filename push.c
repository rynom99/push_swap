/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:11:52 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/16 20:17:52 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *stack, t_tuple *tuple)
{
	if (stack->size == 0)
	{
		stack->start = 0;
		stack->end = 0;
	}
	else if (stack->start == 0)
		stack->start = (stack->max_size - 1);
	else
		stack->start = stack->start - 1;
	stack->array[stack->start] = tuple;
	stack->size = stack->size + 1;
}

static t_tuple	*pop(t_stack *stack)
{
	t_tuple	*tuple;

	tuple = ft_get_stack(stack, 0);
	if (stack->start == (stack->max_size - 1))
		stack->start = 0;
	else
		stack->start = stack->start + 1;
	stack->size = stack->size - 1;
	return (tuple);
}

int	pa(t_stack *a, t_stack *b)
{
	static int	i;

	if (!a || !b || a->size == a->max_size)
		return (i);
	push(a, pop(b));
	ft_log("pa");
	return (++i);
}

int	pb(t_stack *a, t_stack *b)
{
	static int	i;

	if (!a || !b || b->size == b->max_size)
		return (i);
	push(b, pop(a));
	ft_log("pb");
	return (++i);
}
