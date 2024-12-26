#include "../includes/ft_printf.h"

int	ft_printf(const char *mandatory, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, mandatory);
	while (*mandatory)
	{
		if (*mandatory == '%')
		{
			mandatory++;
			format_recognizer(*(mandatory++), args, &count);
		}
		else
			ft_putchar_count(*(mandatory++), &count);
	}
	va_end(args);
	return (count);
}
