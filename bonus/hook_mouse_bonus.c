/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:54:27 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/13 16:42:43 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int		ft_exit(t_all *all)
{
	free_struct(all);
	free_map(all);
	exit(0);
	return (0);
}

void	blast_gomer(t_all *all)
{
	all->blast = 1;
	raycast(all);
	all->blast = 0;
	del_sprites_gomer(all);
}

int		ft_hook_mouse(int button, int x, int y, t_all *all)
{
	if (all->death == false)
	{
		if (x < all->mlx.w / 2 && button == 2)
			left_right(all, -1);
		if (x > all->mlx.w / 2 && button == 2)
			left_right(all, 1);
		if (y < all->mlx.h / 2 && button == 2)
		{
			all->ray.pitch += 400 * MS;
			all->ray.pitch > 200 ? all->ray.pitch = 200 : 0;
		}
		if (y > all->mlx.h / 2 && button == 2)
		{
			all->ray.pitch -= 400 * MS;
			all->ray.pitch < -200 ? all->ray.pitch = -200 : 0;
		}
		if (button == 1)
			blast_gomer(all);
		raycast(all);
	}
	return (0);
}
