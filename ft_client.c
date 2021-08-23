/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:00:00 by user42            #+#    #+#             */
/*   Updated: 2021/08/23 18:24:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <sys/types.h>
#include <signal.h>

int	ft_send_byte(int pid, int c)
{
	int	byte;
	int	nb;

	byte = 0;
	nb = 128;
	while (byte < 8)
	{
		if (c >= nb)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (ft_printf("Error kill\n"));
			c = c - nb;
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				return (ft_printf("Error kill\n"));
		nb /= 2;
		byte++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac < 3)
		return (ft_printf("%s PID \"message to send\"\n", av[0]));
	pid = ft_atoi(av[1]);
	while (av[2][i])
		ft_send_byte(pid, av[2][i++]);
	return (1);
}
