/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 22:01:26 by malshare          #+#    #+#             */
/*   Updated: 2026/05/13 01:05:59 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// int compute_disorder(stack a):
// mistakes = 0
// total_pairs = 0
// for i from 0 to size(a)-1:
// for j from i+1 to size(a)-1:
// total_pairs += 1
// if a[i] > a[j]:
// mistakes += 1
// return (mistakes / total_pairs);

#include "push_swap.h"

float ft_disorder(t_stack a)
{
	int misatkes;
	int total_pairs;
	int i;
	int j;

	i = 0;
	misatkes = 0;
	total_pairs = 0;

	while (i < a.size - 1)
	{
		j = i + 1;
		while (j < a.size - 1)
		{
			total_pairs = total_pairs + 1;
			if (a[i] > a[j])
				misatkes = misatkes + 1;
		}
	}
	return (((float) misatkes) / total_pairs);
}


//  first algorithem : check for the minimum element in the stak 
// chek if it is closer to top or buttom
// push it to the nearest eadge
//  push it to stake b

// int find_min_index(t_stack *a)
// {
//     int min_val = 2147483647; // INT_MAX
//     int min_pos = -1;
//     int current;

//     for (int i = 0; i < a->size; i++)
//     {
//         current = a->array[(a->start + i) % a->size];
//         if (current < min_val)
//         {
//             min_val = current;
//             min_pos = i; // Relative position from the 'start'
//         }
//     }
//     return (min_pos);
// }

int	find_minimum_number_index(t_stack a)
{
	int	i;
	int	small;

	i = a.start;
	small = a.array[a.start];
	while (i < a.e)
	{
		if (a.array[i] < small)
			small = i;
		i ++;
	}
	return (small);
}
