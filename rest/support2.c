/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:17:03 by learodri          #+#    #+#             */
/*   Updated: 2022/12/12 21:00:30 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_render(isso *info)
{
	/*for (int i = 0; i < all.line ; i++){
        for(int k = 0; k < all.colun; k++){
            printf("%c ", all.map[i][k]);
        }
	*/
	int i;
	int	k;

	i = 0;
	k = 0;
	while(info->map[i])
	{
		k = 0;
		while(info->map[i][k])
		{
			if(info->map[i][k] == '1')
				mlx_put_image_to_window(info->mlx, info->window, info->image4, k*64, i*64);
			else if(info->map[i][k] == '0')
				mlx_put_image_to_window(info->mlx, info->window, info->image2, k*64, i*64);
			else if(info->map[i][k] == 'P')
			{
				mlx_put_image_to_window(info->mlx, info->window, info->image, k*64, i*64);
				info->cord_x = k * 64;
				info->cord_y = i * 64;
			}
			else if(info->map[i][k] == 'E')
				mlx_put_image_to_window(info->mlx, info->window, info->image5, k*64, i*64);
			else if(info->map[i][k] == 'C')
				mlx_put_image_to_window(info->mlx, info->window, info->image3, k*64, i*64);
			/*else
				boom("Map render Problem, please add a compatible.ber");*/
			k++;
		}
		i++;
	}
}
