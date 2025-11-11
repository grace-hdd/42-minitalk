/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:02:38 by grhaddad          #+#    #+#             */
/*   Updated: 2025/06/21 14:23:34 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_puthex(unsigned int n, int uppercase);
int	ft_putptr(void *ptr);
int	ft_putnbr_unsigned(unsigned int n);
int	handle_char(va_list args);
int	handle_string(va_list args);
int	handle_integer(va_list args);
int	handle_unsigned(va_list args);
int	handle_pointer(va_list args);
int	handle_percent(void);
int	handle_hex_upper(va_list args);
int	handle_hex_lower(va_list args);
int	handle_conversions(va_list args, char specifier);

#endif