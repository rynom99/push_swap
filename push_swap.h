/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 01:03:26 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/16 20:21:18 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1

enum e_mode
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
};

typedef struct s_config
{
	enum e_mode	mode;
	int			is_bench_mode;
	int			is_valid;
	float		disorder;
}	t_config;

typedef struct s_tuple
{
	int	value;
	int	rank;
}	t_tuple;

typedef struct s_stack
{
	int		start;
	int		end;
	int		max_size;
	int		size;
	t_tuple	**array;
}	t_stack;

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strcmp(const char *s1, const char *s2);
char		**ft_split(char const *s, char c);
t_tuple		*ft_get_stack(t_stack *stack, int index);
t_tuple		**ft_get_stack_ref(t_stack *stack, int index);
int			ft_foreach_stack(
				t_stack *stack,
				int (*fn)(int, t_stack *, t_tuple**, void*),
				void *extra);
int			ft_putstr(char *s);
int			ft_putnbr(int len, int n);
int			ft_putchar(char c);
int			ft_printf(const char *str, ...);
int			ft_str_to_int32(const char *nptr, int *value);
int			ft_isdigit(int c);
char		**join_arr(char **arr1, char **arr2);
void		set_arr(char ***str, char **value);
int			ft_arr_len(void *arr);
int			ft_log_ops(int enable);
void		ft_log(char *s);
float		ft_disorder(t_stack a);
int			sa(t_stack *a);
int			sb(t_stack *a);
int			ss(t_stack *a, t_stack *b);
int			pa(t_stack *a, t_stack *b);
int			pb(t_stack *a, t_stack *b);
int			ra(t_stack *a);
int			rb(t_stack *b);
int			rr(t_stack *a, t_stack *b);
int			rra(t_stack *a);
int			rrb(t_stack *b);
int			rrr(t_stack *a, t_stack *b);
void		ft_set_ranks(t_stack *a);
void		simple_algorithm(t_stack *stack_a, t_stack *stack_b);
void		medium_algorithm(t_stack *stack_a, t_stack *stack_b);
void		case2_algorithm(t_stack *a);
void		case3_algorithm(t_stack *a);
void		print_stack(t_stack stack_a, t_stack stack_b);
t_config	init_app(
				t_stack *stack_a,
				t_stack *stack_b,
				int argc,
				char *argv[argc]);
int			find_rank_position(t_stack *stack, int target_rank);
void		clean_stack(t_stack *stack);
#endif
