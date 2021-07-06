/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:45:36 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/06 14:45:47 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct sigaction sig_try;

void receive(int signo)
{
	int		size;
	char	bit;

	size = 0;
	bit = 0;
	printf("send_pid : %d\n", getpid());
	// 비트 연산 들어감.
	if (size == 8)
	{
		write (1, &bit, 8);
		write (1, "\n", 1);
	}
	printf("receiveß_done\n");
}

int main(void)
{
	// sigemptyset(&sig_try.sa_mask);  블록될 시그널은 없음 이게 무슨 말일까
	if (sigaction(SIGUSR1, &receive, NULL) < 0)
		ft_error("Error : SIG_ERROR\n");
	if (sigaction(SIGUSR2, &receive, NULL) < 0)
		ft_error("Error : SIG_ERROR\n");
	ft_putpid("Server PID", getpid());
	while (1)
		pause();
	return (0);
}