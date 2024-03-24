/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:09:30 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/23 11:23:13 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_error(void)
{
	printf("Error\nwrong map dimensions\n");
	exit(EXIT_FAILURE);
}

int	ft_count_lines(int fd, int x, int img_w)
/* returns how many lines the file of fd contains */
{
	char	*line;
	int		linecount;

	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_strlen(line) < x / img_w
			|| (ft_strlen(line) == 1 && *line != '\n'))
		{
			free(line);
			exit_error();
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}
