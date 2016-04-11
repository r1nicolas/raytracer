/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmichals <hmichals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 16:36:53 by hmichals          #+#    #+#             */
/*   Updated: 2014/03/27 17:24:26 by hmichals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raytracer.h>
#include <libft.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

struct s_scene	g_scene;

static void		init_default(void)
{
	t_vec		pos;
	t_vec		u;

	pos = init_point(1, 1, 1);
	u = unit_vect(-1, -1, -1);
	g_scene.cam = get_cam(pos, u, 1, 0);
	g_scene.lst = NULL;
	g_scene.light = NULL;
}

static void		is_valid(char **line)
{
	char	*tab[7];
	int		i;

	instance_func(tab);
	if (line != NULL)
	{
		if (ft_strcmp(line[0], ">") != 0)
			put_error("format error\n");
		i = 0;
		while (i < 7 && line[1])
		{
			if (!ft_strcmp(tab[i], line[1]))
				return ;
			i++;
		}
		put_error("name error\n");
	}
}

static void		get_params(char **line)
{
	t_parse		tab_f[7];
	char		*tab[7];
	int			i;

	instance_func(tab);
	instance_funcf(tab_f);
	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(tab[i], line[1]) == 0)
			tab_f[i](line);
		i++;
	}
}

static void		is_dir(char *path)
{
	struct stat	file_st;

	if (stat(path, &file_st) == 0 && S_ISDIR(file_st.st_mode))
		put_error("directory is not a valid scene.\n");
}

void			get_scene(char *path)
{
	int			fd;
	char		**split;
	char		*line;
	int			ret;

	init_default();
	is_dir(path);
	if ((fd = open(path, O_RDONLY)) == -1)
		put_error("can't access to the file.\n");
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (line != NULL)
		{
			if (line[0] != '#' && (split = ft_strsplit(line, ' ')) != NULL)
			{
				is_valid(split);
				get_params(split);
				free(split);
			}
			free(line);
		}
	}
}
