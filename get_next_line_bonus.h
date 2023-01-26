/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:57:43 by rofontai          #+#    #+#             */
/*   Updated: 2023/01/26 15:03:24 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
void	*calloc_ptr(size_t count, size_t size);
int		lenstr(char *str);
char	*ft_read(int fd, char *save);
char	*join(char *save, char *buff);
int		search_nline(char *save, char c);
char	*extract_line(char *save, char c);
char	*crop_save(char *save, char c);
void	ft_bzero(void *s, size_t n);
void	*free_ft(char *str);

#endif
