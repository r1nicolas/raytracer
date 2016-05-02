/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:11:10 by rnicolas          #+#    #+#             */
/*   Updated: 2015/12/08 18:57:50 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*memalloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result)
	{
		bzero(result, size);
		return (result);
	}
	return (NULL);
}
