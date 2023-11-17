/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:10:29 by rhmimchi          #+#    #+#             */
/*   Updated: 2023/11/14 23:34:55 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_count(unsigned long n)
{
	int	s;

	s = 1;
	while (n > 15)
	{
		n = n / 16;
		s++;
	}
	return (s);
}

static void	ft_hex_low(unsigned long n)
{
	char	*ar;

	ar = "0123456789abcdef";
	if (n >= 0 && n <= 15)
	{
		ft_pf_putchar(ar[n % 16]);
	}
	else
	{
		ft_hex_low(n / 16);
		ft_hex_low(n % 16);
	}
}

static int	ft_pf_hex(unsigned long n)
{
	int	count;

	count = len_count(n);
	ft_hex_low(n);
	return (count);
}

int	ft_pf_adress(void *adress)
{
	unsigned long	l;

	l = (unsigned long)adress;
	ft_pf_putstr("0x");
	return (ft_pf_hex(l) + 2);
}
