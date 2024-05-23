/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:10:02 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/23 11:42:42 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_utils	utils;

	initialize_struct(&data, &utils);
	if (parsing_manage(&data, argc, argv, &utils))
		return (1);
	printf("voici ce qu'il y a dans texture %s\n", data.north_texture);
	window_creation(&utils, &data);
	return (0);
}
