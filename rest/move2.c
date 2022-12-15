/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:32:10 by learodri          #+#    #+#             */
/*   Updated: 2022/12/15 18:51:04 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
        printf("%d \n", pt->steps);
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
        printf("%d \n", pt->steps);
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
        printf("%d \n", pt->steps);
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
        printf("%d \n", pt->steps);
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
        printf("%d \n", pt->steps);
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
        printf("%d \n", pt->steps);
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
        printf("%d \n", pt->steps);
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
        printf("%d \n", pt->steps);
    }else if(c == 'E')
    {
        if(pt->colect == 0)
            clear_maps(pt);
        
    }
}