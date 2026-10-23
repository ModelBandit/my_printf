/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:39:08 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/23 15:46:09 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_print_string(void *target)
{
	char	*str;

	str = (char *)target;
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str) - 1);
}
