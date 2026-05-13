/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapz.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:36:03 by malshare          #+#    #+#             */
/*   Updated: 2026/05/13 19:37:51 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_tuple	*first;
	t_tuple	*second;
	t_tuple	temp;

	if (!stack || stack->size < 2)
		return ;
	first = ft_get_stack(stack, 0);
	second = ft_get_stack(stack, 1);
	temp = *first;
	*first = *second;
	*second = temp;
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
