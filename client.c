/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:45:25 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/06 14:45:27 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct sigaction abc;

void	send(int pid, char *str)
{
	char	bit;
	int		size;
	int		check;

	check = 0;
	while (*str)
	{
		size = 0;
		bit = 0;
		while (size < 8)
		{
			bit = bit | *str;
			if (bit == 1)
				check = kill(pid, SIGUSR1);
			else if (bit == 0)
				check = kill(pid, SIGUSR2);
			if (check < 0)
				ft_error("Error : KILL_ERROR");
			bit = bit << 1;
			*str = *str >> 1;
			size++;
		}
	}
}

int		main (int argc, char **argv)
{
	int pid;

	// abc.sa_handler = send;
	ft_error_check(argc, argv);
	pid = ft_atoi(argv[1]);
	if (sigaction(SIGUSR1, &abc, NULL) < 0)
		ft_error("Error : SIG_ERROR\n");
	if (sigaction(SIGUSR2, &abc, NULL) < 0)
		ft_error("Error : SIG_ERROR\n");
	send(pid, argv[2]);
}

void	ft_error_check(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 3)
		ft_error("Error : ARG_ERROR\n");
	while (argv[1][i])
	{
		if (argv[1][i] < 48 || argv[1][i] > 57)
			ft_error("Error : PID is not valid\n");
		i++;
		if (i > 6)
			ft_error("Error : PID is not valid\n");
	}
}