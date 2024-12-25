#include "ft_printf.h"

void	ft_putstr_count(char *str, int *count,va_list args);
{
	while (*str)
	{
		write(1, str++, 1);
		*count += 1;
	}
}