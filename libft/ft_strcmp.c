/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:31:33 by hmichals          #+#    #+#             */
/*   Updated: 2014/01/13 16:33:18 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while ((s1[i] == s2[i]) && (s1[i]))
			i++;
		return (s1[i] - s2[i]);
	}
	else if (s1 != NULL)
		return (*s1);
	return (*s2);
}
