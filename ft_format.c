/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mac <ayel-mac@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 22:55:58 by username          #+#    #+#             */
/*   Updated: 2026/11/15 23:50:18 by ayel-mac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	if (c == 'c')
	{
		return (ft_putchar(va_arg(args, int)));
	}
	else if (c == 's')
	{
		return (ft_putstr(va_arg(args, char *)));
	}
	else if (c == 'd' || c == 'i')
	{
		return (ft_putnbr(va_arg(args, int)));
	}
	else if (c == 'x' || c == 'X')
	{
		return (ft_puthex(va_arg(args, unsigned int), c));
	}
	else if (c == 'p')
	{
		return (ft_putptr(va_arg(args, void *)));
	}
	else if (c == 'u')
	{
		return (ft_putunsigned(va_arg(args, unsigned int)));
	}else if (c == '%')
	{
		return (ft_putchar(c));
	}
	return (0);
}
