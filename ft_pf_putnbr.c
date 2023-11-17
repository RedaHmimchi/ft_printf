/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:44:24 by rhmimchi          #+#    #+#             */
/*   Updated: 2023/11/13 22:44:12 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_count(int n)
{
	int	s;

	s = 1;
	if (n < 0)
	{
		s = 2;
		n *= (-1);
	}
	while (n > 9)
	{
		n = n / 10;
		s++;
	}
	return (s);
}

static void	ft_putnbr(int n)
{
	if (n >= 0 && n <= 9)
	{
		ft_pf_putchar(n + '0');
	}
	else if (n < 0)
	{
		ft_pf_putchar('-');
		ft_putnbr(n * (-1));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_pf_putnbr(int n)
{
	int	count;

	count = len_count(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	ft_putnbr(n);
	return (count);
}
