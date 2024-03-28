/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:11:02 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/27 09:23:50 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_background(t_data *data)
/* will fill the whole screen with background */
{
	int		y;
	int		x;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->background, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

void	ft_put_object(t_data *data, char *relative_path)
/* puts the given object to the current position */
{
	int		img_width;
	int		img_height;

	data->map->object = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->win, data->map->object,
		(data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	ft_put_player(t_data *data)
/* puts the player in the starting position */
{
	data->p_x = data->map->x;
	data->p_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->player_right,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
}

int	ft_p_position(t_data *data, char *s, int row)
/* will count appearances of c inside s and return them as integer */
{
	int	col;
	int	x;

	col = 0;
	x = 0;
	if (!s)
		return (-1);
	while (s && s[col])
	{
		if (s[col] == 'P')
		{
			data->pos[0] = row;
			data->pos[1] = col;
			x++;
		}
		col++;
	}
	return (x);
}
