/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 20:16:43 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/15 20:20:00 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_log_ops(int enable)
{
	static int	print;

	if (enable)
		print = TRUE;
	return (print);
}

void	ft_log(char *s)
{
	if (ft_log_ops(FALSE))
		ft_putstr(s);
}
