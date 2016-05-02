/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:47:23 by rnicolas          #+#    #+#             */
/*   Updated: 2015/12/08 19:21:15 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	count;
	char			*result;

	if (s == NULL)
		return (NULL);
	count = 0;
	result = (char*)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (count < len)
	{
		result[count] = s[start + count];
		count++;
	}
	result[count] = '\0';
	return (result);
}
