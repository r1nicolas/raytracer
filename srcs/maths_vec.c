/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 18:40:12 by tlepetit          #+#    #+#             */
/*   Updated: 2014/02/25 18:52:01 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <math.h>

double			scalar_prod(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec			cross_prod(t_vec u, t_vec v)
{
	t_vec		rot;
	double		r;

	rot.x = v.z * u.y - v.y * u.z;
	rot.y = v.x * u.z - v.z * u.x;
	rot.z = v.y * u.x - v.x * u.y;
	r = sqrt(rot.x * rot.x + rot.y * rot.y + rot.z * rot.z);
	if (r != 0)
	{
		rot.x /= r;
		rot.y /= r;
		rot.z /= r;
	}
	return (rot);
}

double			norm(t_vec a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

void			apply_trans(t_vec x, t_vec *y)
{
	y->x = y->x + x.x;
	y->y = y->y + x.y;
	y->z = y->z + x.z;
}

void			apply_trans_inv(t_vec x, t_vec *y)
{
	y->x = y->x - x.x;
	y->y = y->y - x.y;
	y->z = y->z - x.z;
}
