#include "../includes/ft_printf.h"

int	ptr_is_null(void *nb, int *count)
{
	if (!nb)
	{
		ft_putstr("(nil)");
		*count += 5;
		return (1);
	}
	return (0);
}

void	ft_print_pointer(uintptr_t nb, int *count, int flag)
{
	char	*lc_hexa_base;

	if (ptr_is_null((void *)nb, count) == 1)
		return ;
	if (flag == -1)
	{
		ft_putchar_count('0', count);
		ft_putchar_count('x', count);
	}
	lc_hexa_base = "0123456789abcdef";
	if (nb >= 16)
		ft_print_pointer(nb / 16, count, 1);
	ft_putchar_count(lc_hexa_base[nb % 16], count);
}
