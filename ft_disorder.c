/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:20:27 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/13 19:21:33 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_disorder(t_stack a)
{
	int	misatkes;
	int	total_pairs;
	int	i;
	int	j;

	if (a.size < 2)
		return (0);
	i = 0;
	misatkes = 0;
	total_pairs = 0;
	while (i < a.size - 1)
	{
		j = i + 1;
		while (j <= a.size - 1)
		{
			total_pairs = total_pairs + 1;

			if (ft_get_stack(&a, i)->value > ft_get_stack(&a, j)->value)
				misatkes = misatkes + 1;
			j++;
		}
		i++;
	}
	return (((float) misatkes) / total_pairs);
}
