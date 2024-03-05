/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:25:20 by Cristina          #+#    #+#             */
/*   Updated: 2024/02/28 12:52:16 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

static char	*ft_extract_line(char *stash)
{
	char	*line;
	char	*pnewline;
	int		line_len;

	if (stash[0] == '\0')
		return (NULL);
	if (strchr_gnl(stash, '\n'))
	{
		pnewline = strchr_gnl(stash, '\n') + 1;
		line_len = strlen_gnl(stash) - strlen_gnl(pnewline);
		line = substr_gnl(stash, 0, line_len);
		if (!line)
			return (NULL);
	}
	else
		line = strdup_gnl(stash);
	return (line);
}

static char	*ft_clean_stash(char *stash)
{
	char	*rest_stash;
	char	*pnewline;
	int		rest_stash_start;

	if (stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	if (strchr_gnl(stash, '\n'))
	{
		pnewline = strchr_gnl(stash, '\n') + 1;
		rest_stash_start = strlen_gnl(stash) - strlen_gnl(pnewline);
		rest_stash = substr_gnl(stash, rest_stash_start, strlen_gnl(pnewline));
		if (rest_stash == NULL)
		{
			free(stash);
			return (NULL);
		}
		free(stash);
		return (rest_stash);
	}
	free(stash);
	return (NULL);
}

static char	*ft_read_and_stock(int fd, char *stash)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	nbytes;

	*buff = '\0';
	nbytes = 1;
	while (!strchr_gnl(stash, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (stash);
			return (0);
		}
		buff[nbytes] = '\0';
		stash = strjoin_gnl(stash, buff);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!stash)
			return (NULL);
		*stash = '\0';
	}
	stash = ft_read_and_stock(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_extract_line (stash);
	stash = ft_clean_stash(stash);
	return (line);
}
