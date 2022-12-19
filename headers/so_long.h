/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:22:09 by learodri          #+#    #+#             */
/*   Updated: 2022/12/19 20:58:31 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>

typedef struct tantofaz{
	void	*mlx;
	void	*window;
	void	*image;
	void	*image2;
	void	*image3;
	void	*image4;
	void	*image5;
	int		cord_x;
	int		cord_y;
	char	**map;
	char	**map_cpy;
	int		tempx;
	int		tempy;
	int		exitx;
	int		exity;
	int		line;
	int		colun;
	int		colect;
	int		steps;
}t_isso;

void	boom(char *str, t_isso *p);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	**ber_to_mtx(char **map, int fd, int counter);
void	map_render(t_isso *p);
void	rect_check(t_isso *p);
void	map_char_check(t_isso *p, int e, int c, int pl);
void	side_check(t_isso *p);
void	side_check2(t_isso *p);
void	move_check_right(t_isso *pt);
void	move_check_left(t_isso *pt);
void	move_check_up(t_isso *pt);
void	move_check_down(t_isso *pt);
void	right(t_isso *pt, int i, int k, char c);
void	left(t_isso *pt, int i, int k, char c);
void	up(t_isso *pt, int i, int k, char c);
void	down(t_isso *pt, int i, int k, char c);
void	line_colun(t_isso *p);
void	ber_check(char *str, t_isso *p);
void	img_load(t_isso *p);
int		clear_maps(t_isso *p);
void	path_checker(t_isso *pt, int j, int i);
void	ft_putnbr(int nb);
void	right_0(t_isso *pt, int i, int k);
void	left_0(t_isso *pt, int i, int k);
void	up_0(t_isso *pt, int i, int k);
void	down_0(t_isso *pt, int i, int k);
void	each_char(t_isso *pt);

#endif