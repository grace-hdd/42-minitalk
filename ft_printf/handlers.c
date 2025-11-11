/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:07:07 by grhaddad          #+#    #+#             */
/*   Updated: 2025/06/21 14:20:36 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	handle_string(va_list args)
{
	char	*s;
	int		len;

	s = (char *)va_arg(args, char *);
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len);
}

int	handle_pointer(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	return (ft_putptr(ptr));
}

int	handle_integer(va_list args)
{
	int		n;
	char	*str;
	int		count;

	n = va_arg(args, int);
	str = ft_itoa(n);
	if (!str)
		return (0);
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}

int	handle_unsigned(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putnbr_unsigned(n));
}
