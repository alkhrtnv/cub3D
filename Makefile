NAME	=	cub3D

INCL	=	includes

MAKE	=	make

OBJ_DIR	=	.obj

LIB		=	./libft/libft.a

#LIBMLX	=	./mlx/libmlx.a

SRCS_DIR=	srcs

SRCS	=	$(SRCS_DIR)/dbg.c			$(SRCS_DIR)/draw.c	$(SRCS_DIR)/error.c\
			$(SRCS_DIR)/ident.c			$(SRCS_DIR)/init.c\
			$(SRCS_DIR)/key_handler.c	$(SRCS_DIR)/main.c 	$(SRCS_DIR)/map.c\
			$(SRCS_DIR)/parse.c			$(SRCS_DIR)/player.c\
			$(SRCS_DIR)/ray.c	$(SRCS_DIR)/rgb.c\
			$(SRCS_DIR)/vectors.c

#B_DIR	=	$(B_DIR)/
#
#BONUS	=

OBJS	= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

BOBJS	=	$(addprefix) $(OBJ_DIR)/,$(BONUS:.c=.o))

CFLAGS	=	-g -Wall -Wextra -Werror -I $(INCL) -I $(I_MLX) -Imlx

#CC		=	clang

#MLX		=	-lmlx -L./mlx/ -framework OpenGL -framework AppKit
UNAME = $(shell uname)

ifeq ($(UNAME),Darwin)

I_MLX = mlx

LFLAGS = -framework OpenGL -framework AppKit

CC = gcc

else

CC = clang

I_MLX = minilibx_linux

LFLAGS = -lXext -lX11 -lm

endif

MLX_NAME= $(I_MLX)/libmlx.a

RM		=	rm -f

HEADER	=	$(INCL)/cub3D.h

.PHONY	:	all bonus clean fclean re

$(OBJ_DIR)/%.o:%.c $(HEADER)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(SRCS_DIR)
	$(CC) -c $(CFLAGS) -o $@ $<

all		:	$(NAME)

bonus	:	$(BOBJS)
				$(MAKE) -C $(dir $(LIB))
				$(CC) $(CFLAGS) $(BOBJS) $(LIB) $(LFLAGS) -o $(NAME)

$(NAME)	:	$(OBJS) $(LIB) $(MLX_NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) ./libft/libft.a $(MLX_NAME) $(LFLAGS) -o $(NAME)
	#./cub3D /Users/senglish/projects/cub3D/maps/map1.cub

$(LIB)	:
	$(MAKE) -C ./libft

$(MLX_NAME):
	make -C $(I_MLX)
#$(LIBMLX):
#	$(MAKE) -C ./mlx

%.o : %.c $(HEADER) $(BHEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	$(MAKE) clean -C ./libft/
#	$(MAKE) clean -C ./mlx/
	$(RM) -rf $(OBJ_DIR)

fclean	:	clean
	$(MAKE) fclean -C ./libft
#	$(MAKE) fclean -C ./mlx
	$(RM) $(NAME)

re		: fclean all
