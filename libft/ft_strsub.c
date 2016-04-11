/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:02:14 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:33:47 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*str;

	result = (char*)malloc(sizeof(char) * len + 1);
	if (result == 0)
		return (NULL);
	str = result;
	while (len--)
	{
		*result++ = s[start];
		start++;
	}
	*result = 0;
	return (str);
}
