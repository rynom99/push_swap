/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 01:03:26 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/12 22:15:22 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

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
}	t_config;

typedef struct s_stack
{
	int	start;
	int	end;
	int	size;
	int	*array;
}	t_stack;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strstr(const char *big, const char *little);
char	**ft_split(char const *s, char c);
int		stack_get(int pos);
#endif
