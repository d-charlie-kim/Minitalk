/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:45:41 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/06 14:45:42 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (-1);
}

void ft_putstr_fd(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, str[i], 1);
		i++;
	}
}

void ft_putpid(char *str, int nbr)
{
	ft_putstr_fd(str, 1);
	ft_putnbr(nbr);
	write(1, "\n", 1);
}

void ft_putnbr(int nbr)
{
	int first;
	int second;

	first = nbr/ 10;
	second = (nbr % 10) + '0';
	if (nbr >= 10)
	{
		ft_putnbr(first);
		write(1, &second, 1);
	}
	else
		write(1, &second, 1);
}