/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_counter_locked.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:57:56 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/15 20:29:29 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_counter_locked(int lock)
{
	static int	status_lock;

	if (lock)
		status_lock = TRUE;
	return (status_lock);
}
