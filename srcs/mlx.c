/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 19:21:54 by tlepetit          #+#    #+#             */
/*   Updated: 2014/03/03 17:03:51 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <mlx.h>
#include <stdlib.h>
#include <libft.h>

int				expose_hook(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int				key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		exit(0);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

void			start_mlx(void)
{
	t_env	env;

	if ((env.mlx = mlx_init()) == NULL)
	{
		ft_putstr_fd("can't open the window\n", 2);
		exit(1);
	}
	env.win = mlx_new_window(env.mlx, WINCOL, WINROW, "raytracer");
	env.img = mlx_new_image(env.mlx, WINCOL, WINROW);
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_key_hook(env.win, key_hook, &env);
	set_camera(&env);
	mlx_loop(env.mlx);
}
