
NAME = libftprintf.a
LIBFT_DIR = libft/
TEST_DIR = 2026test/

LIBFT_FILE = ft_atoi.c ft_isdigit.c ft_memset.c ft_strnstr.c ft_bzero.c \
ft_isprint.c ft_strchr.c ft_strrchr.c ft_calloc.c ft_memchr.c \
ft_strlcat.c ft_tolower.c ft_isalnum.c ft_memcmp.c ft_strlcpy.c \
ft_toupper.c ft_isalpha.c ft_memcpy.c ft_strlen.c ft_isascii.c \
ft_memmove.c ft_strncmp.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

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

OBJ = $(SRC:.c=.o) $(LIBFT:.c=.o)

all:  $(NAME)
	echo $(LIBOBJ)

$(NAME): $(LIBOBJ) $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

%.o: %.c ft_printf.h
	echo $(LIBFT)
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
