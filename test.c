#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_base(unsigned long long n, int base, int *written, char hex_case);

void	ft_putchar(char c, int *written)
{
	*written += write(1, &c, 1);
}

void	print_int(int n, int *written)
{
	if (n < 0)
		ft_putchar('-', written);
	ft_putnbr_base((unsigned long long)n, 10, written, 0);
}

void	ft_putnbr_base(unsigned long long n, int base, int *written, char hex_case)
{
	if ((int)n >= base)
		ft_putnbr_base(n / base, base, written, hex_case);
	if (((int)n % base) < 10)
		ft_putchar((n % base) + '0', written);
	else
		ft_putchar(((n % base) - 10) + hex_case, written);
}

int main ()
{
	int i = 2147483648;
	int written = 0;
	ft_putnbr_base(i, 10, &written, 0);
	printf("\n");
	printf("%d", i);
	printf("\n");
}