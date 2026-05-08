/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 21:55:56 by gigarcia          #+#    #+#             */
/*   Updated: 2026/05/09 00:58:39 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_fmt(char c, va_list *ap, int *written)
{
	if (c == '%')
		ft_putchar('%', written);
	else if (c == 's')
		ft_putstr(va_arg(*ap, char *), written);
	else if (c == 'c')
		ft_putchar((char)va_arg(*ap, int), written);
	else if (c == 'i' || c == 'd')
		print_int(va_arg(*ap, int), written);
	else if (c == 'u')
		print_nbr(va_arg(*ap, unsigned int), 10, written, 0);
	else if (c == 'x')
		print_nbr(va_arg(*ap, unsigned int), 16, written, 'a');
	else if (c == 'X')
		print_nbr(va_arg(*ap, unsigned int), 16, written, 'A');
	else if (c == 'p')
		print_ptr(va_arg(*ap, unsigned long), written); //AYUDA IMPORTANTE
			//CASTEAR EL VA_ARG COMO UNSIGNED LONG PARA EVITAR COMPORTAMIENTOS 
			//INDEFINIDOS
}

int	ft_printf(const char *fmt, ...)
{
	int		written;
	va_list	ap;

	va_start(ap, fmt);
	written = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			parse_fmt(*fmt, &ap, &written);
		}
		else
			ft_putchar(*fmt, &written);
		fmt++;
	}
	va_end(ap);
	return (written);
}

/*int main()
{
	int i = 784596;

		ft_printf("hola hola %i hola hola\n\n", i);
		printf("hola hola %i hola hola\n\n", i);
}
*/
