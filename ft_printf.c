/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 10:23:59 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/18 14:20:22 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int ft_printf(const char * arg, ...)
{
    int i;
    va_list ap;
    char *s;

    i = 0;
    va_start(ap, arg);

    s = va_arg(ap, char*);
    write(1, s, 1);

    va_end(ap);

    return i;
}

// int main()
// {
//     char *s;
//     ft_printf(s);
// }