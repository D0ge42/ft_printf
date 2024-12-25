#include "ft_printf.h"

int	format_recognizer(char c)
{
	if (c == 'c')
		return (CHAR);
	else if (c == 's')
		return (STRING);
	else if (c == 'p')
		return (POINTER);
	else if (c == 'd')
		return (DECIMAL);
	else if (c == 'i')
		return (INTEGER);
	else if (c == 'u')
		return (UNSIGNED);
	else if (c == 'x')
		return (HEXADECIMAL_LC);
	else if (c == 'X')
		return (HEXADECIMAL_UP);
	else if (c == '%')
		return (PERC);
	return (0);
}