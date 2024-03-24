/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:09:35 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/24 17:04:32 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_data *data)
/* will show a message in the terminal and exit the process */
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("You gave up :(\n");
	ft_printf("Is the map hard for you?\n");
	exit(EXIT_SUCCESS);
}

void	can_access_coins(t_data *data)
{
	int	c;

	c = ft_check_coin(data->map->map, data->size_x / 32, data->size_y / 32, \
		data->p_x, data->p_y);
	if (c != data->map->coins)
	{
		ft_printf("%d collectible(s) inaccessible!!!", data->map->coins - c);
		exit(EXIT_FAILURE);
	}
}

static int	ft_render_next_frame(t_data *data)
/* checks for keyboard or mouse input */
{
	ft_put_background(data);
	ft_create_map(data);
	// can_access_coins(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

int	main(int argc, char **argv)
/* runs the mlx loop */
{
	t_data	data;
	t_map	map;

	ft_window_size(&data, argv);
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
	{
		perror("Error\ncalloc failed\n");
		exit(EXIT_FAILURE);
	}
	ft_init(&data, &map);
	ft_parse_input(&data, argv, argc);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("Error\nprogramm init failed\n");
		exit(EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.size_x,
			data.size_y, "./so_long");
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
	perror("Error\nloop failed\n");
	exit(EXIT_FAILURE);
}
