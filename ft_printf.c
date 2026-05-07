/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 21:22:09 by gigarcia          #+#    #+#             */
/*   Updated: 2026/05/07 21:37:37 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c, int *written)
{
	*written += write(1, &c, 1);
}

void	ft_putstr(char *str, int *written)
{
	*written += write(1, str, ft_strlen(str));
}

void ft_putnbr(long nbr, int *written)
{
	if (nbr < 0)
	{
		ft_putchar('-', written);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10, written);
	ft_putchar((nbr % 10) + '0', written);
}

void print_hex(int n, int *written, int flag)
{
	int		i;
	int		res;
	
	while (str[i])
	{

		if (flag == 0)
		{
		}
	}
}

void parse_fmt(char	c, va_list ap, int *written)
{
	if (c == '%')
		ft_putchar('%', &written);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), &written);
	else if (c == 'c')
		ft_putchar((char)va_arg(ap, int), &written);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(ap, int), &written);
	else if (c == 'x')
		print_hex(va_arg(ap, char *), &written, 0);
	else if (c == 'X')
		print_hex(va_arg(ap, char *), &written, 1);
	else if (c == 'u')
		ft_putnbr((unsigned int)va_arg(ap, int), &written);
	else if (c == 'p')
		print_memory((unsigned char)va_arg(ap, int), &written);
	//Check for NULL dereferencing. If char *ptr = NULL and ft_printf("%p", &ptr), the return shouldn't be NULL, but NIL (when trying to dereference the memory address of a NULL)
}

int ft_printf(const char *fmt, ...)
{
	int		written;
	va_list ap;
	va_start(ap, fmt);
	if (!fmt)
		return (-1);
	written = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			parse_fmt(*(fmt + 1), ap, &written);
		fmt++;
	}
	va_end(ap);
}
