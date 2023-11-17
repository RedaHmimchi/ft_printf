/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_unsignedint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:20:39 by rhmimchi          #+#    #+#             */
/*   Updated: 2023/11/14 23:35:31 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_count(unsigned int n)
{
	int	s;

	s = 1;
	while (n > 9)
	{
		n = n / 10;
		s++;
	}
	return (s);
}

static void	ft_putnbr(unsigned int n)
{
	if (n >= 0 && n <= 9)
	{
		ft_pf_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_pf_unsignedint(unsigned int n)
{
	int	count;

	count = len_count(n);
	ft_putnbr(n);
	return (count);
}
