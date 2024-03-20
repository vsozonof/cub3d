/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:16:22 by tpotilli          #+#    #+#             */
/*   Updated: 2024/03/20 14:09:08 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

// void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char    *pixel;
// 	int		i;

// 	i = img->bpp - 8;
//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	while (i >= 0)
// 	{
// 		/* big endian, MSB is the leftmost bit */
// 		if (img->endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		/* little endian, LSB is the leftmost bit */
// 		else
// 			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
// 		i -= 8;
// 	}
// }

// /* The x and y coordinates of the rect corresponds to its upper left corner. */

// int render_rect(t_img *img, t_rect rect)
// {
// 	int	i;
// 	int j;

// 	i = rect.y;
// 	while (i < rect.y + rect.height)
// 	{
// 		j = rect.x;
// 		while (j < rect.x + rect.width)
// 			img_pix_put(img, j++, i, rect.color);
// 		++i;
// 	}
// 	return (0);
// }

// void	render_background(t_img *img, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WINDOW_HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WINDOW_WIDTH)
// 		{
// 			img_pix_put(img, j++, i, color);
// 		}
// 		++i;
// 	}
// }

// int	handle_keypress(int keysym, t_game *game)
// {
// 	if (keysym == XK_Escape)
// 	{
// 		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
// 		game->win_ptr = NULL;
// 	}
// 	return (0);
// }

// int	render(t_game *game)
// {
// 	if (game->win_ptr == NULL)
// 		return (1);
// 	render_background(&game->img, WHITE_PIXEL);
// 	render_rect(&game->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
// 	render_rect(&game->img, (t_rect){0, 0, 100, 100, RED_PIXEL});

// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, 0, 0);

// 	return (0);
// }

// int	exec_ta_vue(void)
// {
// 	t_game	game;

// 	game.mlx_ptr = mlx_init();
// 	if (game.mlx_ptr == NULL)
// 		return (MLX_ERROR);
// 	game.win_ptr = mlx_new_window(game.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
// 	if (game.win_ptr == NULL)
// 	{
// 		free(game.win_ptr);
// 		return (MLX_ERROR);
// 	}

// 	/* Setup hooks */ 
// 	game.img.mlx_img = mlx_new_image(game.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	
// 	game.img.addr = mlx_get_data_addr(game.img.mlx_img, &game.img.bpp,
// 			&game.img.line_len, &game.img.endian);

// 	mlx_loop_hook(game.mlx_ptr, &render, &game);
// 	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &game);

// 	mlx_loop(game.mlx_ptr);

// 	/* we will exit the loop if there's no window left, and execute this code */
// 	mlx_destroy_image(game.mlx_ptr, game.img.mlx_img);
// 	mlx_destroy_display(game.mlx_ptr);
// 	free(game.mlx_ptr);
// }
