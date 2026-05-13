/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:14:34 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/13 19:33:53 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
