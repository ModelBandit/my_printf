/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:29:47 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/23 15:46:12 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_print_uint(unsigned int target)
{
	unsigned int	u_integer;

	u_integer = target;
	if (u_integer == 0)
	{
		ft_putchar_fd('0', 1);
		return (0);
	}
	return (print_tail(u_integer, "0123456789", 0));
}
