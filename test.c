/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:07:10 by rofontai          #+#    #+#             */
/*   Updated: 2022/12/15 14:12:52 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd1;

	fd1 = open("file_test.txt", O_RDONLY);
	line = get_next_line(fd1);
	while (line)
	{
		printf(">%s<", line);
		printf("%s\n", "-----REUSSI-----");
		free(line);
		line = get_next_line(fd1);
	}
	printf(">%s<", line);
	free(line);
	close(fd1);
	return (0);
}
