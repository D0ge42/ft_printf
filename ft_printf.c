#include "ft_printf.h"
#include "libft/libft.h"
#include <stdint.h>
#include <stdio.h>

int	ft_printf(const char *mandatory, ...)
{
	int		count;
	va_list	args;
	int		i;
	char	*str;

	count = 0;
	va_start(args, mandatory);
	i = 0;
	while (mandatory[i])
	{
		if (mandatory[i] == '%')
		{
			i += 2;
			if (format_recognizer(mandatory[i - 1]) == CHAR)
				ft_putchar_count(va_arg(args, int), &count);
			if (format_recognizer(mandatory[i - 1]) == STRING)
			{
				str = va_arg(args, char *);
				if (!str)
					ft_putstr_count("(null)", &count);
				else
					ft_putstr_count(str, &count);
			}
			if (format_recognizer(mandatory[i - 1]) == POINTER)
			{
				
				ft_putchar_count('0', &count);
				ft_putchar_count('x', &count);
				ft_print_pointer(va_arg(args, uintptr_t), &count);
			}
		}
		if (mandatory[i])
			ft_putchar_count(mandatory[i++], &count);
	}
	va_end(args);
	return (count); // Lenght of string without formats specifiers.
}

int main()
{
	printf("%i\n",ft_printf(" %p %p ", 0, 0));
	printf("%i\n",printf(" %p %p ", NULL, NULL));
}