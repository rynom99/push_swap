/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:36:03 by malshare          #+#    #+#             */
/*   Updated: 2026/05/15 20:26:30 by mnououal         ###   ########.fr       */
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

int	sa(t_stack *a)
{
	static int	i;

	swap(a);
	ft_log("sa\n");
	if (!ft_is_counter_locked(FALSE))
		i++;
	return (i);
}

int	sb(t_stack *b)
{
	static int	i;

	swap(b);
	ft_log("sb\n");
	if (!ft_is_counter_locked(FALSE))
		i++;
	return (i);
}

int	ss(t_stack *a, t_stack *b)
{
	static int	i;

	swap(a);
	swap(b);
	ft_log("ss\n");
	if (!ft_is_counter_locked(FALSE))
		i++;
	return (i);
}
