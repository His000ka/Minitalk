/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:35:37 by pitroin           #+#    #+#             */
/*   Updated: 2024/05/30 17:54:55 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

void	sigaction_signal(int sig, siginfo_t *info, void *context)
{
	static int	c;
	static int	count = 0;

	(void)context;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			c |= 0x01 << count;
		count++;
		if (count == 8)
		{
			ft_printf("%c", c);
			if (c == '\0')
				kill(info->si_pid, SIGUSR2);
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
	sa.sa_sigaction = sigaction_signal;
	ft_printf("Bienvenu sur le server de pitroin\n");
	ft_printf("Numero PID du serveur : %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Erreur sigaction\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
