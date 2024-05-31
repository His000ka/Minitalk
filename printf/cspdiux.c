/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspdix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:53:45 by pitroin           #+#    #+#             */
/*   Updated: 2024/05/03 14:18:38 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(long d, int base, char type)
{
	int		count;
	char	*hexa;

	count = 0;
	if (type == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	if (d < 0)
	{
		if (d == INT_MIN && (type == 'd' || type == 'i'))
			return (ft_printstr("-2147483648"));
		ft_printchar('-');
		return (ft_printint(-d, base, type) + 1);
	}
	else if (d < base)
		return (ft_printchar(hexa[d]));
	count += ft_printint(d / base, base, type);
	return (count + ft_printint(d % base, base, type));
}

int	ft_printaddress(unsigned long d, int f)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (f == 0)
		ft_printstr("0x");
	if (d < 16)
		return (ft_printchar(hexa[d]));
	count += ft_printaddress(d / 16, 1);
	return (count + ft_printaddress(d % 16, 1));
}

int	ft_printu(unsigned int d)
{
	unsigned int	count;

	count = 0;
	if (d < 10)
		return (ft_printchar(d + 48));
	count += ft_printu(d / 10);
	return (count + ft_printu(d % 10));
}
