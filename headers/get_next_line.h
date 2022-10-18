/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:05:23 by learodri          #+#    #+#             */
/*   Updated: 2022/10/18 19:05:58 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t			ft_strlen(char *str);

char			*ft_strchr(char *s, int c);

char			*ft_strjoin(char *s1, char *s2);

char			*get_next_line(int fd);

char			*line_only(char *memorycard);
char			*rest4next(char *memorycard);
char			*readuntillinebr(int fd, char *memorycard);

#endif