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

void	send(int signo)
{
	비트 연산 들어감
}

int		main (int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 3)
		ft_error("Error : ARG_ERROR\n");
	if (sigaction(SIGUSR1, &send, NULL) < 0)
		ft_error("Error : SIG_ERROR\n");
	if (sigaction(SIGUSR2, &send, NULL) < 0)
		ft_error("Error : SIG_ERROR\n");
}
