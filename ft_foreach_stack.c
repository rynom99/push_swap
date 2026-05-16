/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 23:58:22 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/16 17:21:38 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_foreach_stack(
			t_stack *stack,
			int (*fn)(int, t_stack*, t_tuple**, void *extra),
			void *extra)
{
	t_tuple	**element;
	int		i;

	i = 0;
	while (i < stack->size)
	{
		element = ft_get_stack_ref(stack, i);
		if (fn(i, stack, element, extra) == ERROR)
			return (ERROR);
		i++;
	}
	return (TRUE);
}
