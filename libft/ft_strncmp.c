/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:37:59 by hmichals          #+#    #+#             */
/*   Updated: 2013/11/20 18:42:52 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i]) && (i < n))
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
