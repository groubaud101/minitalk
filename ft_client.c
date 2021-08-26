/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:00:00 by user42            #+#    #+#             */
/*   Updated: 2021/08/26 14:30:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_init_c(char *str)
{
	if (!(*str))
		exit(1);
	return (*str);
}

static int	ft_send(char *s, int id)
{
	static pid_t	pid;
	static int		c;
	static int		nb = 256;
	static char		*str = 0;
	int				sig_to_send;

	if (!str)
	{
		c = ft_init_c(s);
		str = s;
	}
	if (id != -1)
		pid = id;
	if (nb == 0)
	{
		str++;
		c = ft_init_c(str);
		nb = 256;
	}
	sig_to_send = (c >= nb) * SIGUSR1 + !(c >= nb) * SIGUSR2;
	c -= (nb * (c >= nb));
	nb /= 2;
	if (kill(pid, sig_to_send) == -1)
		return (-1);
	return (1);
}

static void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	if (sig == SIGUSR1)
	{
		if (ft_send(NULL, -1) == -1)
		{
			ft_printf_fd(2, "Error kill\n");
			exit(1);
		}
	}
}

int	main(int ac, char **av)
{
	int					pid_server;
	struct sigaction	s;

	if (ac < 3)
		return (ft_printf_fd(2, "%s PID \"message to send\"\n", av[0]));
	pid_server = ft_atoi(av[1]);
	if (pid_server <= 1 || ft_str_isdigit(av[1]) == 0)
		return (ft_printf_fd(2, "Error PID\n"));
	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &s, 0) == -1)
		return (ft_printf_fd(2, "Error sigaction\n"));
	if (ft_send(av[2], pid_server) == -1)
		return (ft_printf_fd(2, "Error kill\n"));
	while (1)
		pause();
	return (0);
}
