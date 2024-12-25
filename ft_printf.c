#include "ft_printf.h"
#include "libft/libft.h"
#include <stdint.h>
#include <stdio.h>

int	ft_printf(const char *mandatory, ...)
{
	int		count;
	va_list	args;
	int		i;
	void	*ptr;
	char	*str;

	count = 0;
	va_start(args, mandatory);
	i = 0;
	while (mandatory[i])
	{
		if (mandatory[i] == '%')
		{
			i += 2;
			char c = mandatory[i - 1];
			if (format_recognizer(c) == CHAR)
				ft_putchar_count(va_arg(args, int), &count);
			if (format_recognizer(c) == STRING)
			{
				str = va_arg(args, char *);
				if (!str)
					ft_putstr_count("(null)", &count);
				else
					ft_putstr_count(str, &count);
			}
			if (format_recognizer(c) == POINTER)
			{
				ptr = va_arg(args, void *);
				if (!ptr)
					ft_putstr_count("(nil)", &count);
				else
				{
					ft_putchar_count('0', &count);
					ft_putchar_count('x', &count);
					ft_print_pointer((uintptr_t)ptr, &count);
				}
			}
			if (format_recognizer(c) == DECIMAL
				|| format_recognizer(c) == INTEGER)
				ft_printnb_count(va_arg(args, int), &count);
			if (format_recognizer(c) == UNSIGNED)
				ft_printnb_count(va_arg(args, unsigned), &count);
			if (format_recognizer(c) == HEXADECIMAL_LC)
				ft_print_hexa(va_arg(args, unsigned int), &count, 'x');
			if (format_recognizer(c) == HEXADECIMAL_UP)
				ft_print_hexa(va_arg(args, unsigned int), &count, 'X');
			if (format_recognizer(c) == PERC)
					ft_putchar_count('%', &count);
		}
		else
			ft_putchar_count(mandatory[i++], &count);
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("%i\n",2147483649);
}