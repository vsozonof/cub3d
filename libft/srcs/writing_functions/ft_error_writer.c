/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_writer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 07:38:41 by vsozonof          #+#    #+#             */
/*   Updated: 2024/03/10 13:14:38 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pr_error(char *error)
{
	ft_printf("\e[1;31m");
	ft_printf("🧊 Cub3D: Error: %s\n", error);
	ft_printf("\e[0;37m");
	return (1);
}
