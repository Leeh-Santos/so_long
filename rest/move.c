/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:04:27 by learodri          #+#    #+#             */
/*   Updated: 2022/12/19 18:32:14 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	move_check_right(t_isso *pt)
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
			if (pt->map[i][k] == 'P')
			{
				if (pt->map[i][k + 1] == '0' || pt->map[i][k + 1] == 'C' ||
				pt->map[i][k + 1] == 'E')
				{
					right(pt, i, k, pt->map[i][k + 1]);
					break ;
				}
			}
			k++;
		}
		i++;
	}
}

void	move_check_left(t_isso *pt)
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
			if (pt->map[i][k] == 'P')
			{
				if (pt->map[i][k - 1] == '0' || pt->map[i][k - 1] == 'C' ||
				pt->map[i][k - 1] == 'E')
				{
					left(pt, i, k, pt->map[i][k - 1]);
					break ;
				}
			}
			k++;
		}
		i++;
	}
}

void	move_check_up(t_isso *pt)
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
			if (pt->map[i][k] == 'P')
			{
				if (pt->map[i - 1][k] == '0' || pt->map[i - 1][k] == 'E' ||
				pt->map[i - 1][k] == 'C')
				{
					up(pt, i, k, pt->map[i - 1][k]);
					return ;
				}
			}
			k++;
		}
		i++;
	}
}

void	move_check_down(t_isso *pt)
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
			if (pt->map[i][k] == 'P')
			{
				if (pt->map[i + 1][k] == '0' || pt->map[i + 1][k] == 'C' ||
				pt->map[i + 1][k] == 'E' )
				{
					down(pt, i, k, pt->map[i + 1][k]);
					return ;
				}
			}
			k++;
		}
		i++;
	}
}
