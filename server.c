/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:31:09 by inunez-g          #+#    #+#             */
/*   Updated: 2022/04/21 12:18:43 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	handler_signal(int signum)
{
	static int	i;
	static int	nbr;

	if (!i)
	{
		i = 0;
		nbr = 0;
	}
	if (i < 8)
	{
		if (signum == 31)
			nbr += 0x01 << i;
		i++;
	}
	if (i == 8)
	{	
		ft_printf("%c", nbr);
		i = 0;
		nbr = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler_signal);
	signal(SIGUSR2, handler_signal);
	while (1)
		pause();
}
