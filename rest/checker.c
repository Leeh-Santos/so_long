/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:06:19 by learodri          #+#    #+#             */
/*   Updated: 2022/12/14 21:35:33 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	rect_check(isso *p)
{
	int	i;

	i = 0;
	while ( i < p->line)
	{
		if(p->map[i][p->colun] != '\n')
		{
			boom("nao retangular", p);
		}
		i++;
	}
}

void	map_char_check(isso *p, int e, int c, int pl)
{
	int	i;
	int k;
	
	i = 0;
	while (p->map[i])
	{
		k = 0;
		while(p->map[i][k])
		{
			if(p->map[i][k] == 'E')
				e++;
			if(p->map[i][k] == 'P')
				pl++;
			if(p->map[i][k] == 'C')
				c++;
			k++;
		}
		i++;
	}
	p->colect = c;
	if (e != 1 || pl != 1 || c < 1)
		boom("checa seu mapa ai fera, algum char ai ta zuado", p);
}

void	side_check(isso *p)
{
	int	i;
	
	i = 0;
	while(i < p->colun)
	{
		if(p->map[0][i] != '1')
			boom("upper part of map not surrounded by 1", p);
		i++;
	}
	i = 0;
	while(i < p->colun)
	{
		if(p->map[p->line - 1][i] != '1')
			boom("lower part of map not surrounded by 1", p);
		i++;
	}
}

void	side_check2(isso *p)
{
	int	i;

	i = 0;
	while (i < p->line)
	{
		if(p->map[i][0] != '1')
			boom("fudeu de ladinho esquerdo", p);
		i++;
	}
	i = 0;
	while(i < p->line)
	{
		if(p->map[i][p->colun - 1] != '1')
			boom("fudeu de ladinho direito", p);
		i++;	
	}
}