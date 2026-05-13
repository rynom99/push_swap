/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:41:49 by malshare          #+#    #+#             */
/*   Updated: 2026/05/13 19:51:02 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
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

static void	reverse_rotete(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	a->start = (a->start - 1 + a->max_size) % a->max_size;
}

void rb(t_stack *a)
{

}
// rr
// rra
// rrb
// rrr
