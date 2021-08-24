/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:36:31 by user42            #+#    #+#             */
/*   Updated: 2021/08/24 20:11:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	g_get_it;

// on doit chopper le premier octet qui nous donne
// le nb d'octet qu'on va lire ensuite
// donc un total de 8 sigaction (qui renvoie 0 en cas de succes)
// si le nb est de 1, c'est un charactere
// si 8, c'est le PID du client

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_get_it = 1;
	else if (sig == SIGUSR2)
		g_get_it = 2;
	else
		g_get_it = 0;
}

int	ft_receive(int nb, struct sigaction s)
{
	int	ret1;
	int ret2;
	int	c;

	c = 0;
	s.sa_handler = signal_handler;
	//ft_printf("nb : %i bin :", nb);
	while (nb > 0)
	{
		ret1 = sigaction(SIGUSR1, &s, 0);
		ret2 = sigaction(SIGUSR2, &s, 0);
		pause();
		//ft_printf("g(%i)", g_get_it);
		if (ret1 == -1 || ret2 == -1)
		{
			ft_printf("Error sigaction\n");
			exit (0);
		}
		else if (g_get_it == 1)
		{
			//ft_printf("1 ");
			c += nb;
			nb /= 2;
		}
		else if (g_get_it == 2)
		{
			//ft_printf("0 ");
			nb /= 2;
		}
		g_get_it = 0;
	}
	//ft_printf("\n");
	return (c);
}

int	main(void)
{
	struct sigaction	s;
	//pid_t				pid_client;
	int					size;
	int					nb;

	ft_printf("PID SERVER : %i\n", getpid());

	g_get_it = 0;
	size = ft_receive(4, s);
	//ft_printf("size pid client : %i\n", size);

	nb = ft_receive(ft_pow_int(2, size * 8), s);
	//ft_printf("pid client : %i\n", nb);
	while (1)
	{
		size = ft_receive(4, s);
		//ft_printf("size du caractere (8 bits) : %i\n", size);

		nb = ft_receive(ft_pow_int(2, size * 8), s);
		//ft_printf("le charactere %c (en int) : %i\n\n", nb, nb);
		ft_printf("%c", nb);
	}
	return (1);
}
