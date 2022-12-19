/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:32:10 by learodri          #+#    #+#             */
/*   Updated: 2022/12/19 19:51:56 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	right(t_isso *pt, int i, int k, char c)
{
	if (c == '0')
	{
		pt->cord_x += 64;
		right_0(pt, i, k);
		pt->steps++;
		ft_putnbr(pt->steps);
		write(1, "\n", 1);
	}
	else if (c == 'C')
	{
		pt->cord_x += 64;
		right_0(pt, i, k);
		pt->colect--;
		pt->steps++;
		ft_putnbr(pt->steps);
		write(1, "\n", 1);
	}
	else if (c == 'E')
	{
		if (pt->colect == 0)
			clear_maps(pt);
	}
}

void	left(t_isso *pt, int i, int k, char c)
{
	if (c == '0')
	{
		pt->cord_x -= 64;
		left_0(pt, i, k);
		pt->steps++;
		ft_putnbr(pt->steps);
		write(1, "\n", 1);
	}
	else if (c == 'C')
	{
		pt->cord_x -= 64;
		left_0(pt, i, k);
		pt->colect--;
		pt->steps++;
		ft_putnbr(pt->steps);
		write(1, "\n", 1);
	}
	else if (c == 'E')
	{
		if (pt->colect == 0)
			clear_maps(pt);
	}
}

void	up(t_isso *pt, int i, int k, char c)
{
	if (c == '0')
	{
		pt->cord_y -= 64;
		up_0(pt, i, k);
		pt->steps++;
		ft_putnbr(pt->steps);
		write(1, "\n", 1);
	}
	else if (c == 'C')
	{
		pt->cord_y -= 64;
		up_0(pt, i, k);
		pt->colect--;
		pt->steps++;
		ft_putnbr(pt->steps);
		write(1, "\n", 1);
	}
	else if (c == 'E')
	{
		if (pt->colect == 0)
			clear_maps(pt);
	}
}

void	down(t_isso *pt, int i, int k, char c)
{
	if (c == '0')
	{
		pt->cord_y += 64;
		down_0(pt, i, k);
		pt->steps++;
		ft_putnbr(pt->steps);
		write(1, "\n", 1);
	}
	else if (c == 'C')
	{
		pt->cord_y += 64;
		down_0(pt, i, k);
		pt->colect--;
		pt->steps++;
		ft_putnbr(pt->steps);
		write(1, "\n", 1);
	}
	else if (c == 'E')
	{
		if (pt->colect == 0)
			clear_maps(pt);
	}
}
