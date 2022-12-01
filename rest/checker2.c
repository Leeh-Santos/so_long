/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:36:22 by learodri          #+#    #+#             */
/*   Updated: 2022/12/01 18:11:59 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../headers/so_long.h"

void    vaicarai(char **map, int x, int y, isso *pt)
{

    if (map[x + 1][y] && (map[x + 1][y] == 'C' || map[x + 1][y] == '0'))
	{
		map[x + 1][y] = 'P';
		vaicarai(map, x + 1, y, pt);
	}
	if (map[x - 1][y] && (map[x - 1][y] == 'C' || map[x - 1][y] == '0'))
	{
		map[x - 1][y] = 'P';
		vaicarai(map, x - 1, y, pt);
	}
	if (map[x][y + 1] && (map[x][y + 1] == 'C' || map[x][y + 1] == '0'))
	{
		map[x][y + 1] = 'P';
		vaicarai(map, x, y + 1, pt);
	}
	if (map[x][y - 1] && (map[x][y - 1] == 'C' || map[x][y - 1] == '0'))
	{
		map[x][y - 1] = 'P';
		vaicarai(map, x, y - 1, pt);
	}
}

void	path_checker(isso *pt)
{
  	vaicarai(pt->map_cpy, pt->cord_y / 64, pt->cord_x / 64, pt);

     for (int i = 0; i < pt->line ; i++){
        for(int k = 0; k < pt->colun; k++){
            printf("%c ", pt->pt->map_cpy_cpy[i][k]);
        }
        printf("\n");
    }
}*/