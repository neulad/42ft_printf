/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:52:02 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/30 22:07:34 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_upper_x_len(unsigned long long ptr)
{
	int n;

	n = 0;
	while (ptr && ++n)
		ptr /= 16;
	return (n);
}

static void	ft_upper_x_print(unsigned long long ptr)
{
	if (ptr <= 9)
		return (ft_putchar(ptr + '0'));
	if (ptr <= 15)
		return (ft_putchar(ptr % 10 + 'a'));
	ft_upper_x_print(ptr / 16);
	ft_upper_x_print(ptr % 16);
}

int	ft_print_upper_x(va_list args)
{
	unsigned int	d;
	int				len;

	d = va_arg(args, unsigned int);
	len = ft_upper_x_len(d);
	ft_upper_x_print(d);
	return (len);
}
