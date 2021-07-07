/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:46:08 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/07 21:10:45 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	receive(int signo, siginfo_t *siginfo, void *ptr)
{
	static int				size = 0;
	static unsigned char	bit = 0;
	int						check;

	check = 0;
	bit = bit >> 1;
	if (signo == SIGUSR1)
		bit |= 128;
	size++;
	if (size == 8)
	{
		write(1, &bit, 1);
		if (bit == 0)
			kill(siginfo->si_pid, SIGUSR1);
		if (check < 0)
			ft_error("Error : KILL_ERROR\n");
		size = 0;
		bit = 0;
	}
	(void)ptr;
}

int	main(void)
{
	t_sigaction	server;

	server.sa_sigaction = receive;
	sigemptyset(&server.sa_mask);
	server.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &server, NULL) < 0)
		ft_error("Error : SIG_ERROR\n");
	if (sigaction(SIGUSR2, &server, NULL) < 0)
		ft_error("Error : SIG_ERROR\n");
	ft_putpid("Server PID : ", getpid());
	while (1)
		pause();
	return (0);
}
