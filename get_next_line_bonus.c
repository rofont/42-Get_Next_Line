/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:53:36 by rofontai          #+#    #+#             */
/*   Updated: 2022/12/15 14:00:30 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*calloc_ptr(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	if (!s)
		return ;
	i = 0;
	temp = (char *)s;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
}

int	lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*free_ft(char *str)
{
	if (str)
		free(str);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	save[fd] = ft_read(fd, save[fd]);
	if (!save[fd])
		return (free_ft(save[fd]));
	line = extract_line(save[fd], '\n');
	save[fd] = crop_save(save[fd], '\n');
	if (!line)
		return (free_ft(save[fd]));
	return (line);
}
