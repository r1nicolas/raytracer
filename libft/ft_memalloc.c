/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:11:31 by hmichals          #+#    #+#             */
/*   Updated: 2013/11/24 19:19:21 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (size)
	{
		s = malloc(size);
		if (!s)
			return (NULL);
		else
			ft_bzero(s, size);
		return (s);
	}
	return (NULL);
}
