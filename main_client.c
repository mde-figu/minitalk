/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:52:12 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/14 19:10:49 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	howto(void)
{
	write(1, "how 2 use:./client [server-pid] [message]\n", 42);
}

void	send_char(int pid, unsigned char byte)
{
	uint8_t	counter;

	counter = 1 << 6;
	while (counter)
	{
		if (byte & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
				fail("wrong pid\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				fail("wrong pid\n");
		}
		counter >>= 1;
		usleep(10);
	}
}

void	handle(char *str_pid, char *message)
{
	int			pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		send_char(pid, *message);
		++message;
	}
	send_char(pid, *message);
}

void	success(int sig)
{
	(void)sig;
	write(1, "*Message received.*\n", 21);
}

int	main(int argc, char **argv)
{
	struct sigaction	active_act;

	if (argc != 3)
	{
		howto();
		exit (0);
	}
	signal(SIGUSR1, success);
	handle(argv[1], argv[2]);
	return (0);
}
