/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:29:47 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/23 15:46:02 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_print_convert(void *target, const char *convert)
{
	size_t	address;

	address = (size_t)target;
	if (address == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (ft_strlen("(nil)") - 1);
	}
	return (my_print_string("0x") + print_tail(address, convert, 0) + 1);
}
