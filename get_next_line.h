/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:34:19 by rofontai          #+#    #+#             */
/*   Updated: 2022/12/15 11:56:47 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>		/*à Supprimer*/
# include <fcntl.h>		/*à Supprimer*/
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
