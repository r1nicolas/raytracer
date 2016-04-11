/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:37:52 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:28:47 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *src)
{
	int	i;
	int	result;
	int	sign;

	result = 0;
	i = 0;
	sign = 0;
	while ((src[i] == '\n') || (src[i] == '\v') || (src[i] == '\t')
		|| (src[i] == '\r') || (src[i] == '\f') || (src[i] == ' '))
		i++;
	if (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-')
			sign = -1;
		i++;
	}
	while ((src[i] >= '0') && (src[i] <= '9'))
	{
		result = result * 10 + (src[i] - '0');
		i++;
	}
	if (sign == -1)
		result *= -1;
	return (result);
}
