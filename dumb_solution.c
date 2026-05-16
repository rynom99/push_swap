/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:18:25 by malshare          #+#    #+#             */
/*   Updated: 2026/05/16 17:13:32 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case3(t_stack *a);

int	need_dumb_solution(t_config *config, t_stack *a)
{
	if (config->disorder == 0)
		return (TRUE);
	if (a->size < 4)
		return (TRUE);
	return (FALSE);
}

void	dumb_solution(t_config *config, t_stack *a)
{
	if (config->disorder == 0)
		return ;
	if (a->size == 3)
	{
		case3(a);
		return ;
	}
	ra(a);
}

static void	case3(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = ft_get_stack(a, 0)->value;
	second = ft_get_stack(a, 1)->value;
	third = ft_get_stack(a, 2)->value;
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
