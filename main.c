//cc -Wall -Wextra -Werror main.c -L. -lftprintf -o tester

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int ori;
	int ft;
	char *null_str = NULL;
	void *null_ptr = NULL;
	int min = INT_MIN;
	char *str = "Proyecto 42";
	int a = 1, b = 2, c = 3;

	printf("\n==========================================\n");
	printf("                TEST FT_PRINTF              \n");
	printf("==========================================\n\n");

	// --- 1. Pruebas sencillas (todas las conversiones base) ---
	printf("--- 1. Pruebas sencillas ---\n");
	ori = printf("ORI: Char: %c, Str: %s, Dec: %d, Int: %i, Uns: %u, Hex_min: %x, Hex_MAY: %X, Pct: %%\n", 'Z', "Hola", 42, -42, 4294967295U, 255, 255);
	ft = ft_printf(" FT: Char: %c, Str: %s, Dec: %d, Int: %i, Uns: %u, Hex_min: %x, Hex_MAY: %X, Pct: %%\n", 'Z', "Hola", 42, -42, 4294967295U, 255, 255);
	printf("-> Retorno ORI: %d | Retorno FT: %d\n\n", ori, ft);

	// --- 2. Casos especiales ---
	printf("--- 2. Casos especiales ---\n");
	ori = printf("ORI: Cero: %d, INT_MIN: %i, Vacio: [%s], Nulo: %s, Ptr Nulo: %p\n", 0, min, "", null_str, null_ptr);
	ft = ft_printf(" FT: Cero: %d, INT_MIN: %i, Vacio: [%s], Nulo: %s, Ptr Nulo: %p\n", 0, min, "", null_str, null_ptr);
	printf("-> Retorno ORI: %d | Retorno FT: %d\n\n", ori, ft);

	// --- 3. Múltiples conversiones/argumentos ---
	printf("--- 3. Multiples conversiones mezcladas ---\n");
	ori = printf("ORI: %c | %s | %p | %d | %i | %u | %x | %X | %%\n", 'A', str, &str, 123, -456, 789, 0xabcdef, 0xABCDEF);
	ft = ft_printf(" FT: %c | %s | %p | %d | %i | %u | %x | %X | %%\n", 'A', str, &str, 123, -456, 789, 0xabcdef, 0xABCDEF);
	printf("-> Retorno ORI: %d | Retorno FT: %d\n\n", ori, ft);

	// --- 4. En medio de una frase (con caracteres antes y después) ---
	printf("--- 4. Conversiones en medio de una frase ---\n");
	ori = printf("ORI: << El estudiante saco un %d%% en su %s, y la direccion es %p >>\n", 100, "evaluacion", &a);
	ft = ft_printf(" FT: << El estudiante saco un %d%% en su %s, y la direccion es %p >>\n", 100, "evaluacion", &a);
	printf("-> Retorno ORI: %d | Retorno FT: %d\n\n", ori, ft);

	// --- 5. Varias del mismo tipo seguidas ---
	printf("--- 5. Varias conversiones del mismo tipo seguidas ---\n");
	ori = printf("ORI: Enteros: %d%d%d | Strings: %s%s%s | Hex: %x%x%x\n", a, b, c, "Un", "Dos", "Tres", 10, 11, 12);
	ft = ft_printf(" FT: Enteros: %d%d%d | Strings: %s%s%s | Hex: %x%x%x\n", a, b, c, "Un", "Dos", "Tres", 10, 11, 12);
	printf("-> Retorno ORI: %d | Retorno FT: %d\n\n", ori, ft);

	return (0);
}
