/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 16:21:50 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/18 17:21:41 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"

#include <unistd.h>

#include <stdio.h>

int	convert_hex(unsigned long number, bool is_uppercase)
{
	const char	*caps_digits;
	const char	*nocaps_digits;
	size_t		len;

	len = 0;
	caps_digits = "0123456789ABCDEF";
	nocaps_digits = "0123456789abcdef";
	if (number > 15)
		len += convert_hex(number / 16, is_uppercase);
	number = number % 16;
	if (is_uppercase == true)
		write(STDOUT_FILENO, &caps_digits[number], 1);
	else if (is_uppercase == false)
		write(STDOUT_FILENO, &nocaps_digits[number], 1);
	len++;
	return (len);
}

unsigned int	conversion(t_flags *flags, char *str, va_list ap)
{
	int	i;
	int	len;
	t_conversions	s_conversions[] = {
	{'s', &print_s},
	{'c', &print_c},
	{'i', &print_id},
	{'d', &print_id},
	{'u', &print_u},
	{'p', &print_p},
	{0, NULL}
};

	i = 0;
	len = 0;
	while (s_conversions[i].key)
	{
		if (*str == s_conversions[i].key)
			len = s_conversions[i].func(flags, ap);
		i++;
	}
	if (*str == 'x')
		len = print_x(flags, ap, false);
	else if (*str == 'X')
		len = print_x(flags, ap, true);
	else if (*str == '%')
		len = print_perc(flags);
	return (len);
}
