/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:48:30 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/02 07:47:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

t_data data;
void	receive(int sig)
{
	if (sig == SIGUSR1)
		data.c |= 1 << data.pos; 
	data.pos++;
	if (data.pos == 8)
	{
		data.pos = 0;
		if (!data.c)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(data.c, 1);
		data.c = 0;
	}
}
int main(void)
{
	data.c = 0;
	data.pos = 0;
	ft_putstr_fd("PID     : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while(1)
		usleep(250);
	return (0);
}