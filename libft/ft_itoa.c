/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:44:09 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:29:44 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	sub_len(int n)
{
	size_t	result;

	result = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		n *= -1;
		result++;
	}
	while (n)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char			*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	int		sign;

	sign = 0;
	len = sub_len(n);
	result = (char*)malloc(sizeof(char) * len + 1);
	result[len] = 0;
	if (n < 0)
		sign = -1;
	while (len)
	{
		if (sign == -1)
			result[len - 1] = (n % 10) * -1 + '0';
		else
			result[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
