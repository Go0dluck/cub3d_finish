# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/14 12:45:38 by ksharee           #+#    #+#              #
#    Updated: 2021/01/14 17:31:21 by ksharee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
NAME_BONUS		=	cub3D_bonus

PATH_INC		=	./inc
PATH_SRC		=	./src
PATH_SRC_BONUS	=	./bonus
PATH_OBJ		=	./obj
PATH_LIBFT		=	libft
PATH_LIBMLX		=	minilibx

SRCS			=	cub3d.c ft_putpixel.c gnl.c hook.c \
					pars_map.c raycast.c ft_error.c free_all.c rgb_color.c \
					pars_all.c pars_ceilling_color.c pars_floor_color.c pars_resolution.c pars_text.c \
					pars_player.c pars_sprites.c draw_sprites.c draw_sprites2.c save_bitmap.c \
					pars_map2.c raycast2.c ft_isnum.c
SRCS_BONUS		=	cub3d_bonus.c ft_putpixel_bonus.c gnl_bonus.c hook_bonus.c \
					pars_map_bonus.c raycast_bonus.c ft_error_bonus.c free_all_bonus.c rgb_color_bonus.c \
					pars_all_bonus.c pars_ceilling_color_bonus.c pars_floor_color_bonus.c pars_resolution_bonus.c pars_text_bonus.c \
					pars_player_bonus.c pars_sprites_bonus.c draw_sprites_bonus.c draw_sprites2_bonus.c save_bitmap_bonus.c \
					pars_map2_bonus.c raycast2_bonus.c ft_isnum_bonus.c raycast_floor_ceilling_bonus.c lifebar_bonus.c \
					struct_init_bonus.c hook_mouse_bonus.c del_sprites_bonus.c
OBJS			=	$(addprefix $(PATH_OBJ)/, $(SRCS:.c=.o))
OBJS_BONUS		=	$(addprefix $(PATH_OBJ)/, $(SRCS_BONUS:.c=.o))
INCS			=	$(addprefix $(PATH_INC)/, cub3d.h)
INCS_BONUS		=	$(addprefix $(PATH_INC)/, cub3d_bonus.h)

COMP			=	gcc
COMP_FLAG		=	-Wall -Werror -Wextra -g
COMP_ADD		=	-I$(PATH_INC)

METAL_MLX		= libmlx.dylib -framework Metal -framework AppKit

RM				= rm -rf

all:			init $(NAME)

bonus:			init $(NAME_BONUS)

init:
				echo "$(_INFO) Initialize $(NAME)"
				$(shell mkdir -p $(PATH_OBJ))
				make -C $(PATH_LIBFT)
				make -C $(PATH_LIBMLX)
				mv $(PATH_LIBMLX)/libmlx.dylib .

$(NAME_BONUS):	$(OBJS_BONUS) $(INCS_BONUS)
				$(COMP) $(COMP_FLAG) $(COMP_ADD) -o $(NAME_BONUS) $(OBJS_BONUS) -Llibft -lft $(METAL_MLX)

$(PATH_OBJ)/%.o:	$(PATH_SRC_BONUS)/%.c $(INCS_BONUS)
					$(COMP) $(COMP_FLAG) $(COMP_ADD) -o $@ -c $<

$(NAME):		$(OBJS) $(INCS)
				$(COMP) $(COMP_FLAG) $(COMP_ADD) -o $(NAME) $(OBJS) -Llibft -lft $(METAL_MLX)

$(PATH_OBJ)/%.o:	$(PATH_SRC)/%.c $(INCS)
					$(COMP) $(COMP_FLAG) $(COMP_ADD) -o $@ -c $<

clean:
				$(RM) $(PATH_OBJ)
				make -C $(PATH_LIBFT) clean
				make -C $(PATH_LIBMLX) clean

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)
				$(RM) libmlx.dylib
				$(RM) screen.bmp
				make -C $(PATH_LIBFT) fclean

re:				fclean all

.PHONY: 		all fclean clean re
