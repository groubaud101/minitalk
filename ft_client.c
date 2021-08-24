/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:00:00 by user42            #+#    #+#             */
/*   Updated: 2021/08/24 20:14:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <limits.h>

int	ft_send(pid_t pid, int send, int nb)
{
	int	sig_to_send;

	//ft_printf("nb to send : %i\n", send);
	while (nb > 0)
	{
		sig_to_send = (send >= nb) * SIGUSR1 + !(send >= nb) * SIGUSR2;
		//ft_printf("nb : %i(%i), ", nb, sig_to_send);
		send -= (nb * (send >= nb));
		if (kill(pid, sig_to_send) == -1)
			return (-1);
		usleep(5000);
		nb /= 2;
	}
	//ft_printf("\n");
	return (1);
}

#define BYTE1 256
#define BYTE2 65536
#define BYTE3 16777216

int	ft_send_pid_client(int pid_client, int pid_server)
{
	int	size;

	//ft_printf("pid client : %i\n", pid_client);
	size = (1 + (pid_client >= BYTE1) + (pid_client >= BYTE2)
		+ (pid_client >= BYTE3));
	// quelle taille je vais recevoir
	ft_send(pid_server, size, 4); //pid, nb de byte à lire, le nb max
	// envoie du pid du client
	ft_send(pid_server, pid_client, ft_pow_int(2, size * 8));
	//ft_printf("pid server : %i, size : %i\n\n", pid_server, size);
	return (1);
}

int	main(int ac, char **av)
{
	pid_t	pid_server;
	int		i;

	if (ac < 3)
		return (ft_printf("%s PID \"message to send\"\n", av[0]));
	pid_server = ft_atoi(av[1]);
	if (pid_server == 0) // || ft_strisdigit(av[1]) == 0)
		return (0);
	ft_send_pid_client(getpid(), pid_server);
	i = 0;
	while (av[2][i])
	{
		// quelle taille je vais recevoir
		ft_send(pid_server, 1, 4);
		// envoie de l'int du caractere
		ft_send(pid_server, av[2][i], 256);
		ft_printf("%c", av[2][i]);
		i++;
	}
	return (1);
}
