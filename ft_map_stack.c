/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 23:58:22 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/13 00:49:24 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_map_stack(t_stack stack, int *(*fn)(int, t_tuple*))
{
	t_tuple	*element;
	int		i;

	i = 0;
	while (i < stack.size)
	{
		element = ft_get_stack(stack, i);
		fn(i, element);
		i++;
	}
}
