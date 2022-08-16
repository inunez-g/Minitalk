/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:31:05 by inunez-g          #+#    #+#             */
/*   Updated: 2022/04/21 12:06:19 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/Libft/libft.h"
#include "ft_printf/ft_printf.h"

void	ft_error(void)
{
	ft_printf("ERROR: Incorrect PID\n");
	exit(0);
}

void	response(int pid)
{
	(void)pid;
	ft_printf("Received signal!\n");
}

void	to_bin(int pid, char letter)
{
	int	q;
	int	status;

	q = 0;
	while (q < 8)
	{
		if ((letter & (0x01 << q)) != 0)
			status = kill(pid, SIGUSR2);
		else
			status = kill(pid, SIGUSR1);
		if (status == -1)
			ft_error();
		usleep(8000);
		q++;
	}
}

int	main(int argc, char *argv[])
{
	int				pid;
	char			*str;
	unsigned int	i;
	int				len;

	signal(SIGUSR1, &response);
	i = 0;
	if (argc != 3)
	{
		ft_printf("client: invalid arguments\n");
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_error();
	str = argv[2];
	len = ft_strlen(str);
	while (i < (unsigned int)len)
	{
		to_bin(pid, str[i]);
		i++;
	}
	to_bin(pid, '\n');
	return (0);
}
