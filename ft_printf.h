/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:45:38 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/23 15:51:51 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *arg, ...);
int	print_tail(size_t target, const char *convert, int count);
int	my_print_convert(void *target, const char *convert);
int	my_print_int(int target);
int	my_print_uint(unsigned int target);
int	my_print_hexa(unsigned int target, const char *convert);
int	my_print_string(void *target);
#endif
