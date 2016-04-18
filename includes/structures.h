/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:16:14 by hmichals          #+#    #+#             */
/*   Updated: 2016/04/18 19:31:22 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct				s_vec
{
	double					x;
	double					y;
	double					z;
}							t_vec;

typedef enum				e_object
{
	plane,
	sphere,
	cylinder,
	cone,
	quad
}							t_object;

typedef struct				s_object_list
{
	void					*e;
	t_object				obj;
	struct s_object_list	*next;
}							t_object_list;

typedef struct				s_sphere
{
	t_vec					center;
	double					radius;
	int						color;
}							t_sphere;

typedef struct				s_plane
{
	double					a;
	double					b;
	double					c;
	double					d;
	int						color;
}							t_plane;

typedef struct				s_cylinder
{
	double					**rot;
	double					**inv;
	t_vec					trans;
	double					radius;
	int						color;
}							t_cylinder;

typedef struct				s_cone
{
	double					**rot;
	double					**inv;
	t_vec					apex;
	double					angle;
	int						color;
}							t_cone;

typedef struct				s_ray
{
	t_vec					point;
	t_vec					dir;
}							t_ray;

typedef struct				s_cam
{
	t_vec					pos;
	double					dist;
	t_vec					dir;
	t_vec					down;
	t_vec					right;
	double					size;
}							t_cam;

typedef struct				s_ray_list
{
	t_ray					light;
	struct s_ray_list		*next;
}							t_ray_list;

typedef struct				s_inter
{
	double					*dist;
	t_ray_list				*light_ray_list;
	t_vec					normal;
	t_vec					refl;
	t_vec					inter;
	int						color;
}							t_inter;

typedef struct				s_light
{
	t_vec					spot;
	struct s_light			*next;
}							t_light;

typedef struct				s_scene
{
	t_object_list			*list;
	t_vec					spot;
	t_cam					cam;
	t_light					*light;
}							t_scene;

extern t_scene	g_scene;

typedef struct				s_quad
{
	double					a;
	double					b;
	double					c;
	double					d;
	double					e;
	double					f;
	double					g;
	double					h;
	double					i;
	double					j;
	int						color;
}							t_quad;

typedef int					(*t_func2)(void *e, t_ray ray, double dist);
typedef void				(*t_func)(t_inter *pt, void *e, t_ray ray, t_light *li);
typedef void				(*t_parse)(char **line);

#endif
