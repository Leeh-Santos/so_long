/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:32:06 by learodri          #+#    #+#             */
/*   Updated: 2022/10/20 21:15:05 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers/so_long.h"

typedef struct fodase{
    void *mlx;
    void *window;
    void *image;
    void *image2;
    void *image3;
    int img_dimen;  
    void **map; //map matrix
    char *map_str;
}isso;


int key(int keycode, void *pointer){
    static int  y = 400; //coordenadas
    static int  x = 400; //coordenadas
    isso *novo; //struct pointer 

    novo = pointer;
    printf("%d \n", keycode);
    //x += (((keycode == 100) - (keycode == 97)) * 30);
    //y += (((keycode == 115) - (keycode == 119)) * 30);
    if (keycode == 115){ //down
        y += 30; 
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image, x , y);
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image2, x , y - 30);
        }
    if (keycode == 119){ // upp
        y -= 30;
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image, x , y);
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image2, x , y + 30);
        }
    if (keycode == 97){ // left
        x -= 30;
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image, x , y);
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image2, x + 30, y);
        }
    if (keycode == 100){ //right
        x += 30;
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image, x , y);
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image2, x - 30, y);
        }
    if (keycode == 65307)
        exit(EXIT_FAILURE);

    
    return (1);
}

int main(int argc, char *argv[])
{
    isso    all;
    int fd;
    (void)argc;
    static char *str;

    int y_axis = 400; // 30px +/- relative move
    int x_axis = 400;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        boom("map.bar blowed up");

    all.map_str = ber_to_str(fd, str);

    printf("%s", all.map_str);
    
    all.img_dimen = 30;
    all.mlx = mlx_init(); //to use all the others init conection with graphical sis
    all.window = mlx_new_window(all.mlx, 1120, 820, "sdo_fuckin_long");
    all.image = mlx_xpm_file_to_image(all.mlx,"jony.xpm", &all.img_dimen, &all.img_dimen);
    all.image2 = mlx_xpm_file_to_image(all.mlx, "black.xpm", &all.img_dimen, &all.img_dimen);
    all.image3 = mlx_xpm_file_to_image(all.mlx, "index.xpm", &all.img_dimen, &all.img_dimen);

    mlx_put_image_to_window(all.mlx, all.window, all.image, 400 , 400); 
    
    for ( int i = 0 ; i <= 30; i++){
        mlx_put_image_to_window(all.mlx, all.window, all.image3, x_axis + 30*i, y_axis); 
        mlx_put_image_to_window(all.mlx, all.window, all.image3, x_axis + 30*i, y_axis + 30*i); 
        mlx_put_image_to_window(all.mlx, all.window, all.image3, x_axis, y_axis + 30*i);
        mlx_put_image_to_window(all.mlx, all.window, all.image3, x_axis - 30*i, y_axis); 
        mlx_put_image_to_window(all.mlx, all.window, all.image3, x_axis - 30*i, y_axis - 30*i); 
        mlx_put_image_to_window(all.mlx, all.window, all.image3, x_axis, y_axis - 30*i);
        
    };
    

    mlx_hook(all.window,02,(1L<<0), key, &all);

    
    mlx_loop(all.mlx); // keep window opened

    return 0;

}

