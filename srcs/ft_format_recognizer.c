#include "../includes/ft_printf.h"

int	format_recognizer(char c, va_list args, int *count)
{
	if (c == CHAR)
		ft_putchar_count(va_arg(args, int), count);
	else if (c == STRING)
		ft_putstr_count(args, count);
	else if (c == POINTER)
		ft_print_pointer(va_arg(args, uintptr_t), count, -1);
	else if (c == DECIMAL || c == INTEGER)
		ft_printnb_count(va_arg(args, int), count);
	else if (c == UNSIGNED)
		ft_printnb_count(va_arg(args, unsigned), count);
	else if (c == HEXADECIMAL_LC)
		ft_print_hexa(va_arg(args, unsigned int), count, 'x');
	else if (c == HEXADECIMAL_UP)
		ft_print_hexa(va_arg(args, unsigned int), count, 'X');
	else if (c == PERC)
		ft_putchar_count('%', count);
	return (0);
}
