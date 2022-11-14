/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:17:27 by learodri          #+#    #+#             */
/*   Updated: 2022/11/14 20:42:40 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

/*char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	int		length_s1;
	int		length_s2;

	if (!s1 || !s2)
		return (NULL);
	length_s1 = strlen(s1);
	length_s2 = strlen(s1);
	string = malloc((length_s1 + length_s2 + 1) * sizeof(char));
	if (!string)
		return (NULL);
	memcpy(string, s1, length_s1);
	memcpy(string + length_s1, s2, length_s2);
	return (string);
}*/

char	*ft_strjoin(char *s1, char *s2)
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
}

char	*ber_to_str(int fd)
{
	char	*temp;
	static char *str;
	int	check;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		boom("malloc failed");
	
	while (check != 0)
	{
		check = read(fd, temp, BUFFER_SIZE);
		temp[check] = '\0';
		str = ft_strjoin(str, temp);
		if (check == -1)
				boom("read func. failed");
	}
	free(temp);
	//printf("%s", str);
	return (str);
}

int	linecount(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;

	while (str[i] != '\0')
	{
			if (str[i] == '\n')
				count++;
		i++;
	}

	return (count); // CUIDADO COM .BER SE NAO TEM UN \N AO FINAL ADD +1 AO COUNT,E O CHEKER 
}

int	coluncount(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}

	return (i);
}