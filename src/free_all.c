/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:21:29 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/14 17:34:26 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		ft_exit(t_all *all)
{
	free_struct(all);
	free_map(all);
	exit(0);
	return (0);
}

int		ft_split_size(char **str)
{
	int size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	free_split(char **str)
{
	int size;

	size = ft_split_size(str);
	while (size)
	{
		free(str[--size]);
	}
	free(str);
}

void	free_struct(t_all *all)
{
	all->sprs != NULL ? free(all->sprs) : 0;
	all->t_spr.img != NULL ?
		mlx_destroy_image(all->mlx.mlx, all->t_spr.img) : 0;
	all->t_no.img != NULL ? mlx_destroy_image(all->mlx.mlx, all->t_no.img) : 0;
	all->t_so.img != NULL ? mlx_destroy_image(all->mlx.mlx, all->t_so.img) : 0;
	all->t_we.img != NULL ? mlx_destroy_image(all->mlx.mlx, all->t_we.img) : 0;
	all->t_ea.img != NULL ? mlx_destroy_image(all->mlx.mlx, all->t_ea.img) : 0;
	all->mlx.img != NULL ? mlx_destroy_image(all->mlx.mlx, all->mlx.img) : 0;
	all->mlx.win != NULL ? mlx_destroy_window(all->mlx.mlx, all->mlx.win) : 0;
	free(all->mlx.mlx);
}

void	free_map(t_all *all)
{
	if (all->map != NULL)
	{
		while (all->size_map)
			free(all->map[--all->size_map]);
		free(all->map);
	}
}
