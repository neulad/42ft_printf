/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:16:22 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/03/30 18:10:47 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prints(va_list args)
{
	char	*cs;
	int		n;

	cs = va_arg(args, char *);
	while (*cs)
	{
		write(1, cs++, 1);
		n++;
	}
	return (n);
}
