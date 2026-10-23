/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 10:23:59 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/23 14:47:12 by chchoi           ###   ########.fr       */
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

    while(str_start != NULL && str_start[i+covert_count] != '\0')
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
    return i+spec_count;
}


static int print_by_type(const char token, va_list vl)
{
    void *p_addr;
    int i;

    p_addr = NULL;
    i = 0;
    if(token == 'c')
        ft_putchar_fd(va_arg(vl, int), 1);
    else if(token == 's')
        i = my_print_string(va_arg(vl, char*));
    else if(token == 'p')
    {
        p_addr = va_arg(vl, void*);
        if(p_addr != NULL)
            i += my_print_string("0x") + 1;
        i += my_print_convert(p_addr, "0123456789abcdef");
    }
    else if(token == 'd' || token == 'i')
        i = my_print_int(va_arg(vl, int));
    else if(token == 'u')
        i = my_print_uint(va_arg(vl, unsigned int));
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


// #include <stdio.h>
// int main()
// {
//     unsigned int num = 0x7fffffffffffffffL;
//     int n = 0;
//     n = printf("%u\n", num);
//     printf("u: %d\n", n);
//     n = ft_printf("%u\n", num);
//     printf("u: %d\n", n);
// }