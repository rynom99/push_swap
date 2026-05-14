/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:18:25 by malshare          #+#    #+#             */
/*   Updated: 2026/05/15 00:33:59 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	case3(t_stack *a)
{
	int	first;
	int	second;
	int	thired;

	if (ft_disorder(*a) == 0)
		return ;
	first = ft_get_stack(a, 0)->value;
	second = ft_get_stack(a, 1)->value;
	thired = ft_get_stack(a, 2)->value;
	if ((first > second) && (first < thired) && (second < thired))
		sa(a);
	else if ((first > second) && (first > thired) && (second > thired))
	{
		sa(a);
		rra(a);
	}
	else if ((first > second) && (first > thired) && (second < thired))
		ra(a);
	else if ((first < second) && (first < thired) && (second > thired))
	{
		sa(a);
		ra(a);
	}
	else if ((first < second) && (first > thired) && (second > thired))
		rra(a);
}

