/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:22:42 by rnicolas          #+#    #+#             */
/*   Updated: 2016/04/25 17:03:08 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# define WINROW 600
# define WINCOL 800

# define BUFF_SIZE 512
# define DELIM_CHAR '\n'

# include "structures.h"



/*
** function prototypes
*/

/*
** camera.c
*/

t_cam		new_cam(t_vec pos, t_vec dir, double size, double rot);
t_ray		new_ray(int x, int y, t_cam cam);

/*
** color.c
*/

int			get_color_inter(t_inter inter, t_object_list *list);
int			get_color(t_ray ray, t_scene sc);

/*
** cone.c
*/

void		cone_inter(t_inter *inter, void *obj, t_ray ray, t_light *light);
int			cone_shadow(void *obj, t_ray ray, double light_dist);

/*
** cylinder.c
*/

void		cylinder_inter(t_inter *inter, void *obj, t_ray ray, t_light *light);
int			cylinder_shadow(void *obj, t_ray ray, double light_dist);

/*
** error.c
*/

void		put_error(char const *str);

/*
** free_matrix.c
*/

void		free_matrix(double **mat);

/*
** get_next_lines.c
*/

int			get_next_line(int fd, char **line);

/*
** intersection.c
*/

t_vec		calculate_position(t_ray ray, double t);
t_vec		calculate_reflection(t_ray ray, t_vec normal);
void		change_frame(t_ray *ray, double **rot, t_vec trans);
int			is_not_in_shadow(t_vec inter, t_object_list *lst, t_ray light);

/*
** is_all_num.c
*/

int			is_all_num(char *str);

/*
** maths_obj.c
*/

double		**matrix_direction(t_vec u);
double		res_equ_scnd(double a, double b, double c);
void		op_inv(t_vec trans, double **rot, t_vec *normal, t_vec *inter);

/*
** maths_rot.c
*/

t_vec		rotation_vector(double **rot, t_vec vector);
double		**create_rotation_matrix(double angle, t_vec ort);
double		**matrix_inverse(double **rot);

/*
** maths_vector1.c
*/

t_vec		new_vector(double x, double y, double z);
t_vec		new_vector_unit(double x, double y, double z);
t_vec		vector_scalar_mult(t_vec u, double scalar);
double		vector_distance(t_vec u, t_vec v);
t_vec		vector_add(t_vec u, t_vec v);

/*
** maths_vector1.c
*/

double		vector_scalar_product(t_vec u, t_vec v);
t_vec		vector_cross_product(t_vec u, t_vec v);
double		vector_norm(t_vec a);
t_vec		vector_inverse(t_vec v);

void		create_tab_func_shadow(t_func_shadow *tab);
void		create_tab_func_inter(t_func_inter *tab);
void		create_tab_func_parse(t_func_parse *tab);
void		create_tab_type(char **tab);
int			count_light(t_ray_list *light_ray_list);
void		free_light_ray_list(t_inter *inter);
void		create_light_ray_list(t_inter *inter, t_light *light, t_vec pos);
void		int_sphere(t_inter *inter, void *e, t_ray ray, t_light *light);
void		int_quad(t_inter *inter, void *e, t_ray ray, t_light *light);
void		int_plane(t_inter *inter, void *e, t_ray ray, t_light *light);
void		push_quad(char **line);
int			sh_quad(void *e, t_ray ray, double dist);
int			sh_sphere(void *e, t_ray ray, double dist);
int			sh_plane(void *e, t_ray ray, double dist);
void		get_scene(char *path);
void		push_spot(char **line);
void		push_cam(char **line);
void		push_cone(char **line);
void		push_cylinder(char **line);
void		push_sphere(char **line);
void		push_plane(char **line);
void		test_object(char **line, int size, char *name);
char		**ft_strsplit(char * line, char c);

#endif
