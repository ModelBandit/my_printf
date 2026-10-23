

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
int ft_printf(const char *, ...);
int print_tail(size_t target, const char *convert, int count);
int my_print_convert(void* target, const char *convert);
int	my_print_int(int target);
int	my_print_uint(unsigned int target);
int	my_print_hexa(unsigned int target, const char *convert);
int	my_print_string(void *target);
#endif