/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 23:13:56 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/12 17:14:55 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_error(char *str, t_all *all)
{
	write(2, "Error\n", 6);
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	write(2, "\n", 1);
	free_struct(all);
	free_map(all);
	exit(0);
}
