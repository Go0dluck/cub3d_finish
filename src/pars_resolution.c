/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:18:52 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/15 12:54:01 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	pars_resolution_next(char **str, t_all *all)
{
	all->size_param++;
	if (ft_isnum(str[1]) == 1)
	{
		free_split(str);
		ft_error("Not valid parametr's resolution", all);
	}
	all->mlx.w = ft_atoi(str[1]);
	(all->mlx.w <= 0 || all->mlx.w > all->mlx.wm) && all->save == 0
		? all->mlx.w = all->mlx.wm : 0;
	if (ft_isnum(str[2]) == 1)
	{
		free_split(str);
		ft_error("Not valid parametr's resolution", all);
	}
	all->mlx.h = ft_atoi(str[2]);
	(all->mlx.h <= 0 || all->mlx.h > all->mlx.hm) && all->save == 0
		? all->mlx.h = all->mlx.hm : 0;
}

void	pars_resolution(char **str, t_all *all)
{
	all->mlx.w != 0 ? ft_error("Duplicate resolution", all) : 0;
	if (ft_split_size(str) == 3)
		pars_resolution_next(str, all);
	else
	{
		free_split(str);
		ft_error("Not valid parametr's resolution", all);
	}
}
