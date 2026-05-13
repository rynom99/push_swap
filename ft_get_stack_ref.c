/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack_ref.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:04:09 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/13 19:04:30 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tuple	**ft_get_stack_ref(t_stack *stack, int index)
{
	return (stack->array + ((index + stack->start) % stack->max_size));
}
