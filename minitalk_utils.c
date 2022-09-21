/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarslan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:14:03 by rarslan           #+#    #+#             */
/*   Updated: 2022/09/21 15:49:26 by rarslan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int num)
{
	char	d;

	d = 0;
	if (num > 9)
		ft_putnbr(num / 10);
	d = num % 10 + 48;
	write(1, &d, 1);
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i] != 0)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}
