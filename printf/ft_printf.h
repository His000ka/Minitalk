/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:41:01 by pitroin           #+#    #+#             */
/*   Updated: 2024/05/03 13:44:43 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *form, ...);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printint(long d, int base, char type);
int		ft_printu(unsigned int d);
int		ft_printaddress(unsigned long d, int f);
int		ft_checkpar(char c, va_list args);
int		ft_strlen(char *str);
int		ft_sizeint(int d);

#endif