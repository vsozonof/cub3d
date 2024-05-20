/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_checker-1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:03:08 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/20 08:32:09 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	are_all_params_ok(t_data *data)
{
	int	i;

	i = 0;
	if (!data->ceiling_color)
		pr_error_spe("Ceiling color parameter is missing.", &i);
	if (!data->floor_color)
		pr_error_spe("Floor color parameter is missing.", &i);
	if (!data->north_texture)
		pr_error_spe("North texture path is missing.", &i);
	if (!data->south_texture)
		pr_error_spe("South texture path is missing.", &i);
	if (!data->east_texture)
		pr_error_spe("East texture path is missing.", &i);
	if (!data->west_texture)
		pr_error_spe("West texture path is missing.", &i);
	return (i);
}

void	skip_parameter(char *map, int *i, int *n)
{
	*i += 2;
	while (map[*i] && ft_is_whitespace(map[*i]))
		*i += 1;
	while (map[*i] && !ft_is_whitespace(map[*i]))
		*i += 1;
	*n += 1;
}

int	iterate_to_map_location(char *map, int i)
{
	int	n;

	n = 0;
	while (map[i])
	{
		if (n == 6)
			break ;
		if (map[i] == 'N' && map[i + 1] == 'O')
			skip_parameter(map, &i, &n);
		else if (map[i] == 'S' && map[i + 1] == 'O')
			skip_parameter(map, &i, &n);
		else if (map[i] == 'E' && map[i + 1] == 'A')
			skip_parameter(map, &i, &n);
		else if (map[i] == 'W' && map[i + 1] == 'E')
			skip_parameter(map, &i, &n);
		else if (map[i] == 'C' && map[i + 1] == ' ')
			skip_parameter(map, &i, &n);
		else if (map[i] == 'F' && map[i + 1] == ' ')
			skip_parameter(map, &i, &n);
		i++;
	}
	return (i);
}

int	update_map_var(t_data *data)
{
	int		i;
	char	*tmp;

	i = iterate_to_map_location(data->map, 0);
	tmp = data->map;
	data->map = ft_substr(data->map, i, ft_strlen(data->map));
	free(tmp);
	tmp = ft_strtrim(data->map, "\n");
	if (!tmp)
		return (1);
	free(data->map);
	data->map = tmp;
	if (!data->map || ft_strlen(data->map) == 0)
		return (1);
	return (0);
}

int	map_file_parser(t_data *data)
{
	pr_msg(GET_PARAMS, 0);
	if (texture_path_getter(data, 0) || color_code_getter(data, 0))
	{
		pr_msg(GET_PARAMS, 1);
		return (pr_error("Double parameters detected."));
	}
	else if (are_all_params_ok(data))
		return (1);
	if (update_map_var(data))
	{
		pr_msg(GET_PARAMS, 1);
		return (pr_error("A problem with the map was detected"));
	}
	pr_msg(GET_PARAMS, 2);
	return (0);
}
