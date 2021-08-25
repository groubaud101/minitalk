/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:00:00 by user42            #+#    #+#             */
/*   Updated: 2021/08/25 22:19:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

#define MY 1

#if !MY
int	ft_send(char *s, int id)
{
	static int	c;
	static int	bit = -1;
	static char	*str;
	static int	pid;

	if (!str)
		str = s;
	if (id != -1)
		pid = id;
	if (bit < 0)
	{
		c = *str++;
		if (!c)
			return (-1);
		bit = 7;
	}
	if ((c >> bit--) & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	return (1);
}
#endif

#if MY
int	ft_send(char *s, int id)
{
	static pid_t	pid;
	static int		c;
	static int		nb = 128;
	static char		*str = 0;
	//int				sig_to_send;

	ft_printf("c : %i, nb : %i, sig : ", c, nb);
	if (!str)
	{
		c = *s;
		str = s;
	}
	if (id != -1)
		pid = id;
	if (nb == 0)
	{
		c = *(str++);
		if (!c)
			exit(0);
		nb = 128;
	}
	//sig_to_send = (c >= nb) * SIGUSR1 + !(c >= nb) * SIGUSR2;
	if (c >= nb)
	{
		kill(pid, SIGUSR1);
		ft_printf("10\n\n");
	}
	else
	{
		kill(pid, SIGUSR2);
		ft_printf("12\n\n");
	}
	c -= (nb * (c >= nb));
	nb /= 2;
	return (1);
}
#endif
void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	if (sig == SIGUSR1)
		if (ft_send(NULL, -1) == -1)
		{
			ft_printf("Error kill\n");
			exit(0);
		}
}

int	main(int ac, char **av)
{
	int					pid_server;
	struct sigaction	s;

	if (ac < 3)
		return (ft_printf("%s PID \"message to send\"\n", av[0]));
	pid_server = ft_atoi(av[1]);
	if (pid_server <= 1) // || ft_strisdigit(av[1]) == 0)
		return (0);

	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &s, 0) == -1)
		return (ft_printf("Error sigaction\n"));

	if (ft_send(av[2], pid_server) == -1)
		return (ft_printf("Error kill\n"));
	while (1)
		pause();

	return (0);
}
