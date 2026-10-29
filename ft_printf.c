/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 10:23:59 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/29 13:38:32 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_by_type(const char token, va_list vl);

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		i;
	int		covert_count;
	int		spec_count;

	va_start(ap, arg);
	i = 0;
	covert_count = 0;
	spec_count = 0;
	while (arg != NULL && arg[i + covert_count] != '\0')
	{
		if (arg[i + covert_count] == '%')
		{
			spec_count += (print_by_type(*ft_strchr("cspdiuxX%", arg[(i
								+ covert_count) + 1]), ap));
			++covert_count;
		}
		else
			ft_putchar_fd(arg[i + covert_count], 1);
		++i;
	}
	va_end(ap);
	return (i + spec_count);
}

static int	print_by_type(const char token, va_list vl)
{
	int	i;

	i = 0;
	if (token == 'c')
		ft_putchar_fd(va_arg(vl, int), 1);
	else if (token == 's')
		i = my_print_string(va_arg(vl, char *));
	else if (token == 'p')
		i += my_print_convert(va_arg(vl, void *), "0123456789abcdef");
	else if (token == 'd' || token == 'i')
		i = my_print_int(va_arg(vl, int));
	else if (token == 'u')
		i = my_print_uint(va_arg(vl, unsigned int));
	else if (token == 'x')
		i = my_print_hexa(va_arg(vl, unsigned int), "0123456789abcdef");
	else if (token == 'X')
		i = my_print_hexa(va_arg(vl, unsigned int), "0123456789ABCDEF");
	else if (token == '%')
		ft_putchar_fd('%', 1);
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "asdasd";
// 	int n = 123456;
// 	n = printf("%s%d%i%x%p\n", s, n, n, n, &n);
// 	printf("u: %d\n", n);
// 	n = 123456;
// 	n = ft_printf("%s%d%i%x%p\n", s, n, n, n, &n);
// 	printf("u: %d\n", n);
// }
