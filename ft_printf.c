/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:40:42 by rhmimchi          #+#    #+#             */
/*   Updated: 2023/11/16 05:16:12 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(va_list ap, char s)
{
	int	count;

	count = 0;
	if (s == 's')
		count += ft_pf_putstr(va_arg(ap, char *));
	if (s == 'c')
		count += ft_pf_putchar(va_arg(ap, int));
	if (s == 'd' || s == 'i')
		count += ft_pf_putnbr(va_arg(ap, int));
	if (s == 'u')
		count += ft_pf_unsignedint(va_arg(ap, unsigned int));
	if (s == 'x')
		count += ft_pf_hex_l(va_arg(ap, unsigned int));
	if (s == 'X')
		count += ft_pf_hex_u(va_arg(ap, unsigned int));
	if (s == 'p')
		count += ft_pf_adress(va_arg(ap, void *));
	if (s != 'p' && s != 'x' && s != 'X' && s != 'u' && 
		s != 'd' && s != 'i' && s != 'c' && s != 's')
		count += ft_pf_putchar(s);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	ap;

	count = 0;
	i = 0;
	va_start(ap, s);
	if (write(1, "", 0) == -1)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			count += print_type(ap, s[i + 1]);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
