/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:46:52 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:35:42 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == 0)
		return (NULL);
	str = (char*)malloc(sizeof(char) * size);
	if (str == 0)
		return (NULL);
	ft_memset(str, 0, size);
	return (str);
}
