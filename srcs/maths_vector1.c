/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_vector1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:29:53 by tlepetit          #+#    #+#             */
/*   Updated: 2016/04/11 17:58:59 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>

/*
** Create a vector of coordinates x, y and z.
*/

t_vec	new_vector(double x, double y, double z)
{
	t_vec	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

/*
** Create a vector of coordinates x, y and z then normalize it.
*/

t_vec	new_vector_unit(double x, double y, double z)
{
	t_vec		result;
	double		norm;

	result = new_vector(x, y, z);
	norm = vector_norm(result);
	if (norm != 0)
		result = vector_scalar_mult(result, 1 / norm);
	return (result);
}

/*
** Return the distance between two vectors.
*/

double	vector_distance(t_vec u, t_vec v)
{
	v = vector_add(u, vector_inverse(v));
	return (vector_norm(v));
}

/*
** Multiplies a vector by a scalar.
*/

t_vec	vector_scalar_mult(t_vec u, double scalar)
{
	u.x = u.x * scalar;
	u.y = u.y * scalar;
	u.z = u.z * scalar;
	return (u);
}

/*
** Add two vectors
*/

t_vec	vector_add(t_vec u, t_vec v)
{
	u.x = u.x + v.x;
	u.y = u.y + v.y;
	u.z = u.z + v.z;
	return (u);
}
