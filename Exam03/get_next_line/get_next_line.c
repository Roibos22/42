/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:05:55 by leon              #+#    #+#             */
/*   Updated: 2023/10/03 16:28:58 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int main(void)
{
    int     fd;
    char    *line;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (0);
    line = get_next_line(fd);
    printf("Line: %s\n", line);
    //close(fd);
    //fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (0);
    line = get_next_line(fd);
    printf("Line: %s\n", line);
    close(fd);
    return(0);
} */

char *get_next_line(int fd)
{
    char        *line;
    char        *buffer;
    static char *res;
    int         bread;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    bread = 1;
    //printf("res0:%s\n", res);
    while (ft_no_newline(res) == 1)
    {
        buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (!buffer)
            return (NULL);
        bread = read(fd, buffer, BUFFER_SIZE);
        if (bread <= 0)
        {
            free(buffer);
            break ;
        }
        res = ft_strjoin(buffer, res);
        free (buffer);
    }
    //printf("get line with res: %s and bread: %i\n", res, bread);
    line = get_line(res, bread);
    //printf("line: %s\n", line);
    res = clean_res(res, bread);
    return (line);
}

char *clean_res(char *res, int bread)
{
    int i = 0;
    int start = ft_strlen_to(res, '\n');
    char *new;

    if (bread == -1)
		return (free(res), NULL);
    if (!res)
        return (NULL);
    new = malloc((ft_strlen_to(res, '\0') - start + 1) * sizeof(char));
    if (!new)
        return (NULL);
    while (res[i + start])
    {
        new[i] = res[i + start];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char *get_line(char *res, int bread)
{
    int   len;
    char  *line;
    int   i = 0;

    if (bread == -1)
        return (NULL);
    if (!res)
        return (NULL);
    if (res[0] == '\n')
        res = res + 1;
    len = ft_strlen_to(res, '\n');
    line = malloc((len + 1) * sizeof(char));
    while (i < len)
    {
        line[i] = res[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

int ft_no_newline(char *s)
{
    int i = 0;
    
    if (!s)
        return (1);
    while(s[i])
    {
        if (s[i] == '\n')
            return (0);
        i++; 
    }
    return (1);
}

// UTILS

size_t ft_strlen_to(const char *s, char c)
{
    int len;

    len = 0;
    if (!s)
        return (0);
    while(s[len] && (s[len] != c))
        len++;
    return (len);
}

char *ft_strdup(const char *s)
{
    char *dest;
    int i;

    if (!s)
        return (NULL);
    dest = malloc((ft_strlen_to(s, '\0') + 1) * sizeof(char));
    if (!dest)
        return (free(dest), NULL);
    i = 0;
    while (s[i])
    {
        dest[i] = s[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strjoin(char *s1, const char *s2)
{
    char *res;
    int i = 0;
    int j = 0;

    if(!s1)
        s1 = ft_strdup("");
    if(!s2)
        s2 = ft_strdup("");
    res = malloc((ft_strlen_to(s1, '\0') + ft_strlen_to(s2, '\0') + 1) * sizeof(char));
    if (!res)
        return(free(s1), NULL);
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        res[i + j] = s2[j];
        j++;
    }
    res[i + j] = '\0';
    return (res);
}

