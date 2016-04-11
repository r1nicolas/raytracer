/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 21:02:51 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:30:41 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*src;

	if ((!s) || (!n))
		return (NULL);
	src = (char*)s;
	while (n)
	{
		if (*src == (unsigned char)c)
			return ((void*)src);
		src++;
		n--;
	}
	return (NULL);
}
