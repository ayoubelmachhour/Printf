/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printftwo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mac <ayel-mac@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 22:58:26 by username          #+#    #+#             */
/*   Updated: 2026/11/15 23:50:32 by ayel-mac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char format)
{
	char	c;
	char	*base;
	int		count;

	count = 0;
	if (format == 'x')
	{
		base = "0123456789abcdef";
	}
	else
	{
		base = "0123456789ABCDEF";
	}
	if (n >= 16)
	{
		count += ft_puthex(n / 16, format);
	}
	c = base[n % 16];
	count += write(1, &c, 1);
	return (count);
}

int	ft_puthex_ptr(unsigned long n)
{
	char	c;
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_puthex_ptr(n / 16);
	}
	c = base[n % 16];
	count += write(1, &c, 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		return (write(1, "(nil)", 5));
	}
	count += write(1, "0x", 2);
	count += ft_puthex_ptr((unsigned long) ptr);
	return (count);
}
