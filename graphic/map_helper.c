/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:05:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/29 09:04:41 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_pov_rotation(t_math *ma, int input)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = ma->dirx;
	// printf("voici mon code %d======\n", input);
	// printf("maintenant voici mes anciennes valeurs\n dirx %f diry %f\n", ma->dirx, ma->diry);
	// printf("planex %f planey %f\n", ma->planex, ma->planey);
	if (input == 5) // droite
	{
		ma->dirx = ma->dirx * cos(-0.2) - ma->diry * sin(-0.2);
		ma->diry = oldDirX * sin(-0.2) + ma->diry * cos(-0.2);
		oldPlaneX = ma->planex;
		ma->planex = ma->planex * cos(-0.2) - ma->planey * sin(-0.2);
		ma->planey = oldPlaneX * sin(-0.2) + ma->planey * cos(-0.2);
	}
	else if (input == 7) // gauche
	{
		ma->dirx = ma->dirx * cos(0.2) - ma->diry * sin(0.2);
		ma->diry = oldDirX * sin(0.2) + ma->diry * cos(0.2);
		oldPlaneX = ma->planex;
		ma->planex = ma->planex * cos(0.2) - ma->planey * sin(0.2);
		ma->planey = oldPlaneX * sin(0.2) + ma->planey * cos(0.2);
	}
	// printf("maintenant voici mes Nouveau valeurs\n dirx %f diry %f\n", ma->dirx, ma->diry);
	// printf("planex %f planey %f\n======\n", ma->planex, ma->planey);
}

void	player_movement_map(t_math *ma, int input, t_info *ptr)
{
	double	x;
	double	y;

	y = ma->posy;
	x = ma->posx;
	// printf("====NOUVELLE INPUT====\n");
	// printf("voici mes valeurs au debut de ma fonction %f %f\n", x, y);
	// printf("voici input %d\n", ptr->p_mov);
	if (input == 1 || input == 3)
		player_movement_front(x, y, ptr, ma);
	else
		player_movement_side(x, y, ptr, ma);
	// maintenant juste avant d'actualiser les positions, je dois faire en sorte
	// que je sorte proprement pour faire comprendre que j'ai toucher un mur
}

void	player_movement_front(double x, double y, t_info *ptr, t_math *ma)
{
	int		i;
	int		vertical_len;
	int		horizontal_len;

	// printf("voici mes valeurs juste avant le debut des calculs %f %f\n", x, y);
	if (ptr->p_mov == 1) // devant
	{
		if (x + 0.2 < 0)
			return ; // peut etre voir si c'est a utiliser
		x += ma->dirx * 0.2;
		y += ma->diry * 0.2;
	}
	else if (ptr->p_mov == 3)// bas
	{
		if (x - 0.2 < 0)
			return ;
		x -= ma->dirx * 0.2;
		y -= ma->diry * 0.2;
	}
	// d'abord calculer la len voir si ca segfault, ensuite verif si c'est un mur dans
	// la map
	i = len_map(ptr->utils->map[(int)y]);
	vertical_len = len_db_tab(ptr->utils->map);
	horizontal_len = ft_strlen(ptr->utils->map[(int)y]) - 1;
	// printf("voici mes valeurs pour verif les murs %f %f\n", x, y);
	// printf("VOICI MA LEN DANS MES MOUVEMENT %d et voici ma len vertical %d et horizon %d\n", i, vertical_len, horizontal_len);
	if (y < 1 || x < 1 || vertical_len <= (int)y
		|| horizontal_len <= (int)x)
	{
		// printf("JE SUIS SORTIS\n");
		// printf("DONC I = %d ET Y = %f\n", i, y);
		// exit(1);
		return ;
	}
	if (ptr->utils->map[(int)y][(int)x] == '1')
		return ;
	ma->posy = y;
	ma->posx = x;
	// printf("nouvelle position %f %f\n", ma->posx, ma->posy);
}

void	player_movement_side(double x, double y, t_info *ptr, t_math *ma)
{
	int		i;
	int		vertical_len;
	int		horizontal_len;

	if (ptr->p_mov == 2) // gauche
	{
		if (y - 0.2 < 0)
			return ;
		x += ma->dirx * 0.2;
		y += ma->diry * 0.2;
	}
	else if (ptr->p_mov == 4) // droite
	{
		if (y + 0.2 < 0)
			return ;
		x += ma->dirx * 0.2;
		y -= ma->diry * 0.2;
	}
	i = len_map(ptr->utils->map[(int)y]);
	vertical_len = len_db_tab(ptr->utils->map);
	horizontal_len = ft_strlen(ptr->utils->map[(int)y]) - 1;
	// printf("VOICI MA LEN DANS MES MOUVEMENT %d et voici ma len vertical %d\n", i, vertical_len);
	if (y < 1 || x < 1 || vertical_len <= (int)y
		|| horizontal_len <= (int)x)
	{
		// printf("JE SUIS SORTIS\n");
		// printf("DONC I = %d ET Y = %f\n", i, y);
		// exit(1);
		// printf("je passe par ici\n");
		return ;
	}
	if (ptr->utils->map[(int)y][(int)x] == '1')
		return ;
	ma->posy = y;
	ma->posx = x;
	// printf("nouvelle position %f %f\n", ma->posx, ma->posy);
}

void	found_pos_player_minimap(t_info *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (ptr->utils->map[i])
	{
		j = 0;
		while (ptr->utils->map[i][j])
		{
			if (ptr->utils->map[i][j] == 'N' || ptr->utils->map[i][j] == 'S'
				|| ptr->utils->map[i][j] == 'W' || ptr->utils->map[i][j] == 'E')
			{
				ptr->ma->posx = WINDOW_WIDTH - 50;
				ptr->ma->posy = 50;
			}
			j++;
		}
		i++;
	}
}

/*
void	player_movement(t_math *ma, int input, t_info *ptr)
{
	int	x;
	int	y;
	int	tmp;

	y = ma->posy;
	x = ma->posx;
	// printf("voici input %d et voici dirx %f t diry %f\n", input, ma->dirx, ma->diry);
	if (input == 1) // devant
	{
		tmp = (int)ma->posx;
		if(ptr->utils->map[tmp + (int)ma->dirx * 1][(int)ma->posy] == 0) 
			ma->posx += ma->dirx * 1;
		if(ptr->utils->map[(int)ma->posx][(int)ma->posy + (int)ma->diry * 1] == 0) 
			ma->posy += ma->diry * 1;
	}
	// else if (input == 2) // gauche
		// ma->posx -= ma->dirx - 0.5;
	else if (input == 3) // bas
	{
		tmp = (int)ma->posx;
		if(ptr->utils->map[tmp - (int)ma->dirx * 1][(int)ma->posy] == 0) 
			ma->posx -= ma->dirx * 1;
		if(ptr->utils->map[(int)ma->posx][(int)ma->posy - (int)ma->diry * 1] == 0) 
			ma->posy -= ma->diry * 1;
	}
	// else if (input == 4) // droite
		// ma->posx -= ma->dirx - 0.5;
	// ptr->ma->posy = y;
	// ptr->ma->posx = x;
}
*/

/* code du 6 avril juste minimap
void	player_pov_rotation(t_info *ptr, int input)
{
	printf("voici mon code %d\n", input);
	if (input == 5) // gauche
	{
		ptr->pa -= 0.1;
		if (ptr->pa < 0)
			ptr->pa += 2 * PI;
		ptr->ma->posx = cos(ptr->pa) * 5;
		ptr->ma->posy = sin(ptr->pa) * 5;
	}
	else if (input == 7) // droite
	{
		ptr->pa += 0.1;
		if (ptr->pa > 2 * PI)
			ptr->pa -= 2 * PI;
		ptr->ma->posx = cos(ptr->pa) * 5;
		ptr->ma->posy = sin(ptr->pa) * 5;
	}
	printf("pdx = %f et pdy = %f\n", ptr->ma->posx, ptr->ma->posy);
	// else if (input == 6) // haut
	// {
	// 	ptr->ma->posx += ptr->ma->posx;
	// 	ptr->ma->posy += ptr->ma->posy;
	// }
	// else if (input == 8) // bas
	// {
	// 	ptr->ma->posx -= ptr->ma->posx;
	// 	ptr->ma->posy -= ptr->ma->posy;
	// }
}

void	wall_creation_minimap(t_info *ptr)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = ((y = 0));
	while (ptr->utils->map[i])
	{
		j = 0;
		x = 0;
		while (ptr->utils->map[i][j])
		{
			if (ptr->utils->map[i][j] == '1')
			{
				printf("start %d end %d\n", ptr->ma->draw_start, ptr->ma->draw_end);
				printf("voici windows height %d\n", ptr->ma->line_Height);
				render_rect(&ptr->img, (t_rect){ptr->ma->draw_start, ptr->ma->draw_end,
				ptr->ma->draw_start, ptr->ma->draw_end, RED_PIXEL});
			}
			x = x + 100;
			j++;
		}
		y = y + 120;
		i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
}

void	player_movement_minimap(t_info *ptr, int input)
{
	int	x;
	int	y;

	y = ptr->ma->posy;
	x = ptr->ma->posx;
	if (input == 1)
		y = y -1;
	else if (input == 2)
		x = x - 1;
	else if (input == 3)
		y = y + 1;
	else if (input == 4)
		x = x + 1;
	ptr->ma->posy = y;
	ptr->ma->posx = x;
}

void	wall_creation_minimap(t_info *ptr)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = ((y = 0));
	while (ptr->utils->map[i])
	{
		j = 0;
		x = WINDOW_WIDTH - 100;
		while (ptr->utils->map[i][j])
		{
			if (ptr->utils->map[i][j] == '1')
			{
				render_rect(&ptr->img, (t_rect){x, y,
				10, 10, RED_PIXEL});
			}
			x = x + 10;
			j++;
		}
		y = y + 10;
		i++;
	}
}

void	found_pos_player_minimap(t_info *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (ptr->utils->map[i])
	{
		j = 0;
		while (ptr->utils->map[i][j])
		{
			if (ptr->utils->map[i][j] == 'N' || ptr->utils->map[i][j] == 'S'
				|| ptr->utils->map[i][j] == 'W' || ptr->utils->map[i][j] == 'E')
			{
				ptr->ma->posx = WINDOW_WIDTH - 50;
				ptr->ma->posy = 50;
			}
			j++;
		}
		i++;
	}
}

void	wall_creation_map(t_info *ptr)
// {
// 	t_math	*ma;
// 	t_line	*line;
// 	double	wall_x;
// 	int		scale;

// 	ma = ptr->ma;
// 	if (ma->side == WEST || ma->side == EAST)
// 		wall_x = ma->posy + ma->perpwalldist * ma->raydiry;
// 	else
// 		wall_x = ma->posx + ma->perpwalldist * ma->raydirx;
// 	wall_x -= floor(wall_x);
// 	line->x = ma->mapx;
// 	if (ptr->utils->map[ma->mapy][ma->mapx] == '1')
// 		paint_texture_line(ptr, ma, line);
// 	line->yb = 0;
// 	line->yf = ma->draw_start;
// 	paint_line(ma, line, ptr->crgb);
// 	line->yb = WINDOW_HEIGHT;
// 	line->yf = ma->draw_end;
// 	paint_line(ptr, ma, ptr->frgb);
// 	texture_on_img(ptr, ma, line, texture);
// 	// scale = line->y - (WINDOW_HEIGHT) / 2 + ma->line_Height;
// 	// scale = line->y * texture->line_length;
// }

// static void	texture_on_img(t_info *ptr, t_math *ma, t_line *line, t_image *texture)
// {
// 	int		scale;
// // peut etre changer le 50 pour la cam height
// 	scale = line->y * line_lenght - (WINDOW_HEIGHT * 50) * line_lenght / 2
// 		+ ma->line_Height * line_lenght / 2;
// 	line->tex_y = ((scale * texture->height) / ma->line_Height) / texture->line_lenght;
// 	ptr->mlx_img->data[line->y * line_lenght + line->x * bbp / 8] = texture->data[line->tex_y
// 		* texture->line_lenght + line->tex_x * (texture->bbp / 8)];
// 	ptr->mlx_img->data[line->y * ptr->mlx_img->line_lenght + line->x
// 		(ptr->mlx_img->bbp / 8) + 1] = texture->data[line->tex_y * texture->line_lenght
// 		+ line->tex_x * (texture->bbp / 8) + 1];
// 	ptr->mlx_img->data[line->y * ]
	
// }

void	wall_creation_minimap(t_info *ptr)
{
	printf("start %d end %d\n", ptr->ma->draw_start, ptr->ma->draw_end);
	// render_background(&ptr->img, BLACK_PIXEL);
	printf("voici windows height %d\n", ptr->ma->line_Height);
	render_rect(&ptr->img, (t_rect){ptr->ma->draw_start, ptr->ma->draw_end,
				100, 100, RED_PIXEL});
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
}

void	wall_creation_minimap(t_info *ptr)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = ((y = 0));
	while (ptr->utils->map[i])
	{
		j = 0;
		x = 0;
		while (ptr->utils->map[i][j])
		{
			if (ptr->utils->map[i][j] == '1')
			{
				render_rect(&ptr->img, (t_rect){x, y,
				100, 120, WHITE_PIXEL});
			}
			x = x + 100;
			j++;
		}
		y = y + 120;
		i++;
	}
}

void	wall_creation_minimap(t_info *ptr)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = ((y = 0));
	while (ptr->utils->map[i])
	{
		j = 0;
		x = 0;
		while (ptr->utils->map[i][j])
		{
			if (ptr->utils->map[i][j] == '1')
			{
				printf("start %d end %d\n", ptr->ma->draw_start, ptr->ma->draw_end);
				printf("voici windows height %d\n", ptr->ma->line_Height);
				render_rect(&ptr->img, (t_rect){j, i,
				ptr->ma->draw_start, ptr->ma->draw_end, RED_PIXEL});
			}
			x = x + 100;
			j++;
		}
		y = y + 120;
		i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
}

*/