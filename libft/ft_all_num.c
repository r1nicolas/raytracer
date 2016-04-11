/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 19:44:05 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/03 18:02:46 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_all_num(char *str)
{
	int		point;

	point = 0;
	if (!str)
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str == '.' && *(str + 1))
		{
			point++;
			str++;
		}
		if ((*str < '0' || *str > '9') || point > 1)
			return (0);
		str++;
	}
	return (1);
}
