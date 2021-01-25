/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:47:21 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/14 14:48:57 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	left_right(t_all *all, int i)
{
	double olddirx;
	double oldplanex;

	olddirx = all->ray.d_x;
	oldplanex = all->ray.pl_x;
	all->ray.d_x = all->ray.d_x * cos(MS2 * i) -
		all->ray.d_y * sin(MS2 * i);
	all->ray.d_y = olddirx * sin(MS2 * i) +
		all->ray.d_y * cos(MS2 * i);
	all->ray.pl_x = all->ray.pl_x * cos(MS2 * i) -
		all->ray.pl_y * sin(MS2 * i);
	all->ray.pl_y = oldplanex * sin(MS2 * i) +
		all->ray.pl_y * cos(MS2 * i);
	raycast(all);
}

void	move_up_down(t_all *all, int i)
{
	if (i == 0)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x +
			all->ray.d_x * MS)] != '1')
			all->plr.x += all->ray.d_x * MS;
		if (all->map[(int)(all->plr.y + all->ray.d_y *
			MS)][(int)all->plr.x] != '1')
			all->plr.y += all->ray.d_y * MS;
	}
	else if (i == 1)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x -
			all->ray.d_x * MS)] != '1')
			all->plr.x -= all->ray.d_x * MS;
		if (all->map[(int)(all->plr.y - all->ray.d_y *
			MS)][(int)all->plr.x] != '1')
			all->plr.y -= all->ray.d_y * MS;
	}
	raycast(all);
}

void	move_left_right(t_all *all, int i)
{
	if (i == 0)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x -
			all->ray.pl_x * MS)] != '1')
			all->plr.x -= all->ray.pl_x * MS;
		if (all->map[(int)(all->plr.y - all->ray.pl_y *
			MS)][(int)all->plr.x] != '1')
			all->plr.y -= all->ray.pl_y * MS;
	}
	else if (i == 1)
	{
		if (all->map[(int)all->plr.y][(int)(all->plr.x +
			all->ray.pl_x * MS)] != '1')
			all->plr.x += all->ray.pl_x * MS;
		if (all->map[(int)(all->plr.y + all->ray.pl_y *
			MS)][(int)all->plr.x] != '1')
			all->plr.y += all->ray.pl_y * MS;
	}
	raycast(all);
}

int		ft_hook(int keycode, t_all *all)
{
	if (keycode == 53)
		ft_exit(all);
	else if (keycode == 0)
		move_left_right(all, 0);
	else if (keycode == 2)
		move_left_right(all, 1);
	else if (keycode == 13)
		move_up_down(all, 0);
	else if (keycode == 1)
		move_up_down(all, 1);
	else if (keycode == 123)
		left_right(all, -1);
	else if (keycode == 124)
		left_right(all, 1);
	return (0);
}
