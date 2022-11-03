/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:17:03 by learodri          #+#    #+#             */
/*   Updated: 2022/11/03 22:03:47 by learodri         ###   ########.fr       */
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
	mtx = (char **)malloc(line * sizeof(char*));
    while (i < colun)
	{
		mtx[i] = (char *)malloc(colun * sizeof(char));
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
				mlx_put_image_to_window(info->mlx, info->window,)
			k++;
		}
		i++;
	}
}