/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:30:06 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/13 15:32:50 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_empty(char c)
{
	return (c == ' ' || (c > 8 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
	int	summirizer;
	int	is_positive;
	int	i;

	is_positive = 1;
	summirizer = 0;
	i = 0;
	while (is_empty(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		is_positive = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		summirizer *= 10;
		summirizer += (nptr[i] - '0');
		i++;
	}
	return (summirizer * is_positive);
}
