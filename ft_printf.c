#include <stdio.h>
#include <stdlib.h>

void parse_fmt(char fmt, va_list ap)
{
	if (fmt == '%')
		ft_putchar('%');
	else if (fmt == 's')
		ft_putstr();
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
