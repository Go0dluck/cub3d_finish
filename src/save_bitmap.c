/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:57:27 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/15 13:51:31 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_color(t_all *all, int fd)
{
	int	x;
	int	y;
	int color;

	y = all->mlx.h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < all->mlx.w)
		{
			color = *(int*)(all->mlx.addr +
			(y * all->mlx.line_length + x * (all->mlx.bits_per_pixel / 8)));
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
}

void	int_to_char(int fz, unsigned char *bmp)
{
	bmp[0] = (unsigned char)(fz);
	bmp[1] = (unsigned char)(fz >> 8);
	bmp[2] = (unsigned char)(fz >> 16);
	bmp[3] = (unsigned char)(fz >> 24);
}

void	bmp_init(t_all *all, int fd)
{
	unsigned char bmp[54];

	all->bmp.file_size = 54 + (all->mlx.w * all->mlx.h * 4);
	ft_bzero(bmp, 54);
	bmp[0] = (unsigned char)('B');
	bmp[1] = (unsigned char)('M');
	int_to_char(all->bmp.file_size, bmp + 2);
	bmp[10] = (unsigned char)(54);
	bmp[14] = (unsigned char)(40);
	int_to_char(all->mlx.w, bmp + 18);
	int_to_char(all->mlx.h, bmp + 22);
	bmp[26] = (unsigned char)(1);
	bmp[28] = (unsigned char)(32);
	write(fd, bmp, 54);
}

void	save_screen(t_all *all)
{
	int	fd;

	if (!(fd = open("screen.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666)))
		ft_error("Error create file bmp", all);
	bmp_init(all, fd);
	get_color(all, fd);
	close(fd);
}
