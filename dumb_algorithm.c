/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:18:25 by malshare          #+#    #+#             */
/*   Updated: 2026/05/16 19:05:43 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case2_algorithm(t_stack *a)
{
	if (ft_get_stack(a, 0)->value > ft_get_stack(a, 1)->value)
		ra(a);
}

void	case3_algorithm(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = ft_get_stack(a, 0)->value;
	second = ft_get_stack(a, 1)->value;
	third = ft_get_stack(a, 2)->value;
	if (first < second && second < third)
		return ;
	if (second < third)
	{
		if ((first > second) && (first < third))
			sa(a);
		else if ((first > second) && (first > third))
			ra(a);
	}
	else if (second > third)
	{
		if ((first < second) && (first > third))
			rra(a);
		else if ((first < second) && (first < third))
			(sa(a) && ra(a));
		else if ((first > second) && (first > third))
			(sa(a) && rra(a));
	}
}
