/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:56:01 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/14 22:35:03 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_stack stack_a;
	t_stack stack_b;
	int 	size = 10;

	stack_a.max_size = size;
	stack_a.size = stack_a.max_size;
	stack_a.array = malloc(size * sizeof(t_tuple*));
	stack_a.array[0] = malloc(sizeof(t_stack));
	stack_a.array[0]->value = 0;
	stack_a.array[1] = malloc(sizeof(t_stack));
	stack_a.array[1]->value = 1;
	stack_a.array[2] = malloc(sizeof(t_stack));
	stack_a.array[2]->value = 2;
	stack_a.array[3] = malloc(sizeof(t_stack));
	stack_a.array[3]->value = 3;
	stack_a.array[4] = malloc(sizeof(t_stack));
	stack_a.array[4]->value = 4;
	stack_a.array[5] = malloc(sizeof(t_stack));
	stack_a.array[5]->value = 5;
	stack_a.array[6] = malloc(sizeof(t_stack));
	stack_a.array[6]->value = 6;
	stack_a.array[7] = malloc(sizeof(t_stack));
	stack_a.array[7]->value = 7;
	stack_a.array[8] = malloc(sizeof(t_stack));
	stack_a.array[8]->value = 8;
	stack_a.array[9] = malloc(sizeof(t_stack));
	stack_a.array[9]->value = 9;
	stack_a.start = 0;
	stack_a.end = size - 1;

	stack_b.size = 0;
	stack_b.array = malloc(size * sizeof(t_tuple*));
	stack_b.start = 0;
	stack_b.end = 0;
	stack_b.max_size = stack_a.max_size;

	print_stack(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	ft_printf("\n#################\n");
	ra(&stack_a);
	print_stack(stack_a, stack_b);
	rb(&stack_b);
	print_stack(stack_a, stack_b);
	ra(&stack_a);
	print_stack(stack_a, stack_b);
	rb(&stack_b);
	print_stack(stack_a, stack_b);
	return (0);
}
