/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:41:53 by pitroin           #+#    #+#             */
/*   Updated: 2024/05/30 17:48:16 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (res > 9223372036854775807 && sign == 1)
		return (-1);
	if (res > 9223372036854775807 && sign == -1)
		return (0);
	return (res * sign);
}

void	ft_convert_bit(char *str, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0' || str[0] == '\0')
	{
		j = 0;
		while (j < 8)
		{
			if ((0x01 << j) & str[i])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(300);
		}
		if (str[0] == '\0')
			break ;
		i++;
	}
}

void	confirm_msg(int signal)
{
	static int	count;

	count = 0;
	if (signal == SIGUSR2 && count == 0)
	{
		ft_printf("Message recieved\n");
		count = 1;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
	{
		ft_printf("Le PID est incorrect");
		return (0);
	}
	signal(SIGUSR2, confirm_msg);
	ft_convert_bit(argv[2], pid);
	ft_convert_bit("\n", pid);
	if (argv[2][0] != '\0')
		ft_convert_bit("", pid);
	usleep(300);
	return (0);
}
