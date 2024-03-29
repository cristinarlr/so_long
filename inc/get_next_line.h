/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crramire <crramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:03:16 by Cristina          #+#    #+#             */
/*   Updated: 2024/02/28 12:53:50 by crramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>
# include <sys/stat.h>

size_t	strlen_gnl(const char *s);
char	*strchr_gnl(char *s, int c);
char	*strjoin_gnl(char *s1, char *s2);
char	*substr_gnl(char const *s, unsigned int start, size_t len);
char	*strdup_gnl(const char *s1);
char	*get_next_line(int fd);

#endif
