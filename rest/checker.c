/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:06:19 by learodri          #+#    #+#             */
/*   Updated: 2022/11/14 21:43:47 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	rect_check(isso *p)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while ( p->map_str[i] != '\0')
	{
		if(p->map_str[i] != '\n')
		{
			check++;
		}
		if(p->map_str[i] == '\n')
		{
			if (check != p->colun)
				boom("nao retangular viado");
			else
				check = 0;
		}
		i++;
	}
}

void	map_char_check(isso *p)
{
	int	i;
	int	e;
	int	c;
	int	pl;

	i = 0;
	e = 0;
	c = 0;
	pl = 0;	
	while (p->map_str[i] != '\0')
	{
		if(p->map_str[i] == 'E')
			e++;
		if(p->map_str[i] == 'P')
			pl++;
		if(p->map_str[i] == 'C')
			c++;
		i++;
	}
	
	if (e != 1 || pl != 1 || c < 1)
		boom("checa seu mapa ai fera, algum char ai ta zuado");
}

void	side_check(isso *p)
{
	int	i;
	
	i = 0;
	while(i < p->colun)
	{
		if(p->map[0][i] != '1')
			boom("map not surrounded by 1 bitch");
		i++;
	}
	i = 0;
	while(i < p->colun)
	{
		if(p->map[p->line - 1][i] != '1')
			boom("map not surrounded by 1 bitch");
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
			boom("fudeu de ladinho");
		i++;
	}
	i = 0;
	while(i < p->line)
	{
		if(p->map[i][p->colun - 1] != '1')
			boom("fudeu de ladinho");
		i++;
	}
}