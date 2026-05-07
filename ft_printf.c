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

void parse_fmt(char	c, va_list ap)
{
	if (c == '%')
		ft_putchar('%');
	else if (c == 's')
		ft_putstr(va_list(c, char *));
	else if (c == 'c')
		ft_putchar((char)va_list(c, int));
	

	//Check for NULL dereferencing. If char *ptr = NULL and ft_printf("%p", &ptr), the return shouldn't be NULL, but NIL (when trying to dereference the memory address of a NULL)
}

int ft_printf(char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	if (!fmt)
		return (-1);
	while (*fmt)
	{
		if (*fmt == '%')
			parse_fmt(*(fmt + 1));
		fmt++;
	}
	va_end(ap);
}
