/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:29:47 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/21 16:19:48 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_print_convert(void *target, const char *convert)
{
	size_t	address;

	address = (size_t)target;
	if (address == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (print_tail(address, convert, 0));
}
