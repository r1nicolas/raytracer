/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_vector2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 18:40:12 by tlepetit          #+#    #+#             */
/*   Updated: 2014/02/25 18:52:01 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>

/*
** Return the dot product of two vector.
*/

double			vector_dot_product(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

/*
** Return the cross product of two vector.
*/

t_vec			vector_cross_product(t_vec u, t_vec v)
{
	t_vec		result;
	double		norm;

	result.x = v.z * u.y - v.y * u.z;
	result.y = v.x * u.z - v.z * u.x;
	result.z = v.y * u.x - v.x * u.y;
	norm = vector_norm(result);
	if (norm != 0)
		result = vector_scalar_mult(result, 1 / norm);
	return (result);
}

/*
** Return the norm of a vector.
*/

double			vector_norm(t_vec a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

/*
** Return the inverse of a vector.
*/

t_vec			vector_inverse(t_vec v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	return (v);
}
