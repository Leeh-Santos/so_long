/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:32:06 by learodri          #+#    #+#             */
/*   Updated: 2022/12/19 21:13:33 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers/so_long.h"

int	key(int keycode, void *pointer)
{
	t_isso	*novo;

	novo = pointer;
	if (keycode == 115)
		move_check_down(novo);
	if (keycode == 119)
		move_check_up(novo);
	if (keycode == 97)
		move_check_left(novo);
	if (keycode == 100)
		move_check_right(novo);
	if (keycode == 65307)
		clear_maps(novo);
	return (1);
}

void	tryit(t_isso *p)
{
	side_check(p);
	side_check2(p);
	map_char_check(p, 0, 0, 0);
	rect_check(p);
	each_char(p);
}

int	main(int argc, char *argv[])
{
	int				fd;
	static t_isso	all;

	if (argc != 2)
		boom("Wrong number of arguments budy", &all);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		boom("problem to open .ber bro", &all);
	all.map = ber_to_mtx(NULL, fd, 0);
	if (!all.map || all.map[0][0] != '1')
		boom("nada no mapa parca", &all);
	close(fd);
	ber_check(argv[1], &all);
	line_colun(&all);
	tryit(&all);
	path_checker(&all, 0, 0);
	all.mlx = mlx_init();
	all.window = mlx_new_window
		(all.mlx, all.colun * 64, all.line * 64, "so_long");
	img_load(&all);
	map_render(&all);
	mlx_hook(all.window, 02, (1L << 0), key, &all);
	mlx_hook(all.window, 17, (1L << 2), clear_maps, &all);
	mlx_loop(all.mlx);
	return (0);
}
