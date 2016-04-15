/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:47:01 by hmichals          #+#    #+#             */
/*   Updated: 2016/04/15 18:19:24 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void			put_error(char const  *str)
{
	write(2, str, strlen(str));
	exit(1);
}
