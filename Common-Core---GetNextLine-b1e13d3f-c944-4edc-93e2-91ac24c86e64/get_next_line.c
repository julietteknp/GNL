/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 15:00:03 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/11 15:52:12 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

static char    *ft_get_line(char *left, char c)
{
	char	*line;
	char	*start;
	int	len;

	len = 0;
	while (left[len] != c && left[len] != '\0')
		len ++;
	if (left[len] == c)
		len++;
	line = malloc (sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	start = line;
	while (len > 0)
	{
		*line++ = *left++;
		len --;
	}
	*line = '\0';
	return (start);
}

static char    *ft_get_left(char *left, char c)
{
	while (*left != '\0' && *left != c)
		left++;
	if (*left == c)
		left ++;
	if (*left == '\0')
		return (NULL);
	return (ft_strdup(left));
}

static char    *ft_split(char **left, char c)
{
        char    *old;
        char    *line;
	char	*new_left;

        if (!left || !*left)
		return (NULL);
	old = *left;
	line = ft_get_line(old, c);
	if (line == NULL)
		return (NULL);
	new_left = ft_get_left(old, c);
	free (old);
	*left = new_left;
	return (line);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *s;
        int             len;

         if (s1 ==  NULL)
                s1 = "";
	len = ft_strlen(s1) + ft_strlen(s2);
        s = malloc(sizeof(char) * (len + 1));
        if (s == NULL)
                return (NULL);
	while (*s1)
                *s++ = *s1++;
        while (*s2)
                *s++ = *s2++;
        *s = '\0';
        return (s - len);
}

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	static char *left;
	char	*temp;
	int	n;
		
	n = 1;
	while (n > 0 && ft_strrchr(left, '\n') == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		buf[n] = '\0';
		temp = ft_strjoin(left, buf);
		free (left);
		left = temp;
	}
	if (left == NULL || *left == '\0')
        {
                free(left);
                left = NULL;
                return (NULL);
        }
	return (ft_split(&left, '\n'));
}

int	main(void)
{
	int	fd;
	char	*lign;

	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
                return (0);
	while ((lign = get_next_line(fd)) != NULL)
	{
		printf("%s", lign);
		free (lign);
	}
	return (0);
}

