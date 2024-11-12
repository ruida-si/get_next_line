/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:51:16 by ruida-si          #+#    #+#             */
/*   Updated: 2024/11/12 17:52:00 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#define FD_MAX 1024

char	*readfile(int fd, char *buffer, char *line)
{
	int		b_read;
	char	*temp;

	b_read = 1;
	while (b_read)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		buffer[b_read] = '\0';
		if (!line)
			line = ft_strdup("");
		temp = line;
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

char	*next_call(char *line)
{
	char	*temp;
	char	*backup;

	if (ft_strchr(line, '\n'))
	{
		temp = ft_strchr(line, '\n');
		if (*(temp + 1))
		{
			backup = ft_strdup(temp +1);
			*(temp +1) = '\0';
			return (backup);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup[FD_MAX];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = readfile(fd, buffer, backup[fd]);
	free(buffer);
	if (!line)
		return (NULL);
	backup[fd] = next_call(line);
	return (line);
}
/*
int main()
{
	int fd = open("test", O_RDWR | O_CREAT, 0644);
	int fd2 = open("test2", O_RDWR | O_CREAT, 0644);
	if (fd < 0 || fd2 < 0)
	{
		perror("Error opening files");
		return (1);
	}

	char *s = get_next_line(fd);
	printf(".%s.", s);
	free(s);

	s = get_next_line(fd2);
	printf(".%s.", s);
	free(s);

	s = get_next_line(fd);
	printf(".%s.", s);
	free(s);

	s = get_next_line(fd2);
	printf(".%s.", s);
	free(s);

	close(fd);
	close(fd2);
	
	return (0);
}
*/