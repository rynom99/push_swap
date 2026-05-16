/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:28:24 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/16 17:42:25 by mnououal         ###   ########.fr       */
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
	stack->start = 0;
	stack->end = 0;
	stack->size = 0;
	stack->max_size = 0;
	stack->array = NULL;
}
