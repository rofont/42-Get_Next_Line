/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:56:50 by rofontai          #+#    #+#             */
/*   Updated: 2022/12/29 21:54:58 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *save)
{
	char	*buff;
	int		byte;

	buff = calloc_ptr(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	byte = 1;
	while ((search_nline(save, '\n') == 0 || !save) && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			free(save);
			return (0);
		}
		save = join(save, buff);
		ft_bzero(buff, BUFFER_SIZE);
	}
	free(buff);
	return (save);
}

char	*join(char *save, char *buff)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (!save)
		save = calloc_ptr(sizeof(char), 1);
	dest = calloc_ptr(sizeof(char), (lenstr(save) + lenstr(buff) + 1));
	if (!dest)
		return (free_ft(save));
	while (save[i])
	{
		dest[i] = save[i];
		i++;
	}
	while (buff[j])
	{
		dest[i] = buff[j];
		i++;
		j++;
	}
	free(save);
	return (dest);
}

int	search_nline(char *save, char c)
{
	int	i;

	i = 0;
	if (!save)
		return (0);
	while (save[i])
	{
		if (save[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*extract_line(char *save, char c)
{
	int		i;
	char	*dest;

	i = 0;
	if (!save[0])
		return (0);
	while (save[i])
		if (save[i++] == c)
			break ;
	dest = calloc_ptr(sizeof(char), i + 1);
	if (!dest)
		return (0);
	i = 0;
	while (save[i] && save[i] != c)
	{
		dest[i] = save[i];
		i++;
	}
	if (save[i] == c)
	{
		dest[i] = save[i];
		i++;
	}
	return (dest);
}

char	*crop_save(char *save, char c)
{
	int		i;
	int		start;
	char	*dest;

	start = 0;
	while (save[start] && save[start] != c)
		start++;
	if (!save[start])
		return (free_ft(save));
	dest = calloc_ptr(sizeof(char), (lenstr(save) - start + 1));
	if (!dest)
		return (0);
	start++;
	i = 0;
	while (save && save[start])
	{
		dest[i] = save[start];
		i++;
		start++;
	}
	free(save);
	save = NULL;
	return (dest);
}
