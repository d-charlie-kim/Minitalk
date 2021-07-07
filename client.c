/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:45:25 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/07 23:13:53 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_receive(int signo)
{
	if (signo == SIGUSR1)
		ft_putstr_fd("Server Successfully Received\n", 1);
	exit (0);
}

void	send(int pid, char alpha)
{
	int		size;
	int		check;

	check = 0;
	size = 0;
	while (size < 8)
	{
		if (1 & alpha)
			check = kill(pid, SIGUSR1);
		else
			check = kill(pid, SIGUSR2);
		if (check < 0)
			ft_error("Error : KILL_ERROR\n");
		alpha = alpha >> 1;
		size++;
		usleep(100);
	}
}

void	ft_error_check(int argc, char **argv)
{
	int	i;

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

int	main(int argc, char **argv)
{
	t_sigaction	client;
	int			pid;
	int			i;

	i = 0;
	client.sa_handler = client_receive;
	sigemptyset(&client.sa_mask);
	ft_error_check(argc, argv);
	pid = ft_atoi(argv[1]);
	if (sigaction(SIGUSR1, &client, NULL) < 0)
		ft_error("Error : SIG_ERROR\n");
	while (argv[2][i])
	{
		send(pid, argv[2][i]);
		i++;
	}
	send(pid, '\0');
	while (1)
		pause();
}
