/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruida-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:51:16 by ruida-si          #+#    #+#             */
/*   Updated: 2024/11/08 15:51:19 by ruida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	int			b_read;
	static char	*backup;
	char		*temp;

	b_read = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (backup)
		line = ft_strdup(backup);
	else
		line = ft_strdup("");
	free(backup);
	backup = NULL;
	while (b_read)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (!b_read)
			break ;
		buffer[b_read] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
		if (ft_strchr(line, '\n'))
		{
			temp = ft_strchr(line, '\n');
			backup = ft_strdup(temp + 1);
			*(++temp) = '\0';
			break ;
		}
	}
	free(buffer);
	return (line);
}

int main()
{
	int fd = open("test", O_RDWR | O_CREAT, 0644);
	char *s = get_next_line(fd);
	printf(".%s.", s);
	free(s);
	s = get_next_line(fd);
	printf(".%s.", s);
	free(s);
}
