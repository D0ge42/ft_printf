#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# define CHAR 1
# define STRING 2
# define POINTER 3
# define DECIMAL 4
# define INTEGER 5
# define UNSIGNED 6
# define HEXADECIMAL_LC 7
# define HEXADECIMAL_UP 8
# define PERC '%'

int		ft_printf(const char *mandatory, ...);
void	ft_putchar_count(char c, int *count);
void	ft_putstr_count(char *str, int *count);
int		format_recognizer(char c);
int		percentage_counter(const char *str);
void	ft_print_pointer(uintptr_t nb, int *count);

#endif