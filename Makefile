NAME = libftprintf.a

LIBFT_SRC = libft/ft_strdup.c\
			libft/ft_strlen.c\

FT_PRINTF_SRC = ft_printf.c\
			ft_format_recognizer.c\
			ft_counter.c\
			ft_putchar_count.c\
			ft_putstr_count.c\
			ft_print_pointer.c

SRC = $(LIBFT_SRC) $(FT_PRINTF_SRC)

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

LIBFT_PATH = /home/doge/ft_printf42/libft/

$(NAME): $(OBJS)
	$(AR) $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT_PATH)/libft.a

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_PATH)/libft.a

re: fclean all

.PHONY: all clean fclean re
