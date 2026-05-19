/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malshare <malshare@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 21:45:16 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/20 00:38:18 by malshare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_arr(char ***str, char **value)
{
	if (value == NULL)
		return (FALSE);
	free(*str);
	*str = value;
	return (TRUE);
}

char	**join_arr(char **arr1, char **arr2)
{
	int		i;
	int		arr1_size;
	int		arr2_size;
	char	**new_arr;

	arr1_size = ft_arr_len(arr1);
	arr2_size = ft_arr_len(arr2);
	new_arr = malloc(sizeof(char *) * (arr1_size + arr2_size + 1));
	if (new_arr == NULL)
		return (new_arr);
	i = 0;
	while (i < arr1_size)
	{
		new_arr[i] = arr1[i];
		i++;
	}
	i = 0;
	while (i < arr2_size)
	{
		new_arr[arr1_size + i] = arr2[i];
		i++;
	}
	new_arr[arr1_size + i] = 0;
	return (new_arr);
}
