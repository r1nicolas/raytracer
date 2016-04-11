/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:58:14 by tlepetit          #+#    #+#             */
/*   Updated: 2014/02/28 16:03:39 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hexatoi(const char *str)
{
	int		n;
	int		i;
	int		nb;

	n = ft_strlen(str);
	i = 0;
	nb = 0;
	while (i < n)
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 16 + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			nb = nb * 16 + str[i] + 10 - 'A';
		else
			return (nb);
		i++;
	}
	return (nb);
}
