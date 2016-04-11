/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:21:44 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:31:51 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*s1_bis;
	char	*s2_bis;

	if (s1)
	{
		s1_bis = (char*)s1;
		s2_bis = (char*)s2;
		if (s1 == s2)
			return (s1);
		else if (s2 > s1 && s2)
			while (n--)
				*s1_bis++ = *s2_bis++;
		else if (s1 > s2 && s2)
		{
			s1_bis += n;
			s2_bis += n;
			while (n--)
				*--s1_bis = *--s2_bis;
		}
	}
	return (s1);
}
