/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:46:11 by vsozonof          #+#    #+#             */
/*   Updated: 2024/03/11 13:37:53 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_name(char *map_name)
{
	char	*ext;

	ft_printf("\e[1;37m");
	ft_printf("🧊 Cub3D: Checking file name ...\t");
	ft_printf("\e[0;37m");
	ext = ft_strnstr(map_name, ".cub", ft_strlen(map_name));
	if (ext[4] != '\0' || !ext)
	{
		ft_printf("\r");
		ft_printf("\e[1;31m");
		ft_printf("🧊 Cub3D: Checking file name ...\tKO X\n");
		ft_printf("\e[0;37m");
		return (pr_error("Invalid file name"));
	}
	ft_printf("\r");
	ft_printf("\e[1;32m");
	ft_printf("🧊 Cub3D: Checking file name ...\tOK ✔\n");
	ft_printf("\e[0;37m");
	return (0);
}

int	argument_checker(t_data *data)
{
	if (is_valid_name(data->map_name))
		return (1);
	ft_printf("\e[1;37m");
	ft_printf("🧊 Cub3D: Opening file ...\t");
	ft_printf("\e[0;37m");
	data->fd = open(data->map_name, O_RDONLY);
	if (data->fd == -1)
	{
		ft_printf("\r");
		ft_printf("\e[1;31m");
		ft_printf("🧊 Cub3D: Opening map file ...\t\tKO X\n");
		ft_printf("\e[0;37m");
		return (pr_error("open() failure."));
	}
	ft_printf("\r");
	ft_printf("\e[1;32m");
	ft_printf("🧊 Cub3D: Opening file ...\t\tOK ✔\n");
	ft_printf("\e[0;37m");
	return (0);
}

int	parsing_manager(t_data *data, int argc, char **argv)
{
	pr_parsing_start();
	ft_printf("\e[1;37m");
	ft_printf("🧊 Cub3D: Checking argument number ...\t");
	ft_printf("\e[0;37m");
	if (argc != 2)
	{
		ft_printf("\r");
		ft_printf("\e[1;31m");
		ft_printf("🧊 Cub3D: Checking argument number ...\tKO X\n");
		ft_printf("\e[0;37m");
		return (pr_error("Invalid amount of arguments."));
	}
	ft_printf("\r");
	ft_printf("\e[1;32m");
	ft_printf("🧊 Cub3D: Checking argument number ...\tOK ✔\n");
	ft_printf("\e[0;37m");
	data->map_name = argv[1];
	if (argument_checker(data))
		return (1);
	return (0);
}
