/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:36:31 by user42            #+#    #+#             */
/*   Updated: 2021/08/25 22:32:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define MY 1

#if !MY
void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	i = 7;
	static int	c;

	(void)ucontext;
	c <<= 1;
	if (sig == SIGUSR1)
		c++;
	if (--i < 0)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

#endif

#if MY
void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	c = 0;
	static int	nb = 256;

	(void)ucontext;
	ft_printf("c : %i, nb : %i, sig : %i\n", c, nb, sig);
	if (sig == SIGUSR1)
		c += nb;
	if (nb == 0)
	{
		write(1, &c, 1);
		nb = 256;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
	nb /= 2;
}
#endif

int	main(void)
{
	struct sigaction	s;

	ft_printf("PID SERVER : %i\n", getpid());

	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = signal_handler;
	if(sigaction(SIGUSR1, &s, 0) == -1
		|| sigaction(SIGUSR2, &s, 0) == -1)
		return (ft_printf("Error sigaction\n"));
	while (1)
		pause();
	return (1);
}
