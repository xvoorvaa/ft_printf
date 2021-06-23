/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_width_int.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/09 19:38:49 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/06/23 21:10:24 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

int	print_width_int(long long ap)
{
	int	len;
	int	remaining;

	len = 0;
	remaining = 0;
	if (flags.precision > numlen(ap))
		remaining = flags.precision - numlen(ap);
	while (flags.width - numlen(ap) > len && flags.zero_true == 1)
	{
		write(1, "0", 1);
		len++;
	}
	while (flags.width - numlen(ap) > len && flags.precision == 0)
	{
		write(1, " ", 1);
		len++;
	}
	while (flags.width - numlen(ap) - remaining > len && flags.precision > 0)
	{
		write(1, " ", 1);
		len++;
	}
	len--;
	return (len);
}
