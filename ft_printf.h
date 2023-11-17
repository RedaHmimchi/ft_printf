/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:25:25 by rhmimchi          #+#    #+#             */
/*   Updated: 2023/11/13 22:25:26 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_pf_putstr(char *s);
int	ft_pf_putchar(int c);
int	ft_pf_putnbr(int n);
int	ft_pf_adress(void *adress);
int	ft_pf_unsignedint(unsigned int n);
int	ft_pf_hex_l(unsigned int n);
int	ft_pf_hex_u(unsigned int n);

#endif