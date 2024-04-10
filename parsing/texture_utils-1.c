/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils-1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:10:54 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/08 14:05:21 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*extract_path(char *str, int *i)
{
	int	c;

	*i += 2;
	while (str[*i] && ft_is_whitespace(str[*i]))
		*i += 1;
	c = *i;
	while (str[*i] && !ft_is_whitespace(str[*i]))
		*i += 1;
	return (ft_substr(str, c, *i - c));
}

int	double_checker_1(char *str, int *i, int mode, t_data *data)
{
	if (mode == 1)
	{
		if (!data->north_texture)
			data->north_texture = extract_path(str, i);
		else
			return (1);
	}
	else if (mode == 2)
	{
		if (!data->south_texture)
			data->south_texture = extract_path(str, i);
		else
			return (2);
	}
	else
		return (double_checker_2(str, i, mode, data));
	return (0);
}

int	double_checker_2(char *str, int *i, int mode, t_data *data)
{
	if (mode == 3)
	{
		if (!data->east_texture)
			data->east_texture = extract_path(str, i);
		else
			return (3);
	}
	else if (mode == 4)
	{
		if (!data->west_texture)
			data->west_texture = extract_path(str, i);
		else
			return (4);
	}
	return (0);
}

int	texture_path_getter(t_data *data, int i)
{
	while (data->map[i])
	{
		if (data->map[i] == 'N' && data->map[i + 1] == 'O')
		{
			if (double_checker_1(data->map, &i, 1, data))
				return (1);
		}
		else if (data->map[i] == 'S' && data->map[i + 1] == 'O')
		{
			if (double_checker_1(data->map, &i, 2, data))
				return (1);
		}
		else if (data->map[i] == 'E' && data->map[i + 1] == 'A')
		{
			if (double_checker_1(data->map, &i, 3, data))
				return (1);
		}
		else if (data->map[i] == 'W' && data->map[i + 1] == 'E')
		{
			if (double_checker_1(data->map, &i, 4, data))
				return (1);
		}
		i++;
	}
	return (0);
}

int	color_code_getter(t_data *data, int i)
{
	while (data->map[i])
	{
		if (data->map[i] == 'F' && data->map[i + 1] == ' ')
		{
			if (!data->floor_color)
				data->floor_color = extract_path(data->map, &i);
			else
				return (1);
		}
		else if (data->map[i] == 'C' && data->map[i + 1] == ' ')
		{
			if (!data->ceiling_color)
				data->ceiling_color = extract_path(data->map, &i);
			else
				return (1);
		}
		i++;
	}
	return (0);
}
