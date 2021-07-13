/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:17:05 by mde-figu          #+#    #+#             */
/*   Updated: 2021/03/18 23:14:09 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*newdest;
	const unsigned char	*newsrc;

	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	if (newdest == 0 && newsrc == 0)
		return (dest);
	while (n > 0)
	{
		*newdest = *newsrc;
		newdest++;
		newsrc++;
		n--;
	}
	return (dest);
}
