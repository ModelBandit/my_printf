/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 10:23:59 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/21 16:18:14 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static int print_by_type(const char token, va_list vl);

int ft_printf(const char * arg, ...)
{
    va_list ap;
    int i;
    int covert_count;
    int spec_count;
    const char *str_start;
    
    va_start(ap, arg);
    i = 0;
    covert_count = 0;
    spec_count = 0;
    str_start = arg;

    while(str_start != NULL && str_start[i] != '\0')
    {
        if(str_start[i+covert_count] == '%')
        {
            spec_count += (print_by_type(*ft_strchr("cspdiuxX%", str_start[(i+covert_count) + 1]), ap));
            ++covert_count;
        }
        else
        {
            ft_putchar_fd(str_start[(i+covert_count)], 1);
        }
        ++i;
    }

    va_end(ap);
    return i+spec_count-1;
}


static int print_by_type(const char token, va_list vl)
{
    int i;

    i = 0;
    if(token == 'c')
        ft_putchar_fd(va_arg(vl, int), 1);
    else if(token == 's')
        i = my_print_string(va_arg(vl, char*));
    else if(token == 'p')
    {
        ft_putstr_fd("0x", 1);
        i = 2 + my_print_convert(va_arg(vl, void*), "0123456789abcdef");
    }
    else if(token == 'd' || token == 'i')
        i = my_print_int(va_arg(vl, int));
    else if(token == 'u')
        i = my_print_convert(va_arg(vl, void*), "0123456789");
    else if(token == 'x')
        i = my_print_convert(va_arg(vl, void*), "0123456789abcdef");
    else if(token == 'X')
        i = my_print_convert(va_arg(vl, void*), "0123456789ABCDEF");
    else if(token == '%')
    {
        ft_putstr_fd("%%", 1);
    }
    else
    {
        write(1, "FUCKYOU", 8);
    }
    return i;
}


#include <stdio.h>
int main()
{
    char *asd = "0x0x0x0x0";
    char a = 'a';
    int n = 0;
    n = printf("zzz%czzz\n", a);
    printf("char: %d\n", n);
    n = ft_printf("zzz%czzz\n", a);
    printf("char: %d\n", n);
    n = printf("zzz%szzz\n", asd);
    printf("string: %d\n", n);
    n = ft_printf("zzz%szzz\n", asd);
    printf("string: %d\n", n);
    n = printf("zzz%pzzz\n", asd);
    printf("point: %d\n", n);
    n = ft_printf("zzz%pzzz\n", asd);
    printf("point: %d\n", n);
    n = 9;
    n = printf("zzz%dzzz\n", n);
    printf("dint: %d\n", n);
    n = ft_printf("zzz%dzzz\n", n);
    printf("dint: %d\n", n);
    n = 9;
    n = printf("zzz%izzz\n", n);
    printf("int: %d\n", n);
    n = ft_printf("zzz%izzz\n", n);
    printf("int: %d\n", n);
    n = 9;
    n = printf("zzz%uzzz\n", n);
    printf("uint: %d\n", n);
    n = ft_printf("zzz%uzzz\n", n);
    printf("uint: %d\n", n);
    n = 9;
    n = printf("zzz%xzzz\n", n);
    printf("x: %d\n", n);
    n = ft_printf("zzz%xzzz\n", n);
    printf("x: %d\n", n);
    n = 9;
    n = printf("zzz%Xzzz\n", n);
    printf("X: %d\n", n);
    n = ft_printf("zzz%Xzzz\n", n);
    printf("X: %d\n", n);
}