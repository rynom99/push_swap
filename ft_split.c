/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:11:27 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/12 20:18:01 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		get_nr_str(char const *s, char c);
static size_t	strlen_until_char(const char *s, char c);
static int		is_clean_arr(char **arr, int size);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nr_str;
	char	*ptr;
	char	**arr;

	ptr = (char *)s;
	nr_str = get_nr_str(s, c);
	arr = malloc(sizeof(char *) * (nr_str + 1));
	if (!arr)
		return (arr);
	arr[nr_str] = 0;
	i = 0;
	while (i < nr_str)
	{
		while (*ptr == c)
			ptr++;
		arr[i] = malloc(sizeof(char) * strlen_until_char(ptr, c) + 1);
		if (!is_clean_arr(arr, i))
			return (NULL);
		ft_strlcpy(arr[i], ptr, strlen_until_char(ptr, c) + 1);
		ptr += strlen_until_char(ptr, c);
		i++;
	}
	return (arr);
}

static int	get_nr_str(char const *s, char c)
{
	size_t	counter;
	int		found_else;
	size_t	i;

	i = 0;
	counter = 0;
	found_else = 0;
	while (s[i])
	{
		if (found_else && c == s[i])
			found_else = 0;
		else if (!found_else && c != s[i])
		{
			found_else = 1;
			counter++;
		}
		i++;
	}
	return (counter);
}

static size_t	strlen_until_char(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	is_clean_arr(char **arr, int size)
{
	if (arr[size])
		return (1);
	while (size--)
		free(arr[size]);
	free(arr);
	return (0);
}
