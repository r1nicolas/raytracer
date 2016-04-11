/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:14:46 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:35:57 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len;
	char	*s2_bis;

	s2_bis = (char*)s2;
	len = ft_strlen(s1);
	while (*s2_bis)
	{
		s1[len] = *s2_bis;
		len++;
		s2_bis++;
	}
	s1[len] = 0;
	return (s1);
}
