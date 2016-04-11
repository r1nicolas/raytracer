/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:22:42 by rnicolas          #+#    #+#             */
/*   Updated: 2014/03/03 18:30:25 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <unistd.h>
#include <libft.h>
#include <mlx.h>

int		main(int ac, char **av)
{
	if (ac != 2)
		put_error("usage: ./raytracer scene\n");
	get_scene(av[1]);
	start_mlx();
	return (0);
}
