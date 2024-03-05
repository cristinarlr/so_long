/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:58:08 by Cristina          #+#    #+#             */
/*   Updated: 2024/02/28 12:49:01 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

size_t	strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*strchr_gnl(char *s, int c)
{
	char	ccomp;

	if (!s)
		return (NULL);
	ccomp = (char) c;
	while (*s && *s != ccomp)
		s++;
	if (*s == ccomp)
		return ((char *)s);
	return (NULL);
}

char	*strjoin_gnl(char *s1, char *s2)
{
	char	*ccatstr;
	size_t	ccatlen;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	ccatlen = (strlen_gnl(s1) + strlen_gnl(s2));
	ccatstr = malloc(ccatlen + 1);
	if (!ccatstr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ccatstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		ccatstr[i++] = s2[j++];
	ccatstr[i] = '\0';
	free (s1);
	return (ccatstr);
}

char	*strdup_gnl(const char *s1)
{
	char	*ptr;
	int		i;
	int		len;

	len = strlen_gnl(s1) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (0);
	if (strlen_gnl(s) <= start)
		return (strdup_gnl(""));
	if (strlen_gnl(&s[start]) < len)
		len = strlen_gnl(&s[start]);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (ptr);
	i = 0;
	while (i < len && s[start])
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
