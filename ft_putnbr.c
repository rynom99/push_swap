/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:22:31 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/01 15:25:38 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

int	ft_putnbr(int len, int n)
{
	char	c;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0 && ++len)
	{
		n = n * -1;
		write(1, "-", 1);
	}
	if (n > 9)
		len = ft_putnbr(len, n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (++len);
}
