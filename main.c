/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:32:06 by learodri          #+#    #+#             */
/*   Updated: 2022/11/14 20:57:48 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers/so_long.h"

int key(int keycode, void *pointer)
{
    //tatic int  y = 0; //coordenadas
    //static int  x = 0; //coordenadas
    isso *novo; //struct pointer 

    novo = pointer;
    printf("%d \n", keycode); // for debug
    //x += (((keycode == 100) - (keycode == 97)) * 64);
    //y += (((keycode == 115) - (keycode == 119)) * 64);
    if (keycode == 115){ //down
        novo->cord_y += 64; 
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image, novo->cord_x , novo->cord_y);
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image2, novo->cord_x , novo->cord_y - 64);
        }
    if (keycode == 119){ // upp
        novo->cord_y -= 64;
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image, novo->cord_x  , novo->cord_y);
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image2, novo->cord_x  , novo->cord_y + 64);
        }
    if (keycode == 97){ // left
        novo->cord_x -= 64;
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image, novo->cord_x  , novo->cord_y);
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image2, novo->cord_x  + 64, novo->cord_y);
        }
    if (keycode == 100){ //right
        novo->cord_x += 64;
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image, novo->cord_x  , novo->cord_y);
        mlx_put_image_to_window(novo->mlx, novo->window, novo->image2, novo->cord_x  - 64, novo->cord_y);
        }
    if (keycode == 65307)
        exit(EXIT_FAILURE);

    
    return (1);
}

int main(int argc, char *argv[])
{
    //isso    all;
    static isso all;
    int fd;
    (void)argc;
    int tamanho;
    char *map_srt_cpy;

    

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        boom("map.bar blowed up");

    
    map_srt_cpy = malloc((999) * sizeof(char)); // SO FUNCIONA SE MALOCAR
    map_srt_cpy = ber_to_str(fd); // recebe mapa.ber 
    printf("%s \n", map_srt_cpy);


    tamanho = ft_strlen(map_srt_cpy);
    printf("%d \n \n", tamanho);

    all.map_str = malloc((tamanho) * sizeof(char)); // tamanho certinho para struct
    all.map_str = map_srt_cpy;
    printf("%s \n", all.map_str);
    


    all.line = linecount(all.map_str);
    all.colun = coluncount(all.map_str);
    printf("%d \n", all.line);
    printf("%d \n\n\n", all.colun);

    

    //all.map = alocamtx(all.line, all.colun);
    
    /*all.map = (char **)malloc(all.line * sizeof(char*));
    while (i < all.colun)
	{
		all.map[i] = (char *)malloc(all.colun * sizeof(char));
		i++;
	}*/

    all.map = mtxalloc(all.line, all.colun, all.map_str);

    //para verificar se a str esta na matrix 
    for (int i = 0; i < all.line ; i++){
        for(int k = 0; k < all.colun; k++){
            printf("%c ", all.map[i][k]);
        }
        printf("\n");
    }
    
    printf("\n\n\n\n\n");
  

   //-------------------------check maps

    side_check(&all);
    side_check2(&all);
    map_char_check(&all);
    rect_check(&all);
    
    
 
 
    if(map_srt_cpy)
        free(map_srt_cpy); // libera o malloc 999 // dps de dar free a map_str fica null

  

    
    
    all.img_dimen = 64;
    all.mlx = mlx_init(); //to use all the others init conection with graphical sis
    all.window = mlx_new_window(all.mlx, all.colun*64, all.line*64, "so_fuckin_long");
    all.image = mlx_xpm_file_to_image(all.mlx,"brabo.xpm", &all.img_dimen, &all.img_dimen);
    all.image2 = mlx_xpm_file_to_image(all.mlx, "floor.xpm", &all.img_dimen, &all.img_dimen);
    all.image3 = mlx_xpm_file_to_image(all.mlx, "calcinha.xpm", &all.img_dimen, &all.img_dimen);
    all.image4 = mlx_xpm_file_to_image(all.mlx, "wall.xpm", &all.img_dimen, &all.img_dimen);
    all.image5 = mlx_xpm_file_to_image(all.mlx, "girl.xpm", &all.img_dimen, &all.img_dimen);



 
    /*renderizar mapa*/  
    //funcionou com 27 POR 8 -- a partir de oito funciona
    map_render(&all);
   

   


    mlx_hook(all.window,02,(1L<<0), key, &all);

    
    mlx_loop(all.mlx); // keep window opened

    return 0;

}

