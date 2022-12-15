/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:35:06 by learodri          #+#    #+#             */
/*   Updated: 2022/12/15 19:48:55 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	boom(char *str, isso *p)
{
	write(1, "error/n", 7);
    perror(str);
    clear_maps(p);
}

void	endgame(isso *p) // imagem window, mlx 
{
	mlx_destroy_image(p->mlx, p->image);
	mlx_destroy_image(p->mlx, p->image2);
	mlx_destroy_image(p->mlx, p->image3);
	mlx_destroy_image(p->mlx, p->image4);
	mlx_destroy_image(p->mlx, p->image5);
	//free(p->image);
	//free(p->image2);
	//free(p->image3);
	//free(p->image4);
	//free(p->image5);
	
	if (p->window)
		mlx_destroy_window(p->mlx, p->window);
	if (p->mlx)
	{
		mlx_destroy_display(p->mlx);
		free(p->mlx);
	}
	exit(EXIT_SUCCESS);
}

int	clear_maps(isso *p) // limpa as matrises
{
	int	i;

	i = 0;
	if (p->map)
	{
		while (p->map[i])
		{
			free(p->map[i++]);
		}
		free(p->map);
	}
	i = 0;
	if (p->map_cpy)
	{
		while (p->map_cpy[i])
			free(p->map_cpy[i++]);
		free(p->map_cpy);
	}
	endgame(p);
	return (1);
}

// valgrind --leak-check=yes