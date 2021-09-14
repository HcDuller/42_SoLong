/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:50:47 by hde-camp          #+#    #+#             */
/*   Updated: 2021/09/05 21:54:52 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static	void	check_for_path(int argc)
{
	if (argc != 2)
	{
		if (argc == 1)
			ft_putstr_fd("Error\nNo path was provided.", 1);
		else
			ft_putstr_fd("Error\nToo many arguments provided", 1);
		errno = EINVAL;
		exit(EINVAL);
	}
}

int	main(int argc, char *argv[])
{
	t_lines			map;
	t_game_handler	game;

	check_for_path(argc);
	map = get_parsed_map(argv[1]);
	start_game(&game, &map);
	destroy_map(&map);
	mlx_hook(game.mlx.win, 17, 1L << 2, close_win, &game);
	mlx_key_hook(game.mlx.win, pressed_key, &game);
	mlx_loop_hook(game.mlx.conn, game_tick, &game);
	mlx_put_image_to_window(game.mlx.conn, game.mlx.win, \
							game.mlx.img->addr, 0, 0);
	mlx_loop(game.mlx.conn);
	return (1);
}
