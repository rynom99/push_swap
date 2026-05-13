/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 01:03:26 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/13 21:00:29 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

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

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
t_tuple	*ft_get_stack(t_stack *stack, int index);
t_tuple	**ft_get_stack_ref(t_stack *stack, int index);
int		ft_foreach_stack(
			t_stack *stack,
			int (*fn)(int, t_tuple**, void*),
			void *extra);
int		ft_putstr(char *s);
int		ft_putnbr(int len, int n);
int		ft_putchar(char c);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
float	ft_disorder(t_stack a);
void	sa(t_stack *a);
void	sb(t_stack *a);
void	ss(t_stack *a);
void	ft_set_ranks(t_stack *a);


#endif