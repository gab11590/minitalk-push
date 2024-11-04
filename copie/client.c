/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabiven <gabiven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:05:12 by gabiven           #+#    #+#             */
/*   Updated: 2024/11/04 19:34:20 by gabiven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, char bit)
{
	if (bit == '1')
	{
		kill(pid, SIGUSR2);
	}
	else
	{
		kill(pid, SIGUSR1);
	}
	usleep(100);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			send_bit(pid, '1');
		}
		else
		{
			send_bit(pid, '0');
		}
		--i;
	}
}

void	send_message(int pid, const char *message)
{
	while (*message)
	{
		send_char(pid, *message++);
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int			pid;
	const char	*message;

	pid = 0;
	message = NULL;
	if (argc != 3)
	{
		ft_printf("<pid> <message>");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	send_message(pid, message);
	return (0);
}
