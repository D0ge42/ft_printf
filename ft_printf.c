#include "ft_printf.h"
#include "libft/libft.h"

int	check_type(char c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'd')
		return (4);
	else if (c == 'i')
		return (5);
	else if (c == 'u')
		return (6);
	else if (c == 'x')
		return (7);
	else if (c == 'X')
		return (8);
	else if (c == '%')
		return (9);
	return (0);
}

int ft_putchar(char c)
{
    write(1,&c,1);
    return 1;   
}

int ft_putnbr_base(long long nb)
{
    int total = 0;
    char *lcbase = "0123456789abcdef";
    if(nb > 16)
        ft_putnbr_base(nb/16);   
	total += ft_putchar(lcbase[nb%16]);
	return total;
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *mandatory, ...)
{
	int		i;
	int		type;
	int		j;
    int to_add = 0;
	va_list	params;

	i = 0;
	j = 0;
    if(ft_strncmp(mandatory,"",1) == 0)
        return 0;
	va_start(params, mandatory);
	while (mandatory[i])
	{
		if (mandatory[i] == '%')
		{
			i += 2;
			type = check_type(mandatory[i - 1]);
			if (type == 1)
				ft_putchar_fd(va_arg(params, int), 1);
			else if (type == 2)
				to_add = ft_putstr(va_arg(params, char *));
			else if (type == 4 || type == 5)
				ft_putnbr_fd(va_arg(params, int), 1);
            else if (type == 3)
            {
                ft_putchar_fd('0',1);
                ft_putchar_fd('x',1);
                to_add += ft_putnbr_base(va_arg(params,long long));
            }
		}
		ft_putchar_fd(mandatory[i], 1);
		i++;
	}
	return ((i - 2) + to_add);
}

#include <stdio.h>

int	main(void)
{
    void *sium;
	// printf("%i\n",ft_printf("Indirizzo %p\n", sium));
    // printf("%i\n",printf("Indirizzo %p\n",sium));
	printf("Numero %i\n",ft_putnbr_base(8901284098));
}