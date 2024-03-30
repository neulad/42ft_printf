/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:58:14 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/30 16:42:21 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flag(char **s, va_list args)
{
	if (**s == 'c')
		return (ft_printc(s, args));
	// if (c == 's')
	// 	return ();
	// if (c == 'p')
	// 	return ();
	// if (c == 'd')
	// 	return ();
	// if (c == 'i')
	// 	return ();
	// if (c == 'd')
	// 	return ();
	// if (c == 'i')
	// 	return ();
	// if (c == 'u')
	// 	return ();
	// if (c == 'x')
	// 	return ();
	// if (c == 'X')
	// 	return ();
	// if (c == '%')
	// 	return ();
	return (NULL);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;

	if (!fmt)
		return (NULL);
	len = 0;
	va_start(args, fmt);
	while(*fmt)
	{
		if (*fmt != '%')
			len += write(1, fmt, 1);
		else
			len += ft_print_flag(&fmt, args);
		fmt++;
	}
}
