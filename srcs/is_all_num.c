/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 19:44:05 by hmichals          #+#    #+#             */
/*   Updated: 2016/04/26 20:23:26 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ctype.h>

/*
** Return 1 if the Cstring str is a valid double and 0 if not.
*/

int		is_all_num(char *str)
{
	int		point;
	int		i;

	i = 0;
	point = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			point++;
			i++;
		}
		if ((str[i] < '0' || str[i] > '9') || point > 1)
			return (0);
		i++;
	}
	return (1);
}

/*
** Return 1 if the Cstring str is a valid hexadecimal number amd 0 if not.
*/

int		is_all_hex(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (!isxdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
