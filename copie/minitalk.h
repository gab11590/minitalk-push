/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabiven <gabiven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:43:10 by gabiven           #+#    #+#             */
/*   Updated: 2024/11/04 19:41:23 by gabiven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// server
void	afficher_pid(void);
void	gerer_signal(int sig);

// client
void	send_bit(int pid, char bit);
void	send_char(int pid, char c);
void	send_message(int pid, const char *message);

// atoi

int      ft_atoi(const char *str);
int	ft_isdigit(int c);