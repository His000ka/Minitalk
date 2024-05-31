/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:38:33 by pitroin           #+#    #+#             */
/*   Updated: 2024/05/03 16:07:19 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (ft_printstr("(null)"));
	while (str[i] != 0)
	{
		ft_printchar((int)str[i]);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_checkpar(char c, va_list args)
{
	if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printaddress(va_arg(args, unsigned long), 0) + 2);
	else if (c == 'd' || c == 'i')
		return (ft_printint((long)va_arg(args, int), 10, c));
	else if (c == 'x' || c == 'X')
		return (ft_printint((long)va_arg(args, unsigned int), 16, c));
	else if (c == 'u')
		return (ft_printu(va_arg(args, unsigned int)));
	return (ft_printchar(c));
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, form);
	count = 0;
	i = 0;
	while (form[i] != 0)
	{
		if (form[i] == '%')
		{
			count += ft_checkpar(form[i + 1], args);
			i++;
		}
		else
			count += ft_printchar(form[i]);
		i++;
	}
	va_end(args);
	return (count);
}
