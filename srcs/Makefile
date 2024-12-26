NAME = libftprintf.a

FT_PRINTF_SRC = ft_printf.c\
			ft_format_recognizer.c\
			ft_putchar_count.c\
			ft_putstr_count.c\
			ft_print_pointer.c\
			ft_printnbr_count.c\
			ft_print_hexa.c\
			ft_putstr.c\

SRC = $(FT_PRINTF_SRC)

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM)

fclean: clean
	$(RM) $(NAME)
	$(RM)

re: fclean all

.PHONY: all clean fclean re
