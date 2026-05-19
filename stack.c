/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:28:24 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/19 18:56:43 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack(t_stack *stack)
{
	t_tuple	**row;
	size_t	i;

	if (stack->array == NULL)
		return ;
	i = stack->size;
	while (i--)
	{
		row = ft_get_stack_ref(stack, i);
		free(*row);
		*row = NULL;
		stack->size = stack->size - 1;
	}
	free(stack->array);
	stack->array = NULL;
	stack->start = 0;
	stack->end = 0;
	stack->size = 0;
	stack->max_size = 0;
}

int	ft_execute(enum e_ops ops, t_stack *a, t_stack *b)
{
	if (ops == SA)
		sa(a);
	else if (ops == SB)
		sb(b);
	else if (ops == SS)
		ss(a, b);
	else if (ops == PA)
		pa(a, b);
	else if (ops == PB)
		pb(a, b);
	else if (ops == RA)
		ra(a);
	else if (ops == RB)
		rb(b);
	else if (ops == RR)
		rr(a, b);
	else if (ops == RRA)
		rra(a);
	else if (ops == RRB)
		rrb(b);
	else if (ops == RRR)
		rrr(a, b);
	return (TRUE);
}

static int	combine_ops(enum e_ops last_ops, enum e_ops ops,
	t_stack *a, t_stack *b)
{
	if ((last_ops == SA && ops == SB) || (last_ops == SB && ops == SA))
	{
		ss(a, b);
		return (TRUE);
	}
	if ((last_ops == RA && ops == RB) || (last_ops == RB && ops == RA))
	{
		rr(a, b);
		return (TRUE);
	}
	if ((last_ops == RRA && ops == RRB) || (last_ops == RRB && ops == RRA))
	{
		rrr(a, b);
		return (TRUE);
	}
	return (FALSE);
}

int	ft_lazy_execute(enum e_ops ops, t_stack *a, t_stack *b)
{
	static enum e_ops	last_ops;

	if ((ops == SA || ops == SB || ops == RA || ops == RB
			|| ops == RRA || ops == RRB) && last_ops == LAST)
	{
		last_ops = ops;
		return (TRUE);
	}
	else if (ops == LAST)
		ft_execute(last_ops, a, b);
	else if (combine_ops(last_ops, ops, a, b))
		last_ops = LAST;
	else
	{
		ft_execute(last_ops, a, b);
		last_ops = ops;
	}
	return (TRUE);
}
