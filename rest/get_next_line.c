/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:53:52 by learodri          #+#    #+#             */
/*   Updated: 2022/10/18 19:26:22 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*line_only(char *memorycard)
{
	int		i;
	char	*str;

	i = 0;
	if (!memorycard[i])
		return (NULL);
	while (memorycard[i] && memorycard[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (memorycard[i] && memorycard[i] != '\n')
	{
		str[i] = memorycard[i];
		i++;
	}
	if (memorycard[i] == '\n')
	{
		str[i] = memorycard[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*rest4next(char *memorycard)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (memorycard[i] && memorycard[i] != '\n')
		i++;
	if (!memorycard[i])
	{
		free(memorycard);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(memorycard) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (memorycard[i])
		s[j++] = memorycard[i++];
	s[j] = '\0';
	free(memorycard);
	return (s);
}

char	*readuntillinebr(int fd, char *memorycard)
{
	char	*buff;
	int		byte_check;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	byte_check = 1;
	while (!ft_strchr(memorycard, '\n') && byte_check != 0)
	{
		byte_check = read(fd, buff, BUFFER_SIZE);
		if (byte_check == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte_check] = '\0';
		memorycard = ft_strjoin(memorycard, buff);
	}
	free(buff);
	return (memorycard);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*memorycard;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	memorycard = readuntillinebr(fd, memorycard);
	if (!memorycard)
		return (NULL);
	line = line_only(memorycard);
	memorycard = rest4next(memorycard);
	return (line);
}
