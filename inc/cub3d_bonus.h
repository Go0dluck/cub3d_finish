/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:34:17 by ksharee           #+#    #+#             */
/*   Updated: 2021/01/14 16:23:04 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# define MS 0.3
# define MS2 0.2
# define BUFFER_SIZE 1000
# define UDIV 1
# define VDIV 1
# define VMOVE 0.0
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <math.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct		s_bmp
{
	int				file_size;
	int				unused;
	int				offset;
	int				header;
	int				plane;
	int				bpp;
}					t_bmp;

typedef struct		s_sprite
{
	char			num;
	double			x;
	double			y;
	double			spr_dist;
}					t_sprite;

typedef struct		s_color
{
	int				kol;
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_sprite_set
{
	int				vms;
	double			spx;
	double			spy;
	double			invdet;
	double			trfx;
	double			trfy;
	int				spscrx;
	int				sp_h;
	int				dr_sy;
	int				dr_ey;
	int				sp_w;
	int				dr_sx;
	int				dr_ex;
	int				stripe;
	int				t_x;
	int				d;
	int				t_y;
	int				s_w;
	int				s_h;
}					t_sprite_set;

typedef struct		s_text_set
{
	int				t_w;
	int				t_h;
	int				t_x;
	int				t_y;
	double			step;
	double			t_p;
	unsigned int	color;
	double			wallx;
}					t_text_set;

typedef struct		s_text
{
	void			*img;
	int				img_w;
	int				img_h;
	void			*addr;
	char			*path;
	int				line_length;
	int				bpp;
	int				endian;
}					t_text;

typedef struct		s_floor
{
	bool			is_floor;
	double			rd_x0;
	double			rd_y0;
	double			rd_x1;
	double			rd_y1;
	int				p;
	double			p_z;
	double			r_dist;
	double			f_sx;
	double			f_sy;
	double			f_x;
	double			f_y;
	int				c_x;
	int				c_y;
	int				tx;
	int				ty;
}					t_floor;

typedef struct		s_ray
{
	double			pitch;
	double			d_x;
	double			d_y;
	double			p_x;
	double			p_y;
	double			pl_x;
	double			pl_y;
	double			c_x;
	double			r_dx;
	double			r_dy;
	double			d_dx;
	double			d_dy;
	double			s_dx;
	double			s_dy;
	double			w_dist;
	double			*z_buf;
	int				m_x;
	int				m_y;
	int				s_x;
	int				s_y;
	int				hit;
	int				side;
	int				l_h;
	int				d_s;
	int				d_e;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
	int				w;
	int				h;
}					t_mlx;

typedef struct		s_plr
{
	char			position;
	double			x;
	double			y;
}					t_plr;

typedef struct		s_all
{
	int				flag_w;
	int				flag_s;
	int				flag_a;
	int				flag_d;
	int				flag_l;
	int				flag_r;
	bool			death;
	char			**map;
	int				size_map;
	int				save;
	int				size_param;
	int				size_sprite;
	int				blast;
	int				heart_size;
	t_plr			plr;
	t_mlx			mlx;
	t_ray			ray;
	t_text_set		t_s;
	t_text_set		life_s;
	t_text_set		gun_s;
	t_text_set		blast_s;
	t_text			t_f;
	t_text			t_c;
	t_text			t_no;
	t_text			t_so;
	t_text			t_we;
	t_text			t_ea;
	t_text			t_spr;
	t_text			t_spr2;
	t_text			t_spr_bad;
	t_text			t_life;
	t_text			t_blast;
	t_text			t_gun;
	t_text			dead;
	t_sprite		*sprs;
	t_sprite_set	spr_s;
	t_sprite_set	death_s;
	t_sprite		*sprs_bad;
	t_sprite_set	sprbad_s;
	t_color			col_f;
	t_color			col_c;
	t_bmp			bmp;
	t_floor			flor_cel;
}					t_all;

void				del_sprites_gomer(t_all *all);
void				draw_dead(t_all *all);
void				parser_file_map(int fd, t_all *all);
int					get_next_line(int fd, char **line);
void				ft_error(char *str, t_all *all);
void				raycast(t_all *all);
int					ft_hook(int keycode, t_all *all);
void				ft_putpixel(t_all *all, int x, int y, int color);
void				free_split(char **str);
int					ft_split_size(char **str);
void				free_struct(t_all *all);
void				free_map(t_all *all);
void				draw_sprites(t_all *all);
void				save_screen(t_all *all);
void				draw_vertical_sprite(t_all *all, t_sprite sprite);
void				sort_sprites(t_all *all);
void				check_line_map(char *str_map, t_all *all);
void				set_text_sprite(t_all *all, char *path);
void				set_text_sprite_two(t_all *all, char *path);
void				texture_seting(t_all *all);
void				verline(int x, t_all *all);
int					ft_isnum(char *str);
void				raycast_floor_ceilling(t_all *all);
unsigned int		shade_color(unsigned int color, double dist);
void				draw_lifebar(t_all *all);
void				draw_blast(t_all *all);
void				struct_init(t_all *all);
int					ft_hook_mouse(int button, int x, int y, t_all *all);
void				del_sprites(t_all *all);
void				left_right(t_all *all, int i);
int					ft_exit(t_all *all);
void				move_up_down(t_all *all, int i);
void				move_left_right(t_all *all, int i);
void				left_right(t_all *all, int i);
int					hook_flag(t_all *all);
int					ft_hook2(int keycode, t_all *all);

void				parser_file(int fd, t_all *all);
void				pars_resolution(char **str, t_all *all);
void				pars_floor(char **str, t_all *all);
void				pars_texture_path(char **str, t_all *all);
void				pars_ceilling(char **str, t_all *all);
void				parser_player(t_all *all);
void				parser_sprites(t_all *all);

#endif
