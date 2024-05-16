/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:59:18 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/16 10:39:38 by tpotilli         ###   ########.fr       */
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
	if (j < ptr->ma->draw_start)
		while (j++ < ptr->ma->draw_start)
			render_rect(&ptr->img, (t_rect){x, j, 1, 1, ptr->crgb});
	if (j < ma->draw_end)
	{
		// while (j < ma->draw_end)
		// {
			// img_pix_put(&ptr->img, x, j, YELLOW_PIXEL);
			// j++;
		// }
		j = verify_texture(ptr, 3, j, x);
	}
	while (j++ < WINDOW_HEIGHT)
		img_pix_put(&ptr->img, x, j, ptr->frgb);
}

/*
void	print_img_simulation(t_info *ptr, int x, int j, t_math *ma)
{
	int		c;

	c = 0;
	if (j < ptr->ma->draw_start)
		while (j++ < ptr->ma->draw_start)
			render_rect(&ptr->img, (t_rect){x, j, 1, 1, ptr->crgb});
	if (j < ma->draw_end)
	{
		// while (j < ma->draw_end)
		// {
			// img_pix_put(&ptr->img, x, j, YELLOW_PIXEL);
			// j++;
		// }
		j = verify_texture(ptr, 0, j, x);
	}
	printf("je suis sortis voici mon j %d ainsi que mon x %d et ma taille max %d\n", j, x, WINDOW_HEIGHT);
	while (j++ < WINDOW_HEIGHT)
		img_pix_put(&ptr->img, x, j, ptr->frgb);
	printf("voici mon j a la sortie %d\n", j);
	usleep(500000);
}
*/

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
	step = 1.0 * ptr->tex[texn].h / ptr->ma->line_Height;
	texx = (int)(ptr->ma->wlx * (double)ptr->tex[texn].w);
	texx = ft_texx(ptr, texx, texn);
	ptr->ma->texpos = (ptr->ma->draw_start - WINDOW_HEIGHT / 2 + ptr->ma->line_Height / 2)
		* step;
	while (y <= ptr->ma->draw_end)
	{
		texy = (int)ptr->ma->texpos & (ptr->tex[texn].h - 1);
		ptr->ma->texpos += step;
		if (y < (WINDOW_HEIGHT - 1) && x < (WINDOW_WIDTH - 1))
		{
			// ptr->img.addr[y * ptr->img.line_len / 4 + x] =
			// ptr->tex[texn].addr[texy * ptr->tex[texn].line_len / 4 + texx];
			// printf("la j'ecris dans mon image a la position y = %d x = %d \n", y, x);
			img_pix_put(&ptr->img, x, y, ptr->tex[texn].addr[texy * ptr->tex[texn].line_len / 4 + texx]);
			// printf("voici mon byte per pixel %d\n", ptr->tex->bpp);
		}
		y++;
		// printf("voici ou je dessine %d %d %d\n", y, ptr->img.line_len, x);
		// printf("voici toute mes valeurs \n");
		// printf("texy %d texpos %f\n", texy, ptr->ma->texpos);
		// printf("voici les composantes de mon calcul %d %d %d\n", texy, ptr->tex[texn].line_len, texx);
		// printf("voici le resultat de mon calcul %d\n", texy * ptr->tex[texn].line_len / 4 + texx);
	}
	return (y);
}

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

int	verify_texture(t_info *ptr, int texn, int y, int x)
{
	int			texx;
	int			texy;
	double		step;

	// printf("nouvelle boucle\n\n\n voici mon index %d\n", x);
	if (ptr->ma->side == 0)
	{
		ptr->ma->wlx = ptr->ma->posy + ptr->ma->perpwalldist * ptr->ma->raydiry;
		// printf("voici mon side a 0 donc %f\n", ptr->ma->wlx);
	}
	else
	{
		ptr->ma->wlx = ptr->ma->posx + ptr->ma->perpwalldist * ptr->ma->raydirx;
		// printf("voici mon side autre donc %f\n", ptr->ma->wlx);
	}
	ptr->ma->wlx -= floor((ptr->ma->wlx));
	// printf("voici wlx a la sortie des if %f\n", ptr->ma->wlx);
	step = 1.0 * ptr->tex[0].h / ptr->ma->line_Height;
	// printf("voici step %f\n", step);
	// printf("|voici les differentes composantes de step|\n %d", ptr->tex[texn].h);
	// printf(" et maintenant le calcul total %f \n", 1.0 * ptr->tex[texn].h / ptr->ma->line_Height);
	texx = (int)(ptr->ma->wlx * (double)ptr->tex[texn].w);
	// printf("voici texx avant %f\n", step);
	texx = ft_texx(ptr, texx, texn);
	// printf("voici texx apres fct %f\n", step);
	ptr->ma->texpos = (ptr->ma->draw_start - WINDOW_HEIGHT / 2 + ptr->ma->line_Height / 2)
		* step;
	// printf("voici texpos %f\n", ptr->ma->texpos);
	// printf("maintenant voici les differentes composante de texpos\n\n");
	// printf("start %d line hieght %d et step %f\n", ptr->ma->draw_start, ptr->ma->line_Height, step);
	usleep(50);
	while (++y <= ptr->ma->draw_end)
	{
		// printf("voici mon ptr %d\n", ptr->tex[texn].addr[texy * ptr->tex[texn].line_len / 4 + texx]);
		texy = (int)ptr->ma->texpos & (ptr->tex[texn].h - 1);
		ptr->ma->texpos += step;
		if (y < (WINDOW_HEIGHT - 1) && ptr->ma->raydirx < (WINDOW_WIDTH - 1))
			ptr->img.addr[y * ptr->img.line_len / 4 + x] = \
				ptr->tex[texn].addr[texy * ptr->tex[texn].line_len / 4 + texx];
		// printf("voici le poucentage %d\n", texy * ptr->tex[texn].line_len / 4 + texx);
		// printf("l'endroit ou je vais ecrire dans l'adresse %d\n", y * ptr->img.line_len / 4 + x);
		// render_rect(&ptr->img, (t_rect){x, y, 1, 1, ptr->crgb});
	}
	return (y);
}
*/

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