/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabiven <gabiven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:04:01 by gabiven           #+#    #+#             */
/*   Updated: 2024/10/24 21:55:59 by gabiven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void	afficher_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID du programme : %d\n", pid);
}

void	gerer_signal(int sig)
{
	static int	bit_count = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
	{
		c = (c << 1);
	}
	else if (sig == SIGUSR2)
	{
		c = (c << 1) | 1;
	}
	if (++bit_count == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			write(1, "\n", 1);
		}
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	afficher_pid();
	signal(SIGUSR1, gerer_signal);
	signal(SIGUSR2, gerer_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
