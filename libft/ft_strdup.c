/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:43:57 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:36:58 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	int		i;
	char	*str_cpy;

	length = ft_strlen(s1);
	str_cpy = (char*)malloc(sizeof(s1) * length + 1);
	i = 0;
	while (s1[i])
	{
		str_cpy[i] = s1[i];
		i++;
	}
	str_cpy[i] = 0;
	return (str_cpy);
}
