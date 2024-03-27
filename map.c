/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:11:27 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/27 12:57:15 by beredzhe         ###   ########.fr       */
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
		ft_printf("Error: The map must be in the .ber format.\n");
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

int	check_path(t_data *data, int **marked)
{
	int	row;
	int	col;
	int	exit;
	int	coins;

	row = -1;
	exit = 0;
	coins = 0;
	while (data->map->map[++row])
	{
		col = -1;
		while (data->map->map[row][++col])
		{
			if ((data->map->map[row][col] == 'E') && (marked[row][col]))
				exit++;
			if ((data->map->map[row][col] == 'C') && (marked[row][col]))
				coins++;
		}
	}
	if ((coins + exit) == data->map->coins + 1)
		return (1);
	return (0);
}

void	ft_check_coin(t_data *data, int row, int col, int **marked)
{
	if ((row < 0 || row >= data->rows) && (col < 0 || col >= data->cols))
		return ;
	if (data->map->map[row][col] != '1' && marked[row][col] != 1)
	{
		marked[row][col] = 1;
		ft_check_coin(data, row, col + 1, marked);
		ft_check_coin(data, row, col - 1, marked);
		ft_check_coin(data, row + 1, col, marked);
		ft_check_coin(data, row - 1, col, marked);
	}
}

void	can_access_coins(t_data *data)
{
	int	**marked;
	int	valid;
	int	i;

	i = 0;
	valid = 1;
	data->rows = data->size_y / IMG_H;
	data->cols = data->size_x / IMG_W;
	marked = ft_calloc(data->rows, sizeof(int *));
	while (i < data->rows)
	{
		marked[i] = (int *)ft_calloc(data->cols, sizeof(int));
		i++;
	}
	ft_check_coin(data, data->pos[0], data->pos[1], marked);
	valid = check_path(data, marked);
	while (--i >= 0)
		free(marked[i]);
	free(marked);
	if (!valid)
		ft_map_error("Error: Some collectibles are unreachable.\n");
}
