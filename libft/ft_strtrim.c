/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:16:57 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:33:21 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	sub_len_s(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	end;

	i = 0;
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		i++;
	len = ft_strlen(&s[i]) - 1;
	ft_putstr("\n");
	i = 0;
	end = 0;
	while (s[end + 1])
		end++;
	while ((s[end] == ' ') || (s[end] == '\t') || (s[end] == '\n'))
	{
		i++;
		end--;
	}
	return (len - i + 1);
}

char	*ft_strtrim(char const *s)
{
	char	*result;
	char	*null;
	size_t	len;
	size_t	i;

	if ((s) && (ft_strlen(s)))
	{
		len = sub_len_s(s);
		result = (char*)ft_memalloc(len + 1);
		result[len] = 0;
		while ((*s == ' ') || (*s == '\t') || (*s == '\n'))
			s++;
		i = 0;
		while (len--)
		{
			result[i] = *s++;
			i++;
		}
		return (result);
	}
	null = (char*)ft_memalloc(1);
	null[0] = 0;
	return (null);
}
