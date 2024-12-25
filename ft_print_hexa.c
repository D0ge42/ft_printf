#include "ft_printf.h"

void	ft_print_hexa(unsigned int nb, int *count, char c)
{
	if (c == 'x')
	{
		char *lcbase = "0123456789abcdef";
		if (nb >= 16)
			ft_print_hexa(nb / 16, count, 'x');
		ft_putchar_count(lcbase[nb % 16], count);
	}
	else if (c == 'X')
	{
		char *lcbase = "0123456789ABCDEF";
		if (nb >= 16)
			ft_print_hexa(nb / 16, count, 'X');
		ft_putchar_count(lcbase[nb % 16], count);
	}
}