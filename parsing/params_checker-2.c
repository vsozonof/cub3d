/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_checker-2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:09:18 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/02 10:50:36 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx_ptr(t_utils *utils)
{
	pr_msg(INIT_MLX, 0);
	utils->mlx = mlx_init();
	// if (!(utils->mlx))
	// {
	// 	pr_msg(INIT_MLX, 1);
	// 	return (pr_error("Failed to load the MiniLibX"));
	// }
	pr_msg(INIT_MLX, 2);
	return (0);
}

int	are_params_valid(t_data *data, t_utils *utils)
{
	(void)data;
	init_mlx_ptr(utils);
	return (0);
}
