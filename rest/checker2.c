/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:36:22 by learodri          #+#    #+#             */
/*   Updated: 2022/12/19 18:33:08 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	vaicarai(char **map, int x, int y)
{
	if (map[x + 1][y] && (map[x + 1][y] == 'C' || map[x + 1][y] == '0'))
	{
		map[x + 1][y] = 'P';
		vaicarai(map, x + 1, y);
	}
	if (map[x - 1][y] && (map[x - 1][y] == 'C' || map[x - 1][y] == '0'))
	{
		map[x - 1][y] = 'P';
		vaicarai(map, x - 1, y);
	}
	if (map[x][y + 1] && (map[x][y + 1] == 'C' || map[x][y + 1] == '0'))
	{
		map[x][y + 1] = 'P';
		vaicarai(map, x, y + 1);
	}
	if (map[x][y - 1] && (map[x][y - 1] == 'C' || map[x][y - 1] == '0'))
	{
		map[x][y - 1] = 'P';
		vaicarai(map, x, y - 1);
	}
}

void	findcord(t_isso *p)
{
	int	i;
	int	k;

	i = 0;
	while (p->map[i])
	{
		k = 0;
		while (p->map[i][k])
		{
			if (p->map[i][k] == 'P')
			{
				p->tempx = k;
				p->tempy = i;
			}
			if (p->map[i][k] == 'E')
			{
				p->exitx = k;
				p->exity = i;
			}
			k++;
		}
		i++;
	}
}

void	finalpathcheck(t_isso *p, int i, int k)
{
	while (p->map_cpy[i])
	{
		k = 0;
		while (p->map_cpy[i][k])
		{
			if (p->map_cpy[i][k] == 'C')
				boom("nao valido cachorro 'c' ", p);
			k++;
		}
		i++;
	}
	if (!(p->map_cpy[p->exity + 1][p->exitx] == 'P' || p->map_cpy[\
	p->exity - 1][p->exitx] == 'P' || p->map_cpy[p->exity][\
	p->exitx + 1] == 'P' || p->map_cpy[p->exity] \
	[p->exitx - 1] == 'P'))
		boom("Princesinha sem saida", p);
}

void	path_checker(t_isso *pt, int j, int i)
{
	pt->map_cpy = malloc((pt->line + 1) * sizeof(char *));
	if (!pt->map_cpy)
		return ;
	while (pt->map[j])
	{
		i = 0;
		pt->map_cpy[j] = malloc((pt->colun + 2) * sizeof(char));
		while (pt->map[j][i])
		{
			pt->map_cpy[j][i] = pt->map[j][i];
			i++;
		}
		pt->map_cpy[j][i] = 0;
		j++;
	}
	pt->map_cpy[j] = 0;
	findcord(pt);
	vaicarai(pt->map_cpy, pt->tempy, pt->tempx);
	finalpathcheck(pt, 0, 0);
}

void	ber_check(char *str, t_isso *p)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || \
	str[i - 3] != 'b' || str[i - 4] != '.')
		boom("not .ber dude", p);
}
