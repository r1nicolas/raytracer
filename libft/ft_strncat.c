/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:23:24 by hmichals          #+#    #+#             */
/*   Updated: 2013/12/02 14:42:27 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s1);
	while ((n--) && (*s2))
	{
		s1[len] = *s2;
		len++;
		s2++;
	}
	s1[len] = 0;
	return (s1);
}
