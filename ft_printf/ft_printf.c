/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:12:27 by grhaddad          #+#    #+#             */
/*   Updated: 2025/06/23 13:41:01 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversions(va_list args, char specifier)
{
	if (specifier == 'c')
		return (handle_char(args));
	else if (specifier == 's')
		return (handle_string(args));
	else if (specifier == 'p')
		return (handle_pointer(args));
	else if (specifier == 'd' || specifier == 'i')
		return (handle_integer(args));
	else if (specifier == 'u')
		return (handle_unsigned(args));
	else if (specifier == 'x')
		return (handle_hex_lower(args));
	else if (specifier == 'X')
		return (handle_hex_upper(args));
	else if (specifier == '%')
		return (handle_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += handle_conversions(args, format[i + 1]);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
