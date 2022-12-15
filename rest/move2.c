/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:32:10 by learodri          #+#    #+#             */
/*   Updated: 2022/12/15 21:57:17 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void	ft_putnbr(int nb) {
	if (nb < 0) {
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10) ft_putchar(nb + 48);
}

void	right(isso *pt, int i, int k, char c)
{
    if(c == '0')
    {
        pt->cord_x += 64;
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image, pt->cord_x  , pt->cord_y);
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image2, pt->cord_x  - 64, pt->cord_y); 
        pt->map[i][k + 1] = 'P';
        pt->map[i][k] = '0';
        pt->steps++;
		ft_putnbr(pt->steps);
		write(1, "\n", 1);
        /*for (int z = 0; z < pt->line ; z++){
            for(int y = 0; y < pt->colun; y++){
                 printf("%c ", pt->map[z][y]);
            }
            printf("\n");
            
          }*/
    }else if(c == 'C')
    {
        pt->cord_x += 64;
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image, pt->cord_x  , pt->cord_y);
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image2, pt->cord_x  - 64, pt->cord_y); 
        pt->map[i][k + 1] = 'P';
        pt->map[i][k] = '0';
        pt->colect--;
        pt->steps++;
        ft_putnbr(pt->steps);
		write(1, "\n", 1);
    }else if(c == 'E')
    {
        if(pt->colect == 0)
            clear_maps(pt);
        
    }
    
}

void	left(isso *pt, int i, int k, char c)
{
    if(c == '0')
    {
        pt->cord_x -= 64;
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image, pt->cord_x  , pt->cord_y);
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image2, pt->cord_x  + 64, pt->cord_y);
        pt->map[i][k - 1] = 'P';
        pt->map[i][k] = '0';
        pt->steps++;
		ft_putnbr(pt->steps);
		write(1, "\n", 1);
                        /*for (int z = 0; z < pt->line ; z++){
                            for(int y = 0; y < pt->colun; y++){
                                printf("%c ", pt->map[z][y]);
                             }
                            printf("\n");
                        }*/
    }else if(c == 'C')
    {
        pt->cord_x -= 64;
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image, pt->cord_x  , pt->cord_y);
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image2, pt->cord_x  + 64, pt->cord_y);
        pt->map[i][k - 1] = 'P';
        pt->map[i][k] = '0';
        pt->colect--;
        pt->steps++;
        ft_putnbr(pt->steps);
		write(1, "\n", 1);
    }else if(c == 'E')
    {
        if(pt->colect == 0)
            clear_maps(pt);
    }
}

void	up(isso *pt, int i, int k, char c)
{
    if(c == '0')
    {
        pt->cord_y -= 64;
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image, pt->cord_x  , pt->cord_y);
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image2, pt->cord_x  , pt->cord_y + 64); 
        pt->map[i][k] = '0';
        pt->map[i - 1][k] = 'P';
        pt->steps++;
		ft_putnbr(pt->steps);
		write(1, "\n", 1);
                        /*for (int z = 0; z < pt->line ; z++){
                            for(int y = 0; y < pt->colun; y++){
                                printf("%c ", pt->map[z][y]);
                             }
                            printf("\n");
                        }*/
    }else if (c == 'C')
    {
        pt->cord_y -= 64;
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image, pt->cord_x  , pt->cord_y);
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image2, pt->cord_x  , pt->cord_y + 64); 
        pt->map[i][k] = '0';
        pt->map[i - 1][k] = 'P';
        pt->colect--;
        pt->steps++;
        ft_putnbr(pt->steps);
		write(1, "\n", 1);
    }else if(c == 'E')
    {
        if(pt->colect == 0)
            clear_maps(pt);
        
    }
    
}

void	down(isso *pt, int i, int k, char c)
{
    if(c == '0')
    {
        pt->cord_y += 64;
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image, pt->cord_x , pt->cord_y);
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image2, pt->cord_x , pt->cord_y - 64);
        pt->map[i][k] = '0';
        pt->map[i + 1][k] = 'P';
        pt->steps++;
        ft_putnbr(pt->steps);
		write(1, "\n", 1);
                        /*for (int z = 0; z < pt->line ; z++){
                            for(int y = 0; y < pt->colun; y++){
                                printf("%c ", pt->map[z][y]);
                             }
                            printf("\n");
                        }*/
    }else if(c == 'C')
    {
        pt->cord_y += 64;
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image, pt->cord_x , pt->cord_y);
        mlx_put_image_to_window(pt->mlx, pt->window, pt->image2, pt->cord_x , pt->cord_y - 64);
        pt->map[i][k] = '0';
        pt->map[i + 1][k] = 'P';
        pt->colect--;
        pt->steps++;
        ft_putnbr(pt->steps);
		write(1, "\n", 1);
    }else if(c == 'E')
    {
        if(pt->colect == 0)
            clear_maps(pt);
        
    }
}