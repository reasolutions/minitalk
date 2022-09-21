/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarslan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:14:37 by rarslan           #+#    #+#             */
/*   Updated: 2022/09/21 15:47:59 by rarslan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendbits(int pid, int c)
{
	int	n;

	n = 128;
	while (n >= 1)
	{
		if (c / n == 1)
		{
			kill(pid, SIGUSR1);
			c = c % n;
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		n = n / 2;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)argv[2];
	if (argc == 3)
	{
		i = 0;
		while (str[i])
		{	
			sendbits(ft_atoi(argv[1]), str[i++]);
		}
	}
	else
		ft_putstr("usage: ./client [server pid] [string to send]");
}
