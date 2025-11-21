/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epesnel <epesnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:12:50 by epesnel           #+#    #+#             */
/*   Updated: 2025/11/21 14:19:58 by epesnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (s[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_dup_or_join(char *stash, char *buffer)
{
	char	*save_stash;

	if (!stash)
		return (ft_strdup(buffer));
	save_stash = ft_strjoin(stash, buffer);
	free (stash);
	return (save_stash);
}

char	*ft_copy_and_free(char **stash, char **buffer, ssize_t bytes_read)
{
	char	*line;

	line = NULL;
	if (*stash && **stash && bytes_read == 0)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		free(*buffer);
		*buffer = NULL;
		return (line);
	}
	if (*stash && ft_strchr(*stash, '\n') != NULL)
	{
		line = ft_substr(*stash, 0, (ft_strlen(*stash) - ft_strlen\
(ft_strchr(*stash, '\n'))) + 1);
		ft_extract_line(stash);
		return (line);
	}
	free(*stash);
	*stash = NULL;
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

void	ft_extract_line(char **ptr)
{
	char	*save_stash;

	save_stash = ft_strdup(ft_strchr(*ptr, '\n') + 1);
	free (*ptr);
	*ptr = save_stash;
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	ssize_t		bytes_read;

	buffer = NULL;
	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes_read != 0)
	{
		if ((stash && ft_strchr(stash, '\n') != NULL))
			return (ft_copy_and_free(&stash, &buffer, bytes_read));
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_dup_or_join(stash, buffer);
		free (buffer);
		buffer = NULL;
	}
	return (ft_copy_and_free(&stash, &buffer, bytes_read));
}

/*int	main(void)
{
	int		fd;
	char	*str;

	fd = 0;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Erreur d'ouverture\n");
		return(1);
	}
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	return(0);
}*/
