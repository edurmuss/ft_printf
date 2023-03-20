/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurmus <edurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:50:56 by edurmus           #+#    #+#             */
/*   Updated: 2023/03/20 13:52:32 by edurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (ft_putstr("(null)"));
	while (++i, s[i])
		ft_putchar(s[i]);
	return (i);
}

int	ft_putnbr_base(long long n, char *base_c, int base)
{
	int	res;
	int	i;
	int	n_backwards[100];

	res = 0;
	i = 0;
	if (n < 0 && base == 10)
	{
		res += ft_putchar('-');
		n *= -1;
	}
	if (n == 0)
		return (ft_putchar('0'));
	while (n)
	{
		n_backwards[i] = n % base;
		n /= base;
		i++;
	}
	while (i--)
		res += ft_putchar(base_c[n_backwards[i]]);
	return (res);
}

int	ft_sort(char c, va_list *args)
{
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(*args, int), "0123456789", 10));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), \
			"0123456789abcdef", 16));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), \
			"0123456789ABCDEF", 16));
	else if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 'p')
		return (ft_putstr("0x") + ft_putnbr_base_u(va_arg(*args, \
			unsigned long long), "0123456789abcdef", 16));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(*args, unsigned int), "0123456789", 10));
	else
		return (ft_putchar(c));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start (args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			res += ft_sort(s[i], &args);
			i++;
		}
		else
		{
			res += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (res);
}
/*
int	main(void)
{
	int a = ft_printf("%x", 163);
	ft_printf("\n%d    ",a);
}*/
