/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_int32.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:30:06 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/16 17:49:59 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_empty(char c)
{
	return (c == ' ' || (c > 8 && c <= 13));
}

static int	get_sign(const char *nptr, int *i)
{
	while (is_empty(nptr[*i]))
		*i = (*i) + 1;
	if (nptr[*i] == '+')
		*i = (*i) + 1;
	else if (nptr[*i] == '-')
	{
		*i = (*i) + 1;
		return (-1);
	}
	return (1);
}

int	ft_str_to_int32(const char *nptr, int *value)
{
	long	summirizer;
	int		is_positive;
	int		i;

	i = 0;
	summirizer = 0;
	if (!nptr || !(*nptr))
		return (ERROR);
	is_positive = get_sign(nptr, &i);
	if (!ft_isdigit(nptr[i]))
		return (ERROR);
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		summirizer = (summirizer * 10) + (nptr[i] - '0');
		i++;
		if ((((summirizer * is_positive) > INT_MAX)
				&& ((summirizer * is_positive) < INT_MIN))
			|| (nptr[i] && !ft_isdigit(nptr[i]))
		)
			return (ERROR);
	}
	*value = (summirizer * is_positive);
	return (0);
}
