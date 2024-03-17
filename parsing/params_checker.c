/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:03:08 by vsozonof          #+#    #+#             */
/*   Updated: 2024/03/17 16:35:04 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_file_parser(t_data *data)
{
	if (texture_path_getter(data, 0))
		return (1);
	if (color_code_getter(data, 0))
		return (1);
	// Check si tous les params ont été obtenus
	return (0);
}
