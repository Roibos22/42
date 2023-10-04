/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:05:55 by leon              #+#    #+#             */
/*   Updated: 2023/10/04 16:20:36 by leon             ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;

	if (!s1)
		s1 = ft_strdup("");
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (free(s1), NULL);

    int i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	res[i + ft_strlen(s1)] = '\0';
	free (s1);
	return (res);
}

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dest;
	int		i;

	i = 0;
	len = ft_strlen(s);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)		
		return (free(dest), NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


int	ft_no_newline(const char *s)
{
	int	i = 0;
	
    if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	clean_res_get_start(char *res)
{
	int	start;

	start = 0;
	while (res[start])
	{
		if (res[start] == '\n')
		{
			start++;
			break ;
		}
		start++;
	}
	return (start);
}

char	*clean_res(char *res, int bread)
{
	char	*new;
	int		i;
	int		start;

	if (bread == -1)
		return (free(res), NULL);
	i = 0;
	if (!res)
		return (NULL);
	start = clean_res_get_start(res);
	if (!res[start])
		return (free(res), NULL);
	new = malloc((ft_strlen(res) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < ft_strlen(res) - start)
	{
		new[i] = res[i + start];
		i++;
	}
	new[i] = '\0';
	return (free(res), new);
}

char	*get_full_line(char *res, int bread)
{
	char	*line;
	int		i;
	int		len;

	if (bread == -1)
		return (NULL);
	i = 0;
	len = 0;
	if (!res)
		return (NULL);
	while (res[len])
	{
		len++;
		if (res[len - 1] == '\n')
			break ;
	}
	line = malloc(len + 1);
	while (i < len)
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*res;
	int			bread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bread = 1;
	while (ft_no_newline(res) == 1)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread <= 0)
		{
			free (buffer);
			break ;
		}
        buffer[bread] = '\0';
		res = ft_strjoin(res, buffer);
		free(buffer);
	}
	line = get_full_line(res, bread);
	res = clean_res(res, bread);
	return (line);
}
