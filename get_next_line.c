/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:51:15 by mboukaiz          #+#    #+#             */
/*   Updated: 2022/11/13 11:54:30 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *select_first(int fd, char *str, int readed)
{
    int i = 0;
    while(str[i] != '\n' && str[i])
        i++;
    return(ft_substr(str, 0, i));
}

char *select_second(int fd, char *str, int readed)
{
    while(*str != '\n' && *str)
        str++;
    return (++str);
}

char *get_next_line(int fd)
{
    char Buffer[BUFFER_SIZE + 1];
    static char *str;
    char *temp;
    int readed;
    int i = 0;
    char *line;

    readed = BUFFER_SIZE;
    if(fd < 0 || BUFFER_SIZE <= 0 || readed == -1)
        return ("-1");
    while(readed)
    {
        readed = read(fd, Buffer, BUFFER_SIZE);
        if(readed == -1)
            return ("-1");
        Buffer[readed] = 0;
        temp = str;
        str = ft_strjoin(temp, Buffer);
        temp = NULL;
        if (strchr(str, '\n'))
            break;
    }
    line = select_first(fd, str, readed);
    temp = str;
    str = select_second(fd, temp, readed);
    // free(str);
    return (line);
}
