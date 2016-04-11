/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 21:10:40 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:31:12 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1bis;
	char	*s2bis;

	if (!s1 || !s2)
		return (0);
	s1bis = (char*)s1;
	s2bis = (char*)s2;
	i = 0;
	while ((s1bis[i] == s2bis[i]) && (n))
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (s1bis[i] - s2bis[i]);
}
