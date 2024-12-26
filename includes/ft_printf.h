#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

# define CHAR 'c'
# define STRING 's'
# define POINTER 'p'
# define DECIMAL 'd'
# define INTEGER 'i'
# define UNSIGNED 'u'
# define HEXADECIMAL_LC 'x'
# define HEXADECIMAL_UP 'X'
# define PERC '%'

void	ft_print_pointer(uintptr_t nb, int *count, int flag);
void	ft_print_hexa(unsigned int nb, int *count, char c);
void	ft_printnb_count(long long nb, int *count);
void	ft_putstr_count(va_list args, int *count);
void	ft_putchar_count(char c, int *count);
void	ft_putstr(char *str);

int		format_recognizer(char c, va_list args, int *count);
int		ft_printf(const char *mandatory, ...);
int		ptr_is_null(void *nb, int *count);

#endif