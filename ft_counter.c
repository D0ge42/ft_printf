#include "ft_printf.h"

int	percentage_counter(const char *str)
{
	int i = 0;
	int counter = 0;
	while (str[i])
	{
		if (str[i] == '%')
			counter++;
		i++;
	}
	return (counter);
}