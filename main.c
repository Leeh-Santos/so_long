/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:32:06 by learodri          #+#    #+#             */
/*   Updated: 2022/10/17 22:54:02 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct fodase{
    void *mlx;
    void *window;
    void *image;
    int img_dimen;  
    void **map; //map matrix

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
        }
    if (keycode == 119){ // upp
        y -= 30;
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image, x , y);
        }
    if (keycode == 97){ // left
        x -= 30;
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image, x , y);
        }
    if (keycode == 100){ //right
        x += 30;
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image, x , y);
        }
    if (keycode == 65307)
        exit(EXIT_FAILURE);

    
    return (1);
}

int main(void)
{
    isso    all;
    all.img_dimen = 30;
    all.mlx = mlx_init(); //to use all the others init conection with graphical sis
    all.window = mlx_new_window(all.mlx, 810, 540, "so_fuckin_long");
    all.image = mlx_xpm_file_to_image(all.mlx,"index.xpm", &all.img_dimen, &all.img_dimen);
    
    mlx_put_image_to_window(all.mlx, all.window, all.image, 400 , 400); 
    mlx_hook(all.window,02,(1L<<0), key, &all);

    mlx_loop(all.mlx); // keep window opened



}

//abriu 
//colocar e meter no ecra
//eventos a,w,s,d esc para sair keycode 
//LER mapa, matriz,renderizar mapa 