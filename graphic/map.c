/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:59:18 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/07 15:02:35 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	make_map(t_info *ptr, int i)//les position du joueur doit deprendre de sa pos de depart
{
	(void)i;
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
	return (0);
}

int	window_creation(t_data *data, t_utils *utils)
{
	t_info	ptr;
	t_math	ma;
	int		i;
	(void)data;

	i = 0;
	ptr.utils = utils;
	if (init_struct(&ptr, utils, &ma) == 1)
		return (1);
	ptr.img.mlx_img = mlx_new_image(ptr.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ptr = initialize_tex(ptr);
	ptr.img.addr = mlx_get_data_addr(ptr.img.mlx_img, &ptr.img.bpp,
			&ptr.img.line_len, &ptr.img.endian);
	mlx_loop_hook(ptr.mlx, &render, &ptr);
	mlx_hook(ptr.win, 17, 0, mouse_hook, &ptr);
	mlx_key_hook(ptr.win, get_key_hook, &ptr);
	mlx_loop(ptr.mlx);
	mlx_destroy_image(ptr.mlx, ptr.img.mlx_img);
	mlx_destroy_display(ptr.mlx);
	free(ptr.mlx);
	return (0);
}

void	print_img_simulation(t_info *ptr, int x, int j, t_math *ma)
{
	int		c;

	c = 0;
	// printf("\n===voici mon x %d et mon debut j %d\n", x, j);
	// printf("voici mon draw start %d\n", ma->draw_start);
	if (j < ptr->ma->draw_start)
		while (j++ < ptr->ma->draw_start)
			render_rect(&ptr->img, (t_rect){x, j, 1, 1, ptr->crgb});
	// printf("voici mon j avant mur %d\n", j);
	// printf("voici mon draw end %d\n", ma->draw_end);
	if (j < ma->draw_end)
	{
		j = verify_texture(ptr, 0, j, x);
	}
	// printf("voici mon fin j %d\n", j);
	if (j > ma->draw_end)
		while (j++ < WINDOW_HEIGHT)
			img_pix_put(&ptr->img, x, j, ptr->frgb);
}

// void	image_helper(t_info *ptr, int x, int j, t_math* ma)
// {
// 	(void)x;
// 	(void)j;
// 	(void)ptr;
// 	double	step;
// 	double	texpos;
// 	int		texy;
// 	int		y;
// 	int		color;

// 	step = 1 * tex_height / ma->line_Height;
// 	texpos = (ma->draw_start - WINDOW_HEIGHT / 2 + ma->line_Height / 2) * step;
// 	y = ma->draw_start;
// 	while (y < ma->draw_end)
// 	{
// 		texy = (int)texpos  + (texhight - 1);
// 		texpos += step;
// 		color = texture[texnum][texheight * texy + texx];
// 		y++;
// 	}
// }

// void *get_image(t_info *ptr, t_math *ma)
// {
// 	if (ma->raydirx == 1 && ma->side == 0)
// 		return (ptr->img_1); // Est
// 	else if (ma->raydiry == -1 && ma->side == 0)
// 		return (ptr->img_2); // West
// 	else if (ma->raydiry == 1 && ma->side == 1)
// 		return (ptr->img_3); // North
// 	else if (ma->raydiry == -1 && ma->side == 0)
// 		return (ptr->img_4); // South
// 	// printf("voici une texture %s\n", ptr->img_1);
// 	return (NULL);
// }

// texn est utile pour savoir a quel texture j'ai a faire
// recup la taille de mon image
//utiliser token pour savoir de quel image on parle

static	int	ft_texx(t_info *ptr, int texx, int texn)
{
	if (ptr->ma->side == 0 && ptr->ma->raydirx < 0)
		texx = ptr->tex[texn].w - texx - 1;
	if (ptr->ma->side == 0 && ptr->ma->raydirx >= 0)
		texx = texx - ptr->tex[texn].w - 1;
	if (ptr->ma->side == 1 && ptr->ma->raydiry >= 0)
		texx = ptr->tex[texn].w - texx - 1;
    return (texx);
}

int	verify_texture(t_info *ptr, int texn, int y, int x)
{
	int			texx;
	int			texy;
	double		step;

	if (ptr->ma->side == 0)
		ptr->ma->wlx = ptr->ma->posy + ptr->ma->perpwalldist * ptr->ma->raydiry;
	else
		ptr->ma->wlx = ptr->ma->posx + ptr->ma->perpwalldist * ptr->ma->raydirx;
	ptr->ma->wlx -= floor((ptr->ma->wlx));
	step = 1.0 * ptr->tex[0].h / ptr->ma->line_Height;
	texx = (int)(ptr->ma->wlx * (double)ptr->tex[texn].w);
	texx = ft_texx(ptr, texx, texn);
	ptr->ma->texpos = (ptr->ma->draw_start - WINDOW_HEIGHT / 2 + ptr->ma->line_Height / 2)
		 * step;
	while (y <= ptr->ma->draw_end)
	{
		// printf("voici mon ptr %d\n", ptr->tex[texn].addr[texy * ptr->tex[texn].line_len / 4 + texx]);
		texy = (int)ptr->ma->texpos & (ptr->tex[texn].h - 1);
		ptr->ma->texpos += step;
		if (y < (WINDOW_HEIGHT - 1) && ptr->ma->raydirx < (WINDOW_WIDTH - 1))
			ptr->img.addr[y * ptr->img.line_len / 4 + x] = \
				ptr->tex[texn].addr[texy * ptr->tex[texn].line_len / 4 + texx];
		y++;
	}
	return (y);
}

// static    int    ft_texx(t_vars *vars, int texx, int texn)
// {
//     if (vars->ray.side == 0 && vars->ray.raydirx < 0)
//         texx = vars->wall[texn].w - texx - 1;
//     if (vars->ray.side == 0 && vars->ray.raydirx >= 0)
//         texx = texx - vars->wall[texn].w - 1;
//     if (vars->ray.side == 1 && vars->ray.raydiry >= 0)
//         texx = vars->wall[texn].w - texx - 1;
	// wall.addr = \
        // (int *)mlx_get_data_addr(wall.img, &wall.bpp, &wall.llen, &wall.endian);
    // if (wall.h != 64 || wall.w != 64)
        // ft_free_mlx(0, vars);
    // vars->wall[i] = wall;
    // return (texx);
// }

// void    ft_test_texture(t_vars *vars, int texn, int y)
// {
//     int        texx;
//     int        texy;
//     double    step;

//     if (vars->ray.side == 0)
//         vars->wlx = vars->ray.posy + vars->ray.perpwalldist * vars->ray.raydiry;
//     else
//         vars->wlx = vars->ray.posx + vars->ray.perpwalldist * vars->ray.raydirx;
//     vars->wlx -= floor((vars->wlx));
//     step = 1.0 * vars->wall[0].h / vars->ray.lineheight;
//     texx = (int)(vars->wlx * (double)vars->wall[texn].w);
//     texx = ft_texx(vars, texx, texn);
//     vars->texpos = \
//     (vars->ray.drawstart - vars->sizey / 2 + vars->ray.lineheight / 2) * step;
//     while (++y <= vars->ray.drawend)
//     {
//         texy = (int)vars->texpos & (vars->wall[texn].h - 1);
//         vars->texpos += step;
//         if (y < (vars->sizey - 1) && vars->ray.x < (vars->sizex - 1))
//             vars->img.addr[y * vars->img.llen / 4 + vars->ray.x] = \
//             vars->wall[texn].addr[texy * vars->wall[texn].llen / 4 + texx];
//     }
// }

/*
void	print_img_simulation(t_info *ptr, int x, int j, t_math *ma)
{
	int		c;
	void	*tmp;

	c = 0;
	// printf("voici endian %d\n", ptr->img.endian);
	// printf("voici line_len %d\n", ptr->img.line_len);
	// printf("voici bpp %d\n", ptr->img.bpp);
	if (j < ptr->ma->draw_start)
		while (j++ < ptr->ma->draw_start)
			render_rect(&ptr->img, (t_rect){x, j, 1, 1, ptr->crgb});
	if (j < ma->draw_end)
	{
		while (j++ < ma->draw_end)
		{
			tmp = ptr->img.mlx_img;
			// envoyer l'image concerne: suivant si je pointe vers le Nord Sud Est ou West
			// il faut que je trouve comment avoir la couleur du pixel de l'image
			// parcourir l'image au meme coordonnee que ma fenetre puis recuperer
			// mon pixel
			// ptr->img.mlx_img = get_image(ptr, ma);
			j = verify_texture(ptr, 1, j, x);
			// img_pix_put(&ptr->img, x, j, c++);
			ptr->img.mlx_img = tmp;
		}
	}
	if (j > ma->draw_end)
		while (j++ < WINDOW_HEIGHT)
			img_pix_put(&ptr->img, x, j, ptr->frgb);
}
*/