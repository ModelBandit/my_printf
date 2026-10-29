/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 14:39:08 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/29 14:23:00 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_print_int(int target)
{
	int		num;
	char	*str;

	num = target;
	str = ft_itoa(num);
	if (str == NULL)
		return (0);
	ft_putstr_fd(str, 1);
	num = (int)ft_strlen(str);
	free(str);
	return (num - 1);
}
