/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 23:58:22 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/13 19:06:42 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_foreach_stack(
			t_stack *stack,
			int (*fn)(int, t_tuple**, void *extra),
			void *extra)
{
	t_tuple	**element;
	int		i;

	i = 0;
	while (i < stack->size)
	{
		element = ft_get_stack_ref(stack, i);
		if (fn(i, element, extra) == ERROR)
		{
			while (i--)
			{
				element = ft_get_stack_ref(stack, i);
				free(*element);
			}
			return (ERROR);
		}
		i++;
	}
	return (TRUE);
}
