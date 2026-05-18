/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:18:25 by malshare          #+#    #+#             */
/*   Updated: 2026/05/18 20:49:44 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case2_algorithm(t_stack *a, t_stack *b)
{
	if (ft_get_stack(a, 0)->value > ft_get_stack(a, 1)->value)
		ft_execute(RA, a, b);
}

void	case3_algorithm(t_stack *a, t_stack *b)
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
			ft_execute(SA, a, b);
		else if ((first > second) && (first > third))
			ft_execute(RA, a, b);
	}
	else if (second > third)
	{
		if ((first < second) && (first > third))
			ft_execute(RRA, a, b);
		else if ((first < second) && (first < third))
			(ft_execute(SA, a, b) && ft_execute(RA, a, b));
		else if ((first > second) && (first > third))
			(ft_execute(SA, a, b) && ft_execute(RRA, a, b));
	}
}
