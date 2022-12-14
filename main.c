/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:32:06 by learodri          #+#    #+#             */
/*   Updated: 2022/12/14 22:01:56 by learodri         ###   ########.fr       */
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
     // for debug manda printar o keycode
    //x += (((keycode == 100) - (keycode == 97)) * 64);
    //y += (((keycode == 115) - (keycode == 119)) * 64);
    if (keycode == 115){ //down
		move_check_down(novo);
        }
    if (keycode == 119){ // upp
		move_check_up(novo);
        }
    if (keycode == 97){ // left
		move_check_left(novo);
        }
    if (keycode == 100){ //right
		move_check_right(novo);
        }
    if (keycode == 65307)
        exit(EXIT_FAILURE);

    
    return (1);
}

int main(int argc, char *argv[])
{
    static isso all;
    int fd;
    (void)argc;
    int i;
    int j;

    if (argc != 2)
		boom("Wrong number of arguments budy", &all);

    
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
		boom("problem to open .ber bro", &all);
	all.map = ber_to_mtx(NULL, fd, 0);
    close(fd);
    ber_check(argv[1], &all);

    
	while (all.map[j])
	{
		i = 0;
		
		while (all.map[j][i])
		{
			printf("%c", all.map[j][i]);
			i++;
		}
		
		j++;
	}
    
	line_colun(&all);

	printf("-----------------------------------\n");

	printf("numero de linhas %d, numero de colunas %d \n", all.line, all.colun);

	printf("-----------------------------------\n");
  
	
    

   //-------------------------check maps

	
    side_check(&all);
    side_check2(&all);
	map_char_check(&all, 0, 0, 0);
    rect_check(&all);
    path_checker(&all, 0, 0);
    
    


  

    
    
    
    all.mlx = mlx_init(); //to use all the others init conection with graphical sis
    all.window = mlx_new_window(all.mlx, all.colun*64, all.line*64, "so_fuckin_long");
	img_load(&all);  
    
    map_render(&all);
   

   

    mlx_hook(all.window,02,(1L<<0), key, &all);
    mlx_hook(all.window, 17, (1L << 2), clear_maps, &all);

    
    mlx_loop(all.mlx); // keep window opened

    return 0;

}

