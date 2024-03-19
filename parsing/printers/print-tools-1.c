/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print-tools-1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:32:18 by vsozonof          #+#    #+#             */
/*   Updated: 2024/03/19 08:31:26 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pr_parsing_start(void)
{
	ft_printf("\033[1;35m");
	ft_printf("█▀ ▀█▀ ▄▀█ █▀█ ▀█▀ █ █▄░█ █▀▀   █▀█ ▄▀█ █▀█ █▀ █ █▄░█ █▀▀\n");
	ft_printf("▄█ ░█░ █▀█ █▀▄ ░█░ █ █░▀█ █▄█   █▀▀ █▀█ █▀▄ ▄█ █ █░▀█ █▄█\n\n");
	ft_printf("\033[0;37m");
}

void	pr_msg(char *msg, int mode)
{
	if (mode == 0)
	{
		ft_printf("\e[1;37m");
		ft_printf("🧊 Cub3D: %s ...", msg);
		ft_printf("\e[0;37m");
	}
	else if (mode == 1)
	{
		ft_printf("\r");
		ft_printf("\e[1;31m");
		ft_printf("🧊 Cub3D: %s... \t\tKO X\n", msg);
		ft_printf("\e[0;37m");
	}
	else if (mode == 2)
	{
		ft_printf("\r");
		ft_printf("\e[1;32m");
		ft_printf("🧊 Cub3D: %s... \t\tOK ✔\n", msg);
		ft_printf("\e[0;37m");
	}
}

void	pr_error_spe(char *msg, int *i)
{
	static int	flag;

	if (flag == 0)
	{
		pr_msg(GET_PARAMS, 1);
		flag += 1;
	}
	pr_error(msg);
	*i += 1;
}
