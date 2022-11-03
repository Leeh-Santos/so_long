/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:22:09 by learodri          #+#    #+#             */
/*   Updated: 2022/11/03 22:00:30 by learodri         ###   ########.fr       */
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
    int img_dimen;  
    char **map; //map matrix //ANTES ERA VOID **MAP
    char *map_str;
    int line;
    int colun;
}isso;


void    boom(char *str);
char	*ber_to_str(int fd);
char	*get_next_line(int fd);
int	linecount(char *str);
int	coluncount(char *str);
size_t	ft_strlen(char *str);
char    **mtxalloc(int line, int colun, char *str);
void	map_render(isso *info);

#endif