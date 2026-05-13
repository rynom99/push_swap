/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:41:49 by malshare          #+#    #+#             */
/*   Updated: 2026/05/13 18:49:22 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->start = (stack->start + 1) % stack->max_size;
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
void	reverse_rotete(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	a->start = (a->start - 1 + a->max_size) % a->max_size;
}