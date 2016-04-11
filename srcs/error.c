/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:47:01 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/03 14:48:13 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <libft.h>
#include <unistd.h>

void			put_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
