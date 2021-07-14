/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:12:25 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/14 19:07:12 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	print_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "pid: ", 5);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
}

void	used_bit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	if (g_msg.top_bit)
	{
		g_msg.top_bit = 1 << 6;
		++(g_msg.top_byte);
	}
	g_msg.message[g_msg.top_byte] += g_msg.top_bit;
	g_msg.top_bit >>= 1;
	if (g_msg.top_byte == BUFFSIZE - 2 && !g_msg.top_bit)
		g_msg.overflow = TRUE;
}

void	null_bit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_msg.top_bit)
	{
		g_msg.top_bit = 1 << 6;
		++(g_msg.top_byte);
	}
	g_msg.top_bit >>= 1;
	if (g_msg.top_byte == BUFFSIZE - 2 && !g_msg.top_bit)
		g_msg.overflow = TRUE;
	else if (!g_msg.message[g_msg.top_byte] && !g_msg.top_bit)
	{
		g_msg.ackn_all = TRUE;
		kill(info->si_pid, SIGUSR1);
	}
}

_Bool	handler(void)
{
	while (42)
	{
		pause();
		if (g_msg.ackn_all || g_msg.overflow)
		{
			write(1, g_msg.message, ft_strlen(g_msg.message));
			ft_bzero(g_msg.message, BUFFSIZE);
			g_msg.top_byte = 0;
			g_msg.top_bit = 1 << 6;
			if (g_msg.ackn_all)
				write(1, "\n", 1);
			g_msg.ackn_all = FALSE;
			g_msg.overflow = FALSE;
		}
	}
	return (TRUE);
}

int	main(void)
{
	struct sigaction	active_act;
	struct sigaction	null_act;

	active_act.sa_sigaction = used_bit;
	null_act.sa_sigaction = null_bit;
	active_act.sa_flags = SA_SIGINFO;
	null_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &active_act, NULL) != 0)
		fail("signal from USR1 failed\n");
	if (sigaction(SIGUSR2, &null_act, NULL) != 0)
		fail("signal from USR2 failed\n");
	print_pid();
	ft_bzero(g_msg.message, BUFFSIZE);
	handler();
}
