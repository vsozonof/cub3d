/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:11:39 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/29 14:27:23 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_map(char **map, t_info *ptr)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	len++;
	ptr->utils->map = malloc(sizeof(char *) * (len + 1));
	while (map[i])
	{
		j = 0;
		ptr->utils->map[i] = malloc(sizeof(char) * (len + 1));
		while (map[i][j])
		{
			ptr->utils->map[i][j] = map[i][j];
			j++;
		}
		ptr->utils->map[i][j] = '\0';
		i++;
	}
	ptr->utils->map[i] = NULL;
}

void	show_db_tab(char **map)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("la map\n");
	if (!map)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return ;
}

int	len_db_tab(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (-1);
	while (map[i])
		i++;
	i--;
	return (i);
}

int		len_map(char *str) // strlen pour la map car les mur peuvent etre multiple
{
	int		i;

	i = 0;
	while (str[i])
	{
		// if (str[i] == '1')
			// return (i);
		i++;
	}
	return (i);
}

int	setup_color_ceiling_floor(t_info *ptr)
{
	ptr->crgb =  ft_atoi(ptr->utils->ceiling_color[0]) * 65536 + ft_atoi(ptr->utils->ceiling_color[1]) * 256 + ft_atoi(ptr->utils->ceiling_color[2]);
	ptr->frgb = ft_atoi(ptr->utils->floor_color[0]) * 65536 + ft_atoi(ptr->utils->floor_color[1]) * 256 + ft_atoi(ptr->utils->floor_color[2]);
	printf("voici mon test %d ainsi que mon floor %d\n", ptr->crgb, ptr->frgb);
	return (0);
}

//donc la je dois: prendre mon code (255. 165. 12)
//diviser mon premier int par 16
//prendre mes unite et les passer en base 16 -> premiere lettre de mon nb
//puis prendre mon nb apres la virgule, la multiplier par 16 ca fera mon second nb base 16

/*
int	setup_color_ceiling(t_info *ptr)
{
	int			i;
	double		nb1;
	double		nb2;
	char		*base;
	int			index_base;
	int			test;

	i = 0;
	base = "0123456789ABCDEF";
	ptr->crgb = malloc(sizeof(char) * 9);
	if (!ptr->crgb)
		return (printf("problem when alloc rgb\n"), -1);
	while (ptr->utils->ceiling_color[i])
	{
		printf("voici toute mes donnees %s\n", ptr->utils->ceiling_color[i]);
		i++;
	}
	ptr->crgb[0] = '0';
	ptr->crgb[1] = 'x';
	i = 0;
	index_base = 2;
	while (ptr->utils->ceiling_color[i])
	{
		printf("voici mon i %d\n", i);
		printf("voici mon nb %d\n", ft_atoi(ptr->utils->ceiling_color[i]));
		nb1 = ft_atoi(ptr->utils->ceiling_color[i]);
		nb1 = nb1 / 16;
		printf("voici mon nb avec virgule %f\n", nb1);
		nb2 = nb1 - (int)nb1;
		nb2 = nb2 * 16;
		printf("voici mon nb2 %f\n", nb2);
		ptr->crgb[index_base] = base[(int)nb1];
		index_base++;
		ptr->crgb[index_base] = base[(int)nb2];
		i++;
		index_base++;
	}
	ptr->crgb[index_base] = '\0';
	printf("voici mon rgb final %s et voici ce qui passe avec atoi %d\n", ptr->crgb, ft_atoi(ptr->crgb));
	test = ft_atoi(ptr->utils->ceiling_color[0]) * 65536 + ft_atoi(ptr->utils->ceiling_color[1]) * 256 + ft_atoi(ptr->utils->ceiling_color[2]);
	printf("voici mon test %d\n", test);
	return (0);
}
*/