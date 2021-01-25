/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:40:52 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/15 13:42:40 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	struct_init(t_all *all)
{
	all->save = 0;
	all->t_s.t_w = 64;
	all->t_s.t_h = 64;
	all->spr_s.s_w = 64;
	all->spr_s.s_h = 64;
	all->size_param = 0;
	all->size_sprite = 0;
	all->mlx.w = 0;
	all->mlx.h = 0;
	all->col_f.kol = 0;
	all->col_c.kol = 0;
	all->t_ea.img = NULL;
	all->t_no.img = NULL;
	all->t_so.img = NULL;
	all->t_we.img = NULL;
	all->t_spr.img = NULL;
	all->sprs = NULL;
	all->map = NULL;
}

void	check_save(char *file, t_all *all)
{
	int	size;

	size = ft_strlen(file);
	if (size == 6)
	{
		if (!(file[size - 1] == 'e' && file[size - 2] == 'v' &&
			file[size - 3] == 'a' && file[size - 4] == 's' &&
			file[size - 5] == '-' && file[size - 6] == '-'))
			ft_error("Not valid SAVE", all);
		all->save = 1;
	}
	else
		ft_error("Not valid SAVE", all);
}

char	*check_name(char *file, t_all *all)
{
	int size;

	size = ft_strlen(file);
	if (size > 4)
	{
		if (!(file[size - 1] == 'b' && file[size - 2] == 'u' &&
			file[size - 3] == 'c' && file[size - 4] == '.'))
			ft_error("Not valid name file map", all);
		return (file);
	}
	ft_error("Not valid name file map", all);
	return (NULL);
}

void	ft_init(t_all *all, char *agrv, int save)
{
	int	fd;

	if ((fd = open(agrv, O_RDONLY)) <= 0)
		ft_error("Not open file", all);
	(all->mlx.mlx = mlx_init()) == NULL ?
		ft_error("Eror mlx init", all) : 0;
	mlx_get_screen_size(all->mlx.mlx, &all->mlx.wm, &all->mlx.hm);
	parser_file(fd, all);
	(all->mlx.win = mlx_new_window(all->mlx.mlx, all->mlx.w,
		all->mlx.h, "CUB3D")) == NULL ? ft_error("Error mlx win", all) : 0;
	all->mlx.img = mlx_new_image(all->mlx.mlx, all->mlx.w, all->mlx.h);
	all->mlx.addr = mlx_get_data_addr(all->mlx.img, &all->mlx.bits_per_pixel,
		&all->mlx.line_length, &all->mlx.endian);
	raycast(all);
	if (save == 1)
		save_screen(all);
	if (save == 0)
	{
		mlx_hook(all->mlx.win, 2, 1L << 0, ft_hook, all);
		mlx_hook(all->mlx.win, 17, 1L << 0, ft_exit, all);
		mlx_loop(all->mlx.mlx);
	}
}

int		main(int agrc, char **agrv)
{
	t_all	all;

	struct_init(&all);
	agrc == 1 ? ft_error("No map file", &all) : 0;
	if (agrc == 2)
		ft_init(&all, check_name(agrv[1], &all), 0);
	if (agrc == 3)
	{
		check_save(agrv[2], &all);
		ft_init(&all, check_name(agrv[1], &all), 1);
	}
	agrc > 3 ? ft_error("More parametr's", &all) : 0;
	return (0);
}
