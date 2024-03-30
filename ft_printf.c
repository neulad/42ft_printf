/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:58:14 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/30 18:17:59 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flag(char const *fmt, va_list args)
{
	if (*fmt== 'c')
		return (ft_printc(args));
	if (*fmt == 's')
		return (ft_prints(args));
	if (*fmt == 'p')
		return (ft_printp(args));
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
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;
	int		bytes_wrote;

	if (!fmt)
		return (0);
	len = 0;
	va_start(args, fmt);
	while(*fmt)
	{
		if (*fmt != '%')
			len += write(1, fmt, 1);
		else
		{
			++fmt;
			bytes_wrote = ft_print_flag((char *)fmt, args);
			if (bytes_wrote < 0)
				return (-1);
			len += bytes_wrote;
		}
		++fmt;
	}
	return (len);
}

#include <stdio.h>
int	main(void)
{
	int n = ft_printf("Hellitch%s\n", "");
	printf("Bytes read: %d", n);
	return (0);
}
