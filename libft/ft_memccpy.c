/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 21:20:46 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:30:03 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)c)
		{
			i++;
			return (&str1[i]);
		}
		i++;
	}
	return (NULL);
}
