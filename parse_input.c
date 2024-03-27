/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:11:11 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/27 09:41:07 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(char *error_msg)
/* will print the error message end exit the process */
{
	ft_printf("%s", error_msg);
	exit(EXIT_FAILURE);
}

static void	ft_check_borders(t_data *data)
/* will check if the whole map is surrounded by walls */
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y / IMG_H))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->size_x / IMG_W)
			ft_map_error("Error: Map has to be rectangular\n");
		x = 0;
		while (x < (data->size_x / IMG_W))
		{
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1' &&
				data->map->map[y][x] != 'C' && data->map->map[y][x] != 'P' &&
				data->map->map[y][x] != 'E')
				ft_map_error("Error: Unknown character in the map.\n");
			else if ((y == 0 || x == 0) && data->map->map[y][x] != '1')
				ft_map_error("Error: The map has to be surrounded by walls\n");
			else if ((y == (data->size_y / IMG_H - 1)
					|| x == (data->size_x / IMG_W - 1))
				&& data->map->map[y][x] != '1')
				ft_map_error("Error: The map has to be surrounded by walls\n");
			x++;
		}
		y++;
	}
}

static void	ft_check_content(t_data *data)
/* will check the contents of the map if valid */
{
	int	row;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	data->map->coins = 0;
	row = 0;
	while (data->map->map && data->map->map[row])
	{
		exit += ft_count_c(data->map->map[row], 'E');
		player += ft_p_position(data, data->map->map[row], row);
		data->map->coins += ft_count_c(data->map->map[row], 'C');
		row++;
	}
	if (player != 1)
		ft_map_error("Error: Only valid map. Required only one player\n");
	if (exit != 1)
		ft_map_error("Error: Only valid map. Required only one exit\n");
	if (data->map->coins == 0)
		ft_map_error("Error: Only valid map. Required at\
			least one coin\n");
}

static void	ft_input_error(int argc)
/* only exists because of the 25 line limit */
{
	if (argc != 2)
	{
		ft_map_error("Error\nUsage: './so_long mappath/mapname.ber'\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_parse_input(t_data *data, char **argv, int argc)
/* will translate the .ber file into a 2-dimensional array of char * */
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	ft_input_error(argc);
	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
		{
			data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
		}
		else
			i++;
	}
	ft_check_content(data);
	ft_check_borders(data);
	can_access_coins(data);
}
