/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfusion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:07:57 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:34:51 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfusion(char *s1, char *s2)
{
	size_t	len;
	char	*result;
	char	*result_save;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char*)ft_memalloc(sizeof(char) * len + 1);
	if (result == 0)
		return (NULL);
	len = 0;
	result_save = result;
	if (s1)
	{
		while (s1[len])
			*result++ = s1[len++];
		free(s1);
	}
	len = 0;
	if (s2)
	{
		while (s2[len])
			*result++ = s2[len++];
		free(s2);
	}
	*result = 0;
	return (result_save);
}
