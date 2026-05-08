/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_text.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 21:56:16 by gigarcia          #+#    #+#             */
/*   Updated: 2026/05/09 00:55:28 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *written)
{
	*written += write(1, &c, 1);
}

void	ft_putstr(char *str, int *written)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str, written);
		str++;
	}
}
