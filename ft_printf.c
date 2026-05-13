/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnououal <mnououal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:43:56 by mnououal          #+#    #+#             */
/*   Updated: 2026/05/13 19:32:29 by mnououal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <limits.h>
#include "push_swap.h"

static int	ft_print_variable(char **str, va_list	*args);
static int	ft_print_pointer_hex(uintptr_t v);
static int	ft_putnbr_usinged(int len, long n);
static int	ft_print_hex(int len, size_t v, int lower_case);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		tot;

	tot = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && ++str)
		{
			if (*str == '\0')
				return (-1);
			tot += ft_print_variable((char **)(&str), &args);
		}
		else if (++tot)
			ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (tot);
}

static int	ft_print_variable(char **str, va_list	*args)
{
	if (**str == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (**str == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (**str == 'p')
		return (ft_print_pointer_hex(va_arg(*args, uintptr_t)));
	else if (**str == 'd')
		return (ft_putnbr(0, va_arg(*args, int)));
	else if (**str == 'i')
		return (ft_putnbr(0, va_arg(*args, int)));
	else if (**str == 'u')
		return (ft_putnbr_usinged(0, (long)va_arg(*args, unsigned int)));
	else if (**str == 'x')
		return (ft_print_hex(0, va_arg(*args, unsigned int), 1));
	else if (**str == 'X')
		return (ft_print_hex(0, va_arg(*args, unsigned int), 0));
	else if (**str == '%')
		return (ft_putchar('%'));
	ft_putchar(*(*str - 1));
	ft_putchar(**str);
	return (2);
}

static int	ft_putnbr_usinged(int len, long n)
{
	char	c;

	if (n > 9)
		len = ft_putnbr_usinged(len, n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (++len);
}

static int	ft_print_pointer_hex(uintptr_t v)
{
	if (!v)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putchar('0');
	ft_putchar('x');
	return (ft_print_hex(0, v, 1) + 2);
}

static int	ft_print_hex(int len, size_t v, int lower_case)
{
	size_t	i;

	if (v >= 16)
		len = ft_print_hex(len, v / 16, lower_case);
	i = v % 16;
	if (i > 9 && !lower_case)
		ft_putchar(i + 'A' - 10);
	else if (i > 9 && lower_case)
		ft_putchar(i + 'a' - 10);
	else
		ft_putchar(i + '0');
	return (++len);
}
