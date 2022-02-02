/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:14:36 by senglish          #+#    #+#             */
/*   Updated: 2022/01/26 15:42:05 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

int	if_invalid(int argc, char **argv)
{
	size_t	count;
	int		fd;

	if (argc != 2)
		error(2);
	count = ft_strlen(argv[1]);
	if (open(argv[1], O_DIRECTORY) == 1)
		error(3);
	if ((count <= 4 || ft_strncmp(&argv[1][count - 4], ".cub", 4)))
		error(3);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(4);
	return (fd);
}

void	to_draw(t_game *game)
{
	show_map(game);
	my_clear_window(game);
	draw_minimap(game);
	draw_miniplayer(game);
	printf(CLRSCR);
}

int main(int argc, char **argv)
{
	t_game	game;

	init_param(&game);
	parse(&game, if_invalid(argc, argv));
	game.player.dx = cos(game.player.da);
	game.player.dy = sin(game.player.da);
	game.player.step = 0.5f;
	init_image(&game.map, &game.image, &game.vars);
	to_draw(&game);
	mlx_key_hook(game.vars.win, key_pressed, &game); //linux
//	mlx_hook(game.vars.win, X_EVENT_KEY_PRESS, 0, &key_pressed, &game); //mac
	mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.image.img, 0,
							0);
	mlx_loop(game.vars.mlx);
	return 0;
}
