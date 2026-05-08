/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 22:52:42 by gigarcia          #+#    #+#             */
/*   Updated: 2026/05/09 01:18:10 by gigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
void	print_nbr(unsigned long long n, unsigned int base, int *w, char h_case);
void	print_int(int n, int *written);
void	print_ptr(unsigned long long ptr, int *written);
void	ft_putchar(char c, int *written);
void	ft_putstr(char *str, int *written);

#endif
