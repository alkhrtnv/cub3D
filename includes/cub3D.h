/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:21:40 by senglish          #+#    #+#             */
/*   Updated: 2022/02/03 20:36:55 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "/usr/local/include/mlx.h"
//# include "../mlx/mlx.h"
# include "keys_macos.h"
//# include "keys.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>

# define CLRSCR	"\e[1;1H\e[2J"

# define SCREEN_W	1024
# define SCREEN_H	768

# define ABS(X) (((X) < 0) ? (-(X)) : (X))
# define MAX(A , B) ((A > B) ? A : B)

# define PI		3.1415926
# define VA		PI / 3

# define TRUE	1
# define FALSE	0

# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define YELLOW	0x00FFFF00
# define WHITE	0x00FFFFFF
# define BLACK	0x00000000
# define GRAY	0x00c9c0bb

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_EXIT			17

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_img
{
	void	*img;
	char 	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		screen_w;
	int		screen_h;
}				t_img;

//typedef struct s_path
//{
//	t_img	*path[4];
////	void	*img;
////	int		img_width;
////	int		img_height;
//}				t_path;

typedef struct s_ident
{
    char    *orient[6];
	int     f_rgb[3];
    int     c_rgb[3];
//	t_path	path[4];
}	t_ident;

typedef struct s_player
{
    char    *pos;
	short   north;
	short   south;
	short   east;
	short   west;
	double	posx;
	double	posy;
	double	dx;
	double	dy;
	double	da;
	double	step;
	double 	maxa;
	double	mina;
	double	ang[90];
	double 	angx[90];
	double	angy[90];
	double 	disx[90];
	double 	disy[90];
}				t_player;

typedef struct s_map
{
	char	**size;
	short	width;
	short	height;
	short	scale;
}				t_map;

typedef struct s_ray
{
	int r;
	int mx;
	int my;
	int mp;
	int dof;
	double rx;
	double ry;
	double ra;
	double xo;
	double yo;
}	t_ray;

typedef struct s_game
{
	t_img		image;
	t_vars		vars;
	t_map       map;
	t_ident     ident;
    t_player    player;
	t_ray		ray;
	t_img		path[4];
	char        **parse;
}				t_game;

typedef struct s_rend
{
	int		hit;
	double	dist_to_wall;
	double	ray_a;
	double	ray_a_h;
	double	dif_a;
	double	y_dir;
	double	x_dir;
	double	x_dir_del;
	double	y_dir_del;
	double	size_wall;
	double	ceil;
	double	floor;
}	t_rend;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

////	dbg.c	//
//void	draw_debug_map(t_game *game);

//	draw.c	//
void	my_mlx_pixel_put(t_img *image, int x, int y, int color);
void	my_clear_window(t_game *game);
void	draw_quad(t_game *game, int x, int y, int x0, int y0, int color);
void	draw_minimap(t_game *game);
void 	draw_scaled_point(t_game *game, double x, double y, int color);
void	draw_miniplayer(t_game *game);
int 	check_values(int x, int y, int x1, int y1);
void    draw_line(t_game *game, double x, double y, double x1, double y1, int
color);


//	error.c	//
void    error_identifier(int num);
void	error(int num);
void	printf_error(char *str1, const char *str2, int *fd, int	count);

//  init.c  //
void 	init_param(t_game *game);
void 	init_ident(t_ident  *ident);
void 	init_map(t_game *game);
void 	init_player(t_game *game);
void 	init_image(t_img *image, t_vars *vars);

//	ident.c	//
void	path_ident(char *orient[6]);
void    to_compare(const char *str1, const char *str2, int errnum);
void    compare_ident(char *orient[6]);
void 	fill_ident(char **turn, const char *orient, const char *str, int no);
void    check_ident(t_game *game, short height, short width);

//	key_handler.c	//
unsigned int f_c(int rgb[3]);
void	up_down(t_game *game, double cos, double sin);
void	left_right(t_game *game, double turn);
int		key_pressed(int key, t_game *game);
void	make_3d(t_game *game);

//	main.c	//
int		exit_func();
int		if_invalid(const char *str, const char *format);
void	to_draw(t_game *game);
int		main(int argc, char **argv);

//  map.c   //
void    check_walls(t_game *game, short height, short width);
void    check_player(t_game *game, short height, short width);
void    check_map(t_game *game);
void    fill_map(t_game *game, short num);
void    parse_map(t_game *game, short num);

//	parse.c	//
short 	parse_ident(t_game *game);
void	read_line(t_game *game, int fd);
void	parse(t_game *game, int fd);

//	player.c	//
void	move_player(t_game *game, int x, int y);
void	show_map(t_game *game);

//	rendering.c	//
double	check_rad(double angle);

//	rgb.c	//
char	*rgb_digit(char *str);
char 	*rgb_sep(char *str, char sep, int count);
void 	check_rgb(t_ident *ident);
void    rgb_ident(t_ident *ident);

//	vectors.c	//
t_vec	add_vec(t_vec a, t_vec b);
double	vec_length(t_vec vec);
t_vec	normilize_vec(t_vec vec);
t_vec	multipleByScalar(t_vec vec, double value);
double	round_down(double x);
double	round_up(double x);
void	find_min_vec(t_vec a, t_vec b, t_vec *res);

#endif
