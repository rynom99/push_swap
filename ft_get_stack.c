/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:30:55 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/13 00:43:17 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tuple	*ft_get_stack(t_stack stack, int index)
{
	return (stack.array + ((index + stack.start) % stack.max_size));
}
