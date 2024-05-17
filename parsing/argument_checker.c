/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:46:11 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/17 08:58:48 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_name(char *map_name)
{
	char	*ext;

	pr_msg(CHECK_F_NAME, 0);
	ext = ft_strnstr(map_name, ".cub", ft_strlen(map_name));
	if (!ext || ext[4] != '\0')
	{
		pr_msg(CHECK_F_NAME, 1);
		return (pr_error("Invalid file name"));
	}
	pr_msg(CHECK_F_NAME, 2);
	return (0);
}

int	open_map(char *map_name)
{
	int	fd;

	pr_msg(OPEN_FILE, 0);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		pr_msg(OPEN_FILE, 1);
		pr_error("open() failure.");
		return (-1);
	}
	pr_msg(OPEN_FILE, 2);
	return (fd);
}

int	read_map(t_data *data)
{
	char	*line;

	pr_msg(READ_MAP, 0);
	line = get_next_line(data->fd);
	if (!line)
	{
		pr_msg(READ_MAP, 1);
		return (pr_error("Map file is empty."));
	}
	while (line)
	{
		data->map = strjoin_and_free(data->map, line);
		if (!data->map)
		{
			pr_msg(READ_MAP, 1);
			return (pr_error("Malloc() error."));
		}
		line = get_next_line(data->fd);
	}
	pr_msg(READ_MAP, 2);
	return (0);
}

int	argument_checker(t_data *data)
{
	if (is_valid_name(data->map_name))
		return (1);
	data->fd = open_map(data->map_name);
	if (data->fd == -1)
		return (1);
	if (read_map(data))
		return (1);
	return (0);
}

int	is_there_enough_args(int n)
{
	pr_msg(CHECK_N_ARG, 0);
	if (n != 2)
	{
		pr_msg(CHECK_N_ARG, 1);
		return (pr_error("Invalid amount of arguments."));
	}
	pr_msg(CHECK_N_ARG, 2);
	return (0);
}
