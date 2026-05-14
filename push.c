/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:11:52 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/14 18:25:07 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack *stack, t_tuple *tuple)
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

void	pa(t_stack *a, t_stack *b)
{
	if (a->size == a->max_size)
		return ;
	push(a, pop(b));
	ft_putstr("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (b->size == b->max_size)
		return ;
	push(b, pop(a));
	ft_putstr("pb\n");
}
