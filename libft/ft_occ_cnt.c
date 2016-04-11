/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occ_cnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:34:15 by hmichals          #+#    #+#             */
/*   Updated: 2013/12/20 16:41:51 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_occ_cnt(const char *str, char c)
{
	size_t		count;

	count = 0;
	if (str)
	{
		while (*str)
		{
			if (*str == c)
				count++;
			str++;
		}
		return (count);
	}
	return (0);
}
