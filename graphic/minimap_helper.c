/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:05:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/03 09:16:21 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_movement_minimap(t_info *ptr, int input)
{
	int	x;
	int	y;

	y = ptr->p_y;
	x = ptr->p_x;
	if (input == 1)
		y = y -1;
	else if (input == 2)
		x = x - 1;
	else if (input == 3)
		y = y + 1;
	else if (input == 4)
		x = x + 1;
	ptr->p_y = y;
	ptr->p_x = x;
}
