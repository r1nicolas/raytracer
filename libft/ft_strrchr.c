/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:22:50 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:36:49 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;

	len = ft_strlen(s);
	while (len)
	{
		if (s[len] == c)
			return ((char*)&s[len]);
		len--;
	}
	if (s[len] == c)
		return ((char*)s);
	return (NULL);
}
