/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:36:03 by malshare          #+#    #+#             */
/*   Updated: 2026/05/18 16:56:40 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_tuple	*first;
	t_tuple	*second;
	t_tuple	temp;

	first = ft_get_stack(stack, 0);
	second = ft_get_stack(stack, 1);
	temp = *first;
	*first = *second;
	*second = temp;
}

int	sa(t_stack *a)
{
	static int	i;

	if (a == NULL || a->size < 2)
		return (i);
	swap(a);
	ft_log("sa");
	return (i++);
}

int	sb(t_stack *b)
{
	static int	i;

	if (b == NULL || b->size < 2)
		return (i);
	swap(b);
	ft_log("sb");
	return (i++);
}

int	ss(t_stack *a, t_stack *b)
{
	static int	i;

	if (a == NULL || a->size < 2 || b == NULL || b->size < 2)
		return (i);
	swap(a);
	swap(b);
	ft_log("ss");
	return (i++);
}
