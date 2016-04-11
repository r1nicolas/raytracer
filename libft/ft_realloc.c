/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 13:55:01 by hmichals          #+#    #+#             */
/*   Updated: 2013/12/11 13:38:22 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t old_size)
{
	void	*new_ptr;

	if ((ptr) && (!size))
	{
		free(ptr);
		return (NULL);
	}
	else if ((!ptr) && (!size))
		return (NULL);
	else if (ptr && size && old_size)
	{
		new_ptr = ft_memalloc(size);
		if (old_size <= size)
			ft_memmove(new_ptr, ptr, old_size);
		else
			ft_memmove(new_ptr, ptr, size);
		free(ptr);
		return (new_ptr);
	}
	new_ptr = ft_memalloc(size);
	return (new_ptr);
}
