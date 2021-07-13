/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:29:25 by mde-figu          #+#    #+#             */
/*   Updated: 2021/07/13 12:04:15 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <signal.h>
# include <zconf.h>
# include "../libft/libft.h"
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
	_Bool		all_receive;
	_Bool		buff_overflow;
}				t_stack;

//t_stack			g_to_print = {{0}, 1 << 6, 0, FALSE, FALSE};

void			fail(char *str_error);

#endif
