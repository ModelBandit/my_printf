
NAME = libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
TEST_DIR = printfTester

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRC = ft_printf.c \
my_print_convert.c \
my_print_int.c \
my_print_utils.c \
my_print_string.c \
my_print_uint.c \
my_print_hexa.c

OBJ = $(SRC:.c=.o)

all:  $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

test:
	$(MAKE) -C $(TEST_DIR)

.PHONY: all clean fclean re test
