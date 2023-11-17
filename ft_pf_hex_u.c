/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_hex_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:02:44 by rhmimchi          #+#    #+#             */
/*   Updated: 2023/11/14 23:35:05 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_count(unsigned int n)
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

static void	ft_hex_upper(unsigned int n)
{
	char	*ar;

	ar = "0123456789ABCDEF";
	if (n >= 0 && n <= 15)
	{
		ft_pf_putchar(ar[n % 16]);
	}
	else
	{
		ft_hex_upper(n / 16);
		ft_hex_upper(n % 16);
	}
}

int	ft_pf_hex_u(unsigned int n)
{
	int	count;

	count = len_count(n);
	ft_hex_upper(n);
	return (count);
}
