/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 15:00:03 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/09 14:57:01 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char    *ft_split(char **left, char c)
{
        char    *s;
        char    *left_copy;
        int     len;

        left_copy = *left;
        len = 0;
        while (*left_copy != c && *left_copy != '\0')
        {
                len++;
                left_copy++;
        }
        s = malloc (sizeof(char) * (len + 1));
        if (s == NULL)
                return (NULL);
        left_copy = left_copy - len;
        //printf("%s", left_copy);
        while (*left_copy != c && *left_copy != '\0')
        {
                *s = *left_copy;
                //printf("%c", *s);
                s++;
                left_copy++;
        }
        *s = '\0';
	if (*left_copy == '\0')
		*left = NULL;
	else 
        	*left = left_copy + 1;
        return (s - len);
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
		printf("avant read\n");
		n = read(fd, buf, BUFFER_SIZE);
		printf("apres read, n = %d\n", n);
		if (n == -1)
			return (NULL);
		buf[n] = '\0';
		printf("buf = %s\n", buf);
		temp = ft_strjoin(left, buf);
		printf("apres strjoin\n");
		free (left);
		left = temp;
		printf("left = %s\n", left);
	}
	if (n == 0 && !ft_strrchr(left, '\n'))
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
	printf("%s", get_next_line(fd));
	/*while ((lign = get_next_line(fd)) != NULL)
	{
		printf("%s", lign);
		free (lign);
	}*/
	return (0);
}

