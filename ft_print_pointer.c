#include "ft_printf.h"
#include <stdint.h>

void	ft_print_pointer(uintptr_t nb, int *count)
{
	char *lc_hexa_base = "0123456789abcdef";
	if (nb >= 16)
		ft_print_pointer(nb / 16, count);
	ft_putchar_count(lc_hexa_base[nb % 16], count);
}