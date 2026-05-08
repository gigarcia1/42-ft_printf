#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *fmt, ...);

int main(void)
{
	int ft_ret;
	int ori_ret;

	// Variables para testear
	char			*str = "¡Hola 42!";
	char			*null_str = NULL;
	void			*ptr = &str;
	void			*null_ptr = NULL;
	int				min = INT_MIN;
	int				max = INT_MAX;
	unsigned int	u_max = UINT_MAX;

	printf("\n=========================================\n");
	printf("   BATALLA FINAL: ft_printf vs printf\n");
	printf("=========================================\n\n");

	// --- 1. CARACTERES Y STRINGS (%c, %s, %%) ---
	printf("--- TEST %%c, %%s, %%%% ---\n");
	ori_ret = printf("ORI: Caracter: %c, String: %s, Vacio: %s, Nulo: %s, Porcentaje: %%\n", 'Z', str, "", null_str);
	ft_ret = ft_printf(" FT: Caracter: %c, String: %s, Vacio: %s, Nulo: %s, Porcentaje: %%\n", 'Z', str, "", null_str);
	printf("-> Retorno ORI: %d | Retorno FT: %d\n\n", ori_ret, ft_ret);

	// --- 2. ENTEROS CON SIGNO (%d, %i) ---
	printf("--- TEST %%d, %%i (Limites) ---\n");
	ori_ret = printf("ORI: Cero: %d, Positivo: %i, Negativo: %d, INT_MAX: %d, INT_MIN: %i\n", 0, 42, -42, max, min);
	ft_ret = ft_printf(" FT: Cero: %d, Positivo: %i, Negativo: %d, INT_MAX: %d, INT_MIN: %i\n", 0, 42, -42, max, min);
	printf("-> Retorno ORI: %d | Retorno FT: %d\n\n", ori_ret, ft_ret);

	// --- 3. ENTEROS SIN SIGNO (%u) ---
	printf("--- TEST %%u (Unsigned) ---\n");
	ori_ret = printf("ORI: Cero: %u, Positivo: %u, UINT_MAX: %u\n", 0, 42, u_max);
	ft_ret = ft_printf(" FT: Cero: %u, Positivo: %u, UINT_MAX: %u\n", 0, 42, u_max);
	printf("-> Retorno ORI: %d | Retorno FT: %d\n\n", ori_ret, ft_ret);

	// --- 4. HEXADECIMALES (%x, %X) ---
	printf("--- TEST %%x, %%X (Hexadecimales) ---\n");
	ori_ret = printf("ORI: Cero: %x, Num: %x, MAYUS: %X, MAX: %x, NEGATIVO: %x\n", 0, 255, 255, u_max, -50);
	ft_ret = ft_printf(" FT: Cero: %x, Num: %x, MAYUS: %X, MAX: %x, NEGATIVO: %x\n", 0, 255, 255, u_max, -50);
	printf("-> Retorno ORI: %d | Retorno FT: %d\n\n", ori_ret, ft_ret);

	// --- 5. PUNTEROS (%p) ---
	printf("--- TEST %%p (Punteros) ---\n");
	ori_ret = printf("ORI: Puntero real: %p, Puntero Nulo: %p\n", ptr, null_ptr);
	ft_ret = ft_printf(" FT: Puntero real: %p, Puntero Nulo: %p\n", ptr, null_ptr);
	printf("-> Retorno ORI: %d | Retorno FT: %d\n\n", ori_ret, ft_ret);

	printf("=========================================\n");
	printf("Si los retornos coinciden, ¡TIENES EL 100%%!\n");
	printf("=========================================\n\n");

	return (0);
}
