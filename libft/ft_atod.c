/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:29:20 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/11 18:03:51 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *str)
{
	double	ret;
	int		i;
	int		sign;

	if (str[0] == '-')
		sign = -1;
	else
		sign = 1;
	ret = ft_atoi(str);
	str = ft_strchr(str, '.');
	if (!str)
		return (ret);
	str++;
	i = 10;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret + sign * ((double)(*str - '0') / (double)i);
		i = i * 10;
		str++;
	}
	return (ret);
}
