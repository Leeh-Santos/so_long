/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:17:03 by learodri          #+#    #+#             */
/*   Updated: 2022/12/19 18:52:26 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	render_support(int k, int i, t_isso *p)
{
	if (p->map[i][k] == '1')
		mlx_put_image_to_window(p->mlx, p->window, p->image4, k * 64, i * 64);
	else if (p->map[i][k] == '0')
		mlx_put_image_to_window(p->mlx, p->window, p->image2, k * 64, i * 64);
	else if (p->map[i][k] == 'P')
	{
		mlx_put_image_to_window(p->mlx, p->window, p->image, k * 64, i * 64);
		p->cord_x = k * 64;
		p->cord_y = i * 64;
	}
	else if (p->map[i][k] == 'E')
		mlx_put_image_to_window(p->mlx, p->window, p->image5, k * 64, i * 64);
	else if (p->map[i][k] == 'C')
		mlx_put_image_to_window(p->mlx, p->window, p->image3, k * 64, i * 64);
}

void	map_render(t_isso *p)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (p->map[i])
	{
		k = 0;
		while (p->map[i][k])
		{
			render_support(k, i, p);
			k++;
		}
		i++;
	}
}
