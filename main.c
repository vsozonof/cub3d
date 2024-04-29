/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:10:02 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/29 11:06:59 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_utils	utils;

	initialize_struct(&data, &utils);
	if (parsing_manager(&data, argc, argv, &utils))
		return (1);
	window_creation(&data, &utils);
	return (0);
}
