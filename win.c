/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:09:03 by beredzhe          #+#    #+#             */
/*   Updated: 2024/03/17 11:56:47 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_data *data)
{
	ft_printf("Congratulations, you collect all the Coins and the exit.\n");
	ft_printf("You won!\n");
	ft_printf("Is %d moves really the best you can do?\n", data->counter);
	exit(EXIT_SUCCESS);
}
