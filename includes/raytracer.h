/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:22:42 by rnicolas          #+#    #+#             */
/*   Updated: 2016/04/21 20:17:00 by rnicolas         ###   ########.fr       */
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
**
*/

void		op_inv(t_vec trans, double **rot, t_vec *normal, t_vec *inter);
void		instance_funct2(t_func2 *funct);
void		instance_funct(t_func *funct);
void		instance_funcf(t_parse *tabf);
void		instance_func(char **tab);
int			count_light(t_ray_list *light_ray_list);
void		free_light_ray_list(t_inter *inter);
void		create_light_ray_list(t_inter *inter, t_light *light, t_vec pos);
void		int_sphere(t_inter *inter, void *e, t_ray ray, t_light *light);
void		int_quad(t_inter *inter, void *e, t_ray ray, t_light *light);
void		int_plane(t_inter *inter, void *e, t_ray ray, t_light *light);
void		push_quad(char **line);
int			sh_quad(void *e, t_ray ray, double dist);
double		res_equ_scnd(double a, double b, double c);
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
t_vec		vect_add(t_vec u, t_vec v);
t_vec		mult_scalar(t_vec u, double scalar);
t_vec		init_point(double x, double y, double z);
double		dist_point(t_vec u, t_vec v);
int			get_color(t_ray ray, t_scene sc);
double		**get_rot(double angle, t_vec ort);
void		init_ret(double ***ret);
void		get_matrice(double **ret, double angle, t_vec ort);
double		**get_rot_obj(t_vec u);
t_vec		unit_vect(double a, double b, double c);
void		apply_trans_inv(t_vec x, t_vec *y);
void		apply_trans(t_vec x, t_vec *y);
double		norm(t_vec a);
t_vec		cross_prod(t_vec u, t_vec v);
double		scalar_prod(t_vec u, t_vec v);
double		**inv_mat(double **rot);
void		apply_rot(double **rot, t_vec *vector);
char		**ft_strsplit(char * line, char c);
int			ft_all_num(char *line);

#endif
