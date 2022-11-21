/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:36:22 by learodri          #+#    #+#             */
/*   Updated: 2022/11/21 19:45:27 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"


void    valid_path(isso *pt)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while(i < pt->line)
    {
        k = 0;
            while(k < pt->colun)
            {
                if(pt->map[i][k] == 'C' || pt->map[i][k] == 'E')
                {
                    if(pt->map[i][k + 1] == '1' && pt->map[i][k - 1] == '1' && pt->map[i + 1][k] == '1' && pt->map[i - 1][k] == '1')
                        boom("deu merda no valid path meu parceiro");
                }
                k++;
            }
        i++;    
    }
}