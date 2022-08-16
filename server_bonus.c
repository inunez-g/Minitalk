/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:31:09 by inunez-g          #+#    #+#             */
/*   Updated: 2022/04/21 12:07:36 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	handler_signal(int signum, siginfo_t *info, void *x)
{
	static int	i;
	static int	nbr;

	(void)x;
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
	usleep(6000);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler_signal;
	ft_printf("Número PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
