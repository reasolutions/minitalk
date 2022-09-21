/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarslan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:50:54 by rarslan           #+#    #+#             */
/*   Updated: 2022/09/21 15:53:15 by rarslan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sfed(int signum)
{
	static int		ch;
	static int		n = 128;
	unsigned int	c;

	if (signum == SIGUSR1)
		c = 1;
	else
		c = 0;
	ch = ch + n * c;
	if (n == 1)
	{
		write(1, &ch, 1);
		ch = 0;
		n = 128;
		c = 0;
	}
	else
		n = n / 2;
}

int	main(void)
{
	ft_putstr("server pid: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	if (signal(SIGUSR1, sfed) == SIG_ERR)
		ft_putstr("oh no\n");
	if (signal(SIGUSR2, sfed) == SIG_ERR)
		ft_putstr("oh no\n");
	while (1)
		pause();
	return (0);
}
