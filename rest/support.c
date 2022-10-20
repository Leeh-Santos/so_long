/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:17:27 by learodri          #+#    #+#             */
/*   Updated: 2022/10/20 21:56:57 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*ber_to_str(fd)
{
	char	*temp;

	while(!get_next_line(fd))
	{
		temp = get_next_line(fd);	
	}
}