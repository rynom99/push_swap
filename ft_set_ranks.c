/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ranks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 22:01:26 by malshare          #+#    #+#             */
/*   Updated: 2026/05/13 23:21:53 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort( int *temp, t_stack *a)
{
	int	swap;
	int	i;
	int	j;

	i = 0;
	while (i < a->size - 1)
	{
		j = 0;
		while (j < a->size - i - 1)
		{
			if (temp[j] > temp[j + 1])
			{
				swap = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}

static void	compare_stack_values_to_sorted_array(t_stack *a, int *temp)
{
	int		i;
	int		j;
	t_tuple	*current_item;

	i = 0;
	while (i < a->size)
	{
		current_item = ft_get_stack(a, i);
		j = 0;
		while (j < a->size)
		{
			if (current_item->value == temp[j])
			{
				current_item->rank = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_set_ranks(t_stack *a)
{
	int	*temp;
	int	i;

	temp = malloc(sizeof(int) * a->size);
	if (!temp)
		return ;
	i = 0;
	while (i < a->size)
	{
		temp[i] = ft_get_stack(a, i)->value;
		i++;
	}
	bubble_sort(temp, a);
	compare_stack_values_to_sorted_array(a, temp);
	free(temp);
}
// int compute_disorder(stack a):
// mistakes = 0
// total_pairs = 0
// for i from 0 to size(a)-1:
// for j from i+1 to size(a)-1:
// total_pairs += 1
// if a[i] > a[j]:
// mistakes += 1
// return (mistakes / total_pairs);



//  first algorithem : check for the minimum element in the stak 
// chek if it is closer to top or buttom
// push it to the nearest eadge
//  push it to stake b

// int find_min_index(t_stack *a)
// {

//void	ft_set_ranks(t_stack *a)

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

// int	find_minimum_number_index(t_stack a)
// {
// 	int	i;
// 	int	small;

// 	i = a.start;
// 	small = a.array[a.start];
// 	while (i < a.e)
// 	{
// 		if (a.array[i] < small)
// 			small = i;
// 		i ++;
// 	}
// 	return (small);
// }
