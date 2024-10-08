/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:35:37 by pitroin           #+#    #+#             */
/*   Updated: 2024/05/30 12:09:54 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	handle_signal(int sig)
{
	static int	c;
	static int	count = 0;

	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			c |= 0x01 << count;
		count++;
		if (count == 8)
		{
			ft_printf("%c", c);
			c = 0;
			count = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	sa.sa_handler = handle_signal;
	ft_printf("Bienvenu sur le server de pitroin\n");
	ft_printf("Numero PID du serveur : %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
