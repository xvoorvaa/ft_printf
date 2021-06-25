/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_width_int.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/09 19:38:49 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/06/25 13:59:33 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../printf.h"

int	print_width_int(long long ap)
{
	int	len;
	int	remaining;
	int ft_numlen;

	len = 0;
	remaining = 0;
	ft_numlen = numlen(ap);
	if (flags.precision < 0)
		ft_numlen = 0;
	if (flags.precision > ft_numlen)
		remaining = flags.precision - ft_numlen;
	while (flags.width - ft_numlen > len && flags.zero_true == 1)
	{
		write(1, "0", 1);
		len++;
	}
	while (flags.width - ft_numlen > len && flags.precision == 0)
	{
		write(1, " ", 1);
		len++;
	}
	while (flags.width - ft_numlen - remaining > len && flags.precision != 0)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}
