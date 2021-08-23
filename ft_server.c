/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:36:31 by user42            #+#    #+#             */
/*   Updated: 2021/08/23 17:49:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

//void	signal_handler(int signum, siginfo_t *some,
//					void *thing)
void	signal_handler(int signum)
{
	static int	c = 0;
	static int	nb = 128;

	c += (signum == SIGUSR1) * nb;
	//(void)some;
	//(void)thing;
	nb /= 2;
	if (nb == 0)
	{
		ft_printf("%c", c);
		nb = 128;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	s;

	ft_printf("%i\n", getpid());
	s.sa_handler = signal_handler;
	while (1)
	{
		sigaction(SIGUSR1, &s, 0);
		sigaction(SIGUSR2, &s, 0);
		pause();
	}
	return (1);
}
