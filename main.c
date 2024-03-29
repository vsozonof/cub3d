/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:10:02 by vsozonof          #+#    #+#             */
/*   Updated: 2024/03/28 10:40:38 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	initialize_struct(&data);
	if (parsing_manager(&data, argc, argv))
		return (1);
	exec_manager(argc, argv, &data);
	return (0);
}
