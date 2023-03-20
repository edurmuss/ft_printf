/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurmus <edurmus@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:51:12 by edurmus           #+#    #+#             */
/*   Updated: 2023/03/20 13:51:13 by edurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_u(unsigned long long n, char *base_c, int base)
{
	int	res;
	int	i;
	int	n_backwards[100];

	res = 0;
	i = 0;
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
