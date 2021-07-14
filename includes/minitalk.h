/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:29:25 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/14 18:30:53 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <signal.h>
# include <zconf.h>
# include "libft.h"
# define BUFFSIZE 1024
# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s_stack
{
	char		message[BUFFSIZE];
	int			top_bit;
	int			top_byte;
	_Bool		ackn_all;
	_Bool		overflow;
}				t_stack;

t_stack			g_msg = {{0}, 1 << 6, 0, FALSE, FALSE};

void			fail(char *str_error);

#endif
