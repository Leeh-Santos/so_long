/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:06:19 by learodri          #+#    #+#             */
/*   Updated: 2022/12/19 21:18:42 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	rect_check(t_isso *p)
{
	int	i;

	i = 0;
	while (i < p->line)
	{
		if (p->map[i][p->colun] != '\n')
		{
			boom("nao retangular", p);
		}
		i++;
	}
}

void	map_char_check(t_isso *p, int e, int c, int pl)
{
	int	i;
	int	k;

	i = 0;
	while (p->map[i])
	{
		k = 0;
		while (p->map[i][k])
		{
			if (p->map[i][k] == 'E')
				e++;
			if (p->map[i][k] == 'P')
				pl++;
			if (p->map[i][k] == 'C')
				c++;
			k++;
		}
		i++;
	}
	p->colect = c;
	if (e != 1 || pl != 1 || c < 1)
		boom("checa seu mapa ai fera, algum char ai ta zuado", p);
}

void	side_check(t_isso *p)
{
	int	i;

	i = 0;
	while (i < p->colun)
	{
		if (p->map[0][i] != '1')
			boom("upper part of map not surrounded by 1", p);
		i++;
	}
	i = 0;
	while (i < p->colun)
	{
		if (p->map[p->line - 1][i] != '1')
			boom("lower part of map not surrounded by 1", p);
		i++;
	}
}

void	side_check2(t_isso *p)
{
	int	i;

	i = 0;
	while (i < p->line)
	{
		if (p->map[i][0] != '1')
			boom("deu ruim de ladinho esquerdo", p);
		i++;
	}
	i = 0;
	while (i < p->line)
	{
		if (p->map[i][p->colun - 1] != '1')
			boom("deu ruim de ladinho direito", p);
		i++;
	}
}

void	each_char(t_isso *pt)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (pt->map[i])
	{
		k = 0;
		while (pt->map[i][k])
		{
			if (pt->map[i][k] != 'P' && pt->map[i][k] != 'E' &&
			pt->map[i][k] != '0' && pt->map[i][k] != '1' &&
			pt->map[i][k] != 'C' && pt->map[i][k] != '\n')
			{
				boom("tem um char esquisito ai", pt);
			}
			k++;
		}
		i++;
	}
}
