/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:29:54 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/23 13:25:01 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_tail(size_t target, const char *convert, int count)
{
	size_t address;
	size_t c_size;
	int i = 0;

	address = target;
	c_size = ft_strlen(convert);

	if (address >= c_size)
		i = print_tail(address / c_size, convert, count + 1);
	ft_putchar_fd(convert[target % c_size], 1);

	if(i > count) // all case choose this
		return (i);
	return count;
}
