/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:36:31 by user42            #+#    #+#             */
/*   Updated: 2021/08/26 14:27:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	c = 0;
	static int	nb = 256;

	(void)ucontext;
	if (sig == SIGUSR1)
		c += nb;
	if (nb == 1)
	{
		write(1, &c, 1);
		nb = 512;
		c = 0;
	}
	nb /= 2;
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_printf_fd(2, "Error kill\n");
		exit(1);
	}
}

int	main(void)
{
	struct sigaction	s;

	ft_printf("PID SERVER : %i\n", getpid());
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &s, 0) == -1
		|| sigaction(SIGUSR2, &s, 0) == -1)
		return (ft_printf_fd(2, "Error sigaction\n"));
	while (1)
		pause();
	return (0);
}
