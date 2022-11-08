/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:17:03 by learodri          #+#    #+#             */
/*   Updated: 2022/11/08 20:59:22 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char 	**mtxalloc(int line, int colun, char *str)
{
	int	i;
	int	k;
	char **mtx;
	int i_str;
	
	i = 0;
	k = 0;
	i_str = 0;
	mtx = malloc(line * sizeof(char*));
    while (i < colun)
	{
		mtx[i] = malloc(colun * sizeof(char));
		i++;
	}
    i = 0;
	while (i <= line)
	{	
		k = 0;
		if (str[i_str] == '\n') // se for \n avanca
			i_str++;
		while (str[i_str] != '\n')
		{
			mtx[i][k] = str[i_str];
			k++;
			i_str++;
		}
		i++;
	}
	return (mtx);
}

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
	while(i < info->line)
	{
		k = 0;
		while(k < info->colun)
		{
			if(info->map[i][k] == '1')
				mlx_put_image_to_window(info->mlx, info->window, info->image4, k*64, i*64);
			else if(info->map[i][k] == '0')
				mlx_put_image_to_window(info->mlx, info->window, info->image2, k*64, i*64);
			else if(info->map[i][k] == 'P')
			{
				mlx_put_image_to_window(info->mlx, info->window, info->image, k*64, i*64);
				info->cord_x = k*64;
				info->cord_y = i*64;
			}
			else if(info->map[i][k] == 'E')
				mlx_put_image_to_window(info->mlx, info->window, info->image5, k*64, i*64);
			else if(info->map[i][k] == 'C')
				mlx_put_image_to_window(info->mlx, info->window, info->image3, k*64, i*64);
			else
				boom("Map Problem, please add a compatible.ber");
			k++;
		}
		i++;
	}
}