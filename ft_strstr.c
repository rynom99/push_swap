/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:34:40 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/12 20:41:34 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	size_big;
	size_t	size_little;

	if (little[0] == 0)
		return ((char *)big);
	size_little = ft_strlen(little);
	size_big = ft_strlen(big);
	if (size_big < size_little)
		return (NULL);
	i = 0;
	while (size_big >= size_little)
	{
		if (!ft_strncmp(big + i, little, size_little))
			break ;
		i++;
		size_big--;
	}
	return ((char *)big + i);
}
