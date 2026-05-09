/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkonop <jkonop@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 10:58:41 by jkonop            #+#    #+#             */
/*   Updated: 2026/05/09 11:19:37 by jkonop           ###   ########.fr       */
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


