/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_letter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 17:26:30 by user42            #+#    #+#             */
/*   Updated: 2021/08/23 18:31:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	a;
	int	i;

	i = 0;
	a = '_';
	if (ac < 2)
		return (printf("%s <nb of letters>\n", av[0]));
	while (i++ < atoi(av[1]))
	{
		if (a - 1 == 'z')
			a = 'A';
		else if (a - 1 == 'Z')
			a = '0';
		else if (a - 1 == '9')
			a = 'a';
		write(1, &a, 1);
		if (a != '_')
			a++;
	}
	write (1, "\n", 1);
	return (0);
}
