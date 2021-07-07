/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:45:49 by dokkim            #+#    #+#             */
/*   Updated: 2021/07/07 21:06:30 by dokkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define PID_MIN 100
# define PID_MAX 99998

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct sigaction	t_sigaction;

void	receive(int signo, siginfo_t *siginfo, void *ptr);

void	send(int pid, char alpha);
void	ft_error_check(int argc, char **argv);

int		ft_atoi(char *str);
void	ft_putnbr(int nbr);
void	ft_putpid(char *str, int nbr);
void	ft_putstr_fd(char *str, int fd);
void	ft_error(char *str);

#endif
