/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:18:20 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:31:30 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*s1_save;
	char	*s2_save;

	if ((s1) && (s2) && (n))
	{
		s2_save = (char*)s2;
		s1_save = (char*)s1;
		while (n--)
		{
			*s1_save = *s2_save++;
			s1_save++;
		}
	}
	return (s1);
}
