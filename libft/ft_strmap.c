/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:09:03 by hmichals          #+#    #+#             */
/*   Updated: 2014/01/09 19:49:09 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	i = 0;
	while (s[i])
		i++;
	result = ft_strnew(i + 1);
	i = 0;
	while (s[i])
	{
		result[i] = (*f)(s[i]);
		i++;
	}
	return (result);
}
