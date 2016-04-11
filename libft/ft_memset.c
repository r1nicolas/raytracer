/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:11:34 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:37:59 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*b_conv;

	if (b)
	{
		b_conv = (char*)b;
		while (len--)
			*b_conv++ = (unsigned char)c;
	}
	return (b);
}
