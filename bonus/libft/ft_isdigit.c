/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/09 19:50:34 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/06/09 19:51:42 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int argc)
{
	if (argc < '0' || argc > '9')
		return (0);
	return (1);
}