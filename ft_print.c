#include "ft_printf.h"
#include "libft/libft.h"


int check_type(char c)
{
    if(c == 'c')
        return 1;
    else if (c == 's')
        return 2;
    else if (c == 'p')
        return 3;    
    else if (c == 'd')
        return 4;
    else if (c == 'i')
        return 5;
    else if (c == 'u')
        return 6;
    else if (c == 'x')
        return 7;
    else if (c == 'X')
        return 8;
    else if (c == '%')
        return 9;
    return 0;
}


int ft_printf(const char *mandatory,...)
{
    int i = 0;
    int type;

    va_list params;
    va_start(params,mandatory);

    while(mandatory[i])
    {
        if (mandatory[i] == '%')
        {
            i += 2;
            type = check_type(mandatory[i - 1]);
            if (type == 1)
                ft_putchar_fd(va_arg(params,int),1);
            else if (type == 2)
                ft_putstr_fd(va_arg(params,char *),1);
        }
        ft_putchar_fd(mandatory[i],1);
        i++;
    }
}

#include <stdio.h>
int main()
{
    char *str = "lorenzo";
    ft_printf("ciao ragazzi, io sono %s\n",str);
    printf("ciao ragazzi, io sono %s\n",str);
}