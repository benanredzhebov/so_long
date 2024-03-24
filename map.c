/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:11:27 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/24 16:33:57 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_size(t_data *data, char **argv)
/* will find the window size and check for some errors */
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nInvalid map_path/map\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		ft_printf("Error\nmap has to be .ber\n");
		exit(EXIT_FAILURE);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
}

void	ft_create_map(t_data *data)
/* will fill the map with the corresponding images */
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			ft_put_player(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			ft_put_object(data, "./textures/wall.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			ft_put_object(data, "./textures/collectable.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			ft_put_object(data, "./textures/exit_door.xpm");
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}

int	ft_check_coin(char **map, int width, int height, int x, int y)
{
	int	c;

	c = 0;
	if (y < 0 || y >= height || x < 0 || x >= width)
		return (0);
	if (map[y][x] == 'C')
		c++;
	if (map[y][x] == 'v' || map[y][x] == '1')
		return (0);
	map[y][x] = 'v';
	c += ft_check_coin(map, width, height, x, y + 1);
	c += ft_check_coin(map, width, height, x, y - 1);
	c += ft_check_coin(map, width, height, x - 1, y);
	c += ft_check_coin(map, width, height, x + 1, y);
	return (c);
}
