/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:17:27 by learodri          #+#    #+#             */
/*   Updated: 2022/12/01 19:43:34 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"


/*char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}*/

char	**ber_to_mtx(char **map, int fd, int counter)
{
	char	*str; // vem com o /n ao final de cada linha

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

void	line_colun(isso *p)
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