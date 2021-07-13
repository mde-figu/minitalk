/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:12:25 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/13 15:14:51 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	print_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "pid: ", 5);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
}

int	main(void)
{
	print_pid();
}
