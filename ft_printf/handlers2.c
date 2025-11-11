/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:18:57 by grhaddad          #+#    #+#             */
/*   Updated: 2025/06/21 14:21:00 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hex_lower(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_puthex(n, 0));
}

int	handle_hex_upper(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_puthex(n, 1));
}

int	handle_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
