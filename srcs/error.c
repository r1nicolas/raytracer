/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:47:01 by hmichals          #+#    #+#             */
/*   Updated: 2016/04/21 17:42:54 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
** Write text in the error output then exit the program returning an error code
*/

void			put_error(char const *str)
{
	write(2, str, strlen(str));
	exit(1);
}
