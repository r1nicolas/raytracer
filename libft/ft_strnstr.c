/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:51:06 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:35:30 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	dif;
	size_t	i;

	if (!*s2)
		return ((char*)s1);
	dif = 0;
	i = 0;
	while (s1[i] && n)
	{
		i -= dif;
		dif = 0;
		if (s1[i] == s2[dif])
		{
			while ((s1[i + dif] == s2[dif]) && n--)
				if (s2[dif++] == 0)
					return ((char*)&s1[i]);
			i += dif;
			n += (dif - 1);
		}
		else
			n--;
		i++;
	}
	return (NULL);
}
