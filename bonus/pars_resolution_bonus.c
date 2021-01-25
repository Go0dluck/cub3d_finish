/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_resolution_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:18:52 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/15 13:07:13 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	pars_resolution(char **str, t_all *all)
{
	all->mlx.w != 0 ? ft_error("Duplicate resolution", all) : 0;
	if (ft_split_size(str) == 3)
	{
		all->size_param++;
		if (ft_isnum(str[1]) == 1)
		{
			free_split(str);
			ft_error("Not valid parametr's resolution", all);
		}
		all->mlx.w = ft_atoi(str[1]);
		all->mlx.w <= 0 || all->mlx.w > 1920 ? all->mlx.w = 1920 : 0;
		if (ft_isnum(str[2]) == 1)
		{
			free_split(str);
			ft_error("Not valid parametr's resolution", all);
		}
		all->mlx.h = ft_atoi(str[2]);
		all->mlx.h <= 0 || all->mlx.h > 1080 ? all->mlx.h = 1080 : 0;
	}
	else
	{
		free_split(str);
		ft_error("Not valid parametr's resolution", all);
	}
}
