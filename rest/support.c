/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:17:27 by learodri          #+#    #+#             */
/*   Updated: 2022/12/19 18:57:34 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

char	**ber_to_mtx(char **map, int fd, int counter)
{
	char	*str;

	str = get_next_line(fd);
	if (str)
		map = ber_to_mtx(map, fd, counter + 1);
	if (!map && counter != 0)
		map = malloc((counter + 1) * (sizeof(char *)));
	if (!map)
		return (NULL);
	map[counter] = str;
	return (map);
}

void	line_colun(t_isso *p)
{
	int	i;

	i = 0;
	while (p->map[i])
		i++;
	p->line = i;
	i = 0;
	while (p->map[0][i])
		i++;
	i--;
	p->colun = i;
}

void	img_load(t_isso *p)
{
	int	img_dimen;

	img_dimen = 64;
	p->image = mlx_xpm_file_to_image
		(p->mlx, "brabo.xpm", &img_dimen, &img_dimen);
	p->image2 = mlx_xpm_file_to_image
		(p->mlx, "floor.xpm", &img_dimen, &img_dimen);
	p->image3 = mlx_xpm_file_to_image
		(p->mlx, "calcinha.xpm", &img_dimen, &img_dimen);
	p->image4 = mlx_xpm_file_to_image
		(p->mlx, "wall.xpm", &img_dimen, &img_dimen);
	p->image5 = mlx_xpm_file_to_image
		(p->mlx, "girl.xpm", &img_dimen, &img_dimen);
}
