/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nasty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:15:20 by learodri          #+#    #+#             */
/*   Updated: 2022/12/19 19:52:50 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	right_0(t_isso *pt, int i, int k)
{
	mlx_put_image_to_window
		(pt->mlx, pt->window, pt->image, pt->cord_x, pt->cord_y);
	mlx_put_image_to_window
		(pt->mlx, pt->window, pt->image2, pt->cord_x - 64, pt->cord_y);
	pt->map[i][k + 1] = 'P';
	pt->map[i][k] = '0';
}

void	left_0(t_isso *pt, int i, int k)
{
	mlx_put_image_to_window
		(pt->mlx, pt->window, pt->image, pt->cord_x, pt->cord_y);
	mlx_put_image_to_window
		(pt->mlx, pt->window, pt->image2, pt->cord_x + 64, pt->cord_y);
	pt->map[i][k - 1] = 'P';
	pt->map[i][k] = '0';
}

void	up_0(t_isso *pt, int i, int k)
{
	mlx_put_image_to_window
		(pt->mlx, pt->window, pt->image, pt->cord_x, pt->cord_y);
	mlx_put_image_to_window
		(pt->mlx, pt->window, pt->image2, pt->cord_x, pt->cord_y + 64);
	pt->map[i][k] = '0';
	pt->map[i - 1][k] = 'P';
}

void	down_0(t_isso *pt, int i, int k)
{
	mlx_put_image_to_window
		(pt->mlx, pt->window, pt->image, pt->cord_x, pt->cord_y);
	mlx_put_image_to_window
		(pt->mlx, pt->window, pt->image2, pt->cord_x, pt->cord_y - 64);
	pt->map[i][k] = '0';
	pt->map[i + 1][k] = 'P';
}
