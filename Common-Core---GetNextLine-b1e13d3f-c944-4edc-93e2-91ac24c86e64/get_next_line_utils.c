* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:58:41 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/11 16:14:22 by jkonop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t   ft_strlen(const char *str)
{
        size_t  len;

        len = 0;
        if (!str)
                return (0);
        while (*str++)
                len++;
        return (len);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	while (*s)
	{
		*copy++ = *s++;
	}
	*copy = '\0';
	return (copy - len);
}

char    *ft_strrchr(const char *s, int c)
{
        char    *str;

        str = NULL;
        while (*s)
        {
                if (*s == (unsigned char) c)
                        str = (char *) s;
                s++;
        }
        if (*s == (unsigned char) c)
                str = (char *) s;
        return (str);
}


