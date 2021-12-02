/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:48:30 by obouadel          #+#    #+#             */
/*   Updated: 2021/12/02 17:00:16 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "../libft/libft.h"

t_data	g_data;

static void	receive(int sig)
{
	if (sig == SIGUSR1)
		g_data.c |= 1 << g_data.pos;
	g_data.pos++;
	if (g_data.pos == 8)
	{
		g_data.pos = 0;
		if (!g_data.c)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(g_data.c, 1);
		g_data.c = 0;
	}
}

int	main(void)
{
	g_data.c = 0;
	g_data.pos = 0;
	ft_putstr_fd("PID     : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (1)
		pause();
	return (0);
}
