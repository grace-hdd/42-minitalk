/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:00:27 by grhaddad          #+#    #+#             */
/*   Updated: 2025/06/23 13:16:58 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
	count ++;
	return (count);
}

static int	ft_puthex_long(unsigned long n, int uppercase)
{
	int		count;
	char	*hex;

	count = 0;
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_long(n / 16, uppercase);
	ft_putchar_fd(hex[n % 16], 1);
	count++;
	return (count);
}

int	ft_puthex(unsigned int n, int uppercase)
{
	int		count;
	char	*hex;

	count = 0;
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	ft_putchar_fd(hex[n % 16], 1);
	count++;
	return (count);
}

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	adr;

	count = 0;
	adr = (unsigned long)ptr;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	count += 2;
	count += ft_puthex_long(adr, 0);
	return (count);
}
