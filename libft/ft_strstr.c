/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:36:58 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:35:14 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	diff;

	if (!*s2)
		return ((char*)s1);
	diff = 0;
	i = 0;
	while (s1[i])
	{
		i -= diff;
		diff = 0;
		if (s1[i] == s2[diff])
		{
			while (s1[i + diff] == s2[diff])
			{
				if (s2[diff] == 0)
					return ((char*)&s1[i]);
				diff++;
			}
			i += diff;
		}
		i++;
	}
	return (NULL);
}
