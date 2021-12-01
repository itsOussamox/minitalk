/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:48:29 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/02 07:52:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"
#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

static void	ft_tobin(char chr, int pidserv)
{
	int	i;

	i = 0;
	if (chr < 0)
		return ;
	while (i < 8)
	{
		if (chr % 2 == 1)
			kill(pidserv, SIGUSR1);
		if (chr % 2 == 0)
			kill(pidserv, SIGUSR2);
		chr = chr / 2;
		i++;
		usleep(100);
	}
}

static void	ft_send(char *str, int pidserv)
{
	int	i;

	i = 0;
	while (str[i])
		ft_tobin(str[i++], pidserv);
	ft_tobin(0, pidserv);
}

int	main(int ac, char **av)
{
	int	pidserv;

	if (ac != 3)
	{
		ft_putstr_fd("WRONG ARGUMENTS!", 1);
		return (1);
	}
	pidserv = ft_atoi(av[1]);
	if (!pidserv)
	{
		ft_putstr_fd("INVALID PID!", 1);
		return (1);
	}
	ft_send(av[2], pidserv);
	return (0);
}