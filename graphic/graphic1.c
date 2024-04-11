/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:16:22 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/11 13:16:14 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exec_manager(int argc, char **argv, t_data *data, t_utils *utils)
{
	(void)argc;
	(void)argv;

	window_creation(data, utils);
	return (0);
}

int	refresh_player_pos(char **argv, t_info *ptr)
{
	ptr->ma->posx = found_player_pos_x(argv);
	if (ptr->ma->posx == -1)
		return (printf("error when searching player 1\n"), -1);
	ptr->ma->posy = found_player_pos_y(argv);
	if (ptr->ma->posy == -1)
		return (printf("error when searching player 2\n"), -1);
	return (0);
}
