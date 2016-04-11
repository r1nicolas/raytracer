/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:19:25 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/05 19:32:26 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putdouble(double x)
{
	int		i;

	if (x < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	ft_putnbr((int)x);
	ft_putchar('.');
	i = 0;
	while (i < 5)
	{
		x = x - (double)((int)x);
		x = x * 10;
		ft_putnbr((int)x);
		i++;
	}
}
