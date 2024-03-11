/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:11:41 by vsozonof          #+#    #+#             */
/*   Updated: 2024/03/11 13:28:54 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "mlx.h"

typedef struct s_data
{
	char	*map_name;
	char	*map;
	int		fd;
}	t_data;

int		parsing_manager(t_data *data, int argc, char **argv);
int		argument_checker(t_data *data);
int		is_valid_name(char *map_name);

// ! Printing
void	pr_parsing_start(void);


#endif