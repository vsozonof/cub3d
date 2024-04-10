/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:40:16 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/10 13:37:10 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// x gauche a droite
// y haut en bas

int	found_player_pos_x(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'N' || argv[i][j] == 'S'
				|| argv[i][j] == 'W' || argv[i][j] == 'E')
			{
				return (j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	found_player_pos_y(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'N' || argv[i][j] == 'S'
				|| argv[i][j] == 'W' || argv[i][j] == 'E')
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	found_player_type(t_utils *utils)
{
	int i;
	int	j;

	i = 0;
	while (utils->map[i])
	{
		j = 0;
		while (utils->map[i][j])
		{
			if (utils->map[i][j] == 'N')
				return (1);
			else if (utils->map[i][j] == 'S')
				return (2);
			else if (utils->map[i][j] == 'E')
				return (3);
			else if (utils->map[i][j] == 'W')
				return (4);
			j++;
		}
		i++;
	}
	return (0);
}

void	player_creation_minimap(t_info *ptr)
{
	// printf("voici pdx et pdy %f %f\n", ptr->ma->posx, ptr->ma->posy);
	render_rect(&ptr->img, (t_rect){ptr->ma->posx, ptr->ma->posy,
		ptr->ma->posx, ptr->ma->posy, GREEN_PIXEL});
	make_ray(ptr, ptr->ma->posx, ptr->ma->posy);
}

//nouvelle idee technique prendre 1/10 de mon point final et additionner a chaque
// tour de boucle mon point actuel

void	make_ray(t_info *ptr, int fix, int fiy)
{
	float	bgx;
	float	bgy;

	bgx = ptr->ma->posx;
	bgy = ptr->ma->posy;
	// printf("voici mes valeurs au debut\n");
	// printf("")
	// printf("donc dans ma fonction de rayon j'ai :\n");
	// printf("bgx %d et bgy %d\n", bgx, bgy);
	while (bgx != fix && bgy != fiy)
	{
		render_rect(&ptr->img, (t_rect){bgx, bgy,
		5, 5, RED_PIXEL});
		bgx++;
		bgy++;
		if (bgx > WINDOW_WIDTH || bgy < 0)
			break;
	}
}

// tracer une ligne de 2 pixels du point x et y au point x' et y'

// arriver fix et fiy mes points qui voyagent sont bgx et bgy

// void	make_ray(t_info *ptr, int fix, int fiy)
// {
// 	int	bgx;
// 	int	bgy;

// 	bgx = ptr->ma->posx;
// 	bgy = ptr->ma->posy;
// 	while (bgx != fix && bgy != fiy)
// 	{
// 		render_rect(&ptr->img, (t_rect){bgx, bgy,
// 		1, 1, YELLOW_PIXEL});
// 		if (fix > bgx)
// 			bgx++;
// 		else
// 			bgx--;
// 		if (fiy > bgy)
// 			bgy++;
// 		else
// 			bgy--;
// 		// printf("voici bgy %d et bgx %d\n", bgy, bgx);
// 		// printf("voici fiy %d et fix %d\n", fiy, fix);
// 		if (bgx > WINDOW_WIDTH || bgy < 0)
// 			break;
// 	}
// } // tracer une ligne de 2 pixels du point x et y au point x' et y'

/* code du 6 avril juste minimap
int	found_player_pos_x(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'N' || argv[i][j] == 'S'
				|| argv[i][j] == 'W' || argv[i][j] == 'E')
			{
				return (j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	found_player_pos_y(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'N' || argv[i][j] == 'S'
				|| argv[i][j] == 'W' || argv[i][j] == 'E')
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	found_player_type(t_utils *utils)
{
	int i;
	int	j;

	i = 0;
	while (utils->map[i])
	{
		j = 0;
		while (utils->map[i][j])
		{
			if (utils->map[i][j] == 'N')
				return (1);
			else if (utils->map[i][j] == 'S')
				return (2);
			else if (utils->map[i][j] == 'E')
				return (3);
			else if (utils->map[i][j] == 'W')
				return (4);
			j++;
		}
		i++;
	}
	return (0);
}

void	player_creation_minimap(t_info *ptr)
{
	// printf("voici pdx et pdy %f %f\n", ptr->ma->posx, ptr->ma->posy);
	render_rect(&ptr->img, (t_rect){ptr->ma->posx, ptr->ma->posy,
		8, 8, YELLOW_PIXEL});
	make_ray(ptr, ptr->ma->posx, ptr->ma->posy);
}
//nouvelle idee technique prendre 1/10 de mon point final et additionner a chaque
// tour de boucle mon point actuel
void	make_ray(t_info *ptr, int fix, int fiy)
{
	float	bgx;
	float	bgy;

	bgx = ptr->ma->posx;
	bgy = ptr->ma->posy;
	// printf("voici mes valeurs au debut\n");
	// printf("")
	// printf("donc dans ma fonction de rayon j'ai :\n");
	// printf("bgx %d et bgy %d\n", bgx, bgy);
	while (bgx != fix && bgy != fiy)
	{
		render_rect(&ptr->img, (t_rect){bgx, bgy,
		1, 1, YELLOW_PIXEL});
		bgx++;
		bgy++;
		if (bgx > WINDOW_WIDTH || bgy < 0)
			break;
	}
} // tracer une ligne de 2 pixels du point x et y au point x' et y' 
// arriver fix et fiy mes points qui voyagent sont bgx et bgy

// void	make_ray(t_info *ptr, int fix, int fiy)
// {
// 	int	bgx;
// 	int	bgy;

// 	bgx = ptr->ma->posx;
// 	bgy = ptr->ma->posy;
// 	while (bgx != fix && bgy != fiy)
// 	{
// 		render_rect(&ptr->img, (t_rect){bgx, bgy,
// 		1, 1, YELLOW_PIXEL});
// 		if (fix > bgx)
// 			bgx++;
// 		else
// 			bgx--;
// 		if (fiy > bgy)
// 			bgy++;
// 		else
// 			bgy--;
// 		// printf("voici bgy %d et bgx %d\n", bgy, bgx);
// 		// printf("voici fiy %d et fix %d\n", fiy, fix);
// 		if (bgx > WINDOW_WIDTH || bgy < 0)
// 			break;
// 	}
// } // tracer une ligne de 2 pixels du point x et y au point x' et y'

*/