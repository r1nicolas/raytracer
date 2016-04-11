/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:53:45 by hmichals          #+#    #+#             */
/*   Updated: 2013/11/21 19:56:42 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	while ((*s1 == *s2) && (*s1 != 0))
	{
		s1++;
		s2++;
	}
	if ((*s1 == *s2) && (*s1 == 0))
		return (1);
	return (0);
}
