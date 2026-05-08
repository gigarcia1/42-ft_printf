/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 21:56:28 by gigarcia          #+#    #+#             */
/*   Updated: 2026/05/09 00:55:42 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr(unsigned long long n, unsigned int base, int *w, char h_case)
{
	if (n >= base)
		print_nbr(n / base, base, w, h_case);
	if ((n % base) < 10)
		ft_putchar((n % base) + '0', w);
	else
		ft_putchar(((n % base) - 10) + h_case, w);
}

void	print_int(int n, int *written)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', written);
		nbr = -nbr;
	}
	print_nbr(nbr, 10, written, 0);
}

void	print_ptr(unsigned long long ptr, int *written)
{
	if (!ptr)
	{
		ft_putstr("(nil)", written);
		return ;
	}
	ft_putstr("0x", written);
	print_nbr(ptr, 16, written, 'a');
}
