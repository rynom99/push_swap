/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_logger.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 21:49:20 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/15 19:24:27 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fn(int a, t_stack *stack, t_tuple **tuple, void *extra)
{
	if (extra || 1)
		ft_printf("{[%d]-> %d}, ", a, (*tuple)->value);
	return (1);
}

void	print_stack(t_stack stack_a, t_stack stack_b)
{
	ft_printf(
		"\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	ft_printf("Stack A = ");
	ft_foreach_stack(&stack_a, fn, NULL);
	ft_printf("\n");
	ft_printf("Stack B = ");
	ft_foreach_stack(&stack_b, fn, NULL);
	ft_printf(
		"\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
}
