/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:22:09 by learodri          #+#    #+#             */
/*   Updated: 2022/11/21 19:38:10 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
#include <mlx.h>

typedef struct fodase{
    void *mlx;
    void *window;
    void *image;
    void *image2;
    void *image3;
    void *image4;
    void *image5;
    int cord_x;
    int cord_y;
    int img_dimen;  
    char **map; //map matrix //ANTES ERA VOID **MAP
    char *map_str;
    int line;
    int colun;
    int	colect;
}isso;


void    boom(char *str);
char	*ber_to_str(int fd);
char	*get_next_line(int fd);
int	linecount(char *str);
int	coluncount(char *str);
size_t	ft_strlen(char *str);
char    **mtxalloc(int line, int colun, char *str);
void	map_render(isso *info);
void	rect_check(isso *p);
void	map_char_check(isso *p);
void	side_check(isso *p);
void	side_check2(isso *p);
void    move_check_right(isso *pt);
void    move_check_left(isso *pt);
void    move_check_up(isso *pt);
void    move_check_down(isso *pt);
void	right(isso *pt, int i, int k, char c);
void	left(isso *pt, int i, int k, char c);
void	up(isso *pt, int i, int k, char c);
void	down(isso *pt, int i, int k, char c);
void    valid_path(isso *pt);
/*t_data *data()
{
    static t_data data;

    return (&data)
}*/

/*
map checker 

fill 'C' AND '0' WITH  'P'
se tiver colect deu ruim
dps checar exit:
checar posicoes do lado para ver se tem o 'P'

*/

#endif