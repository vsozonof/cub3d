/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple_graphic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:58:19 by tpotilli          #+#    #+#             */
/*   Updated: 2024/03/28 10:17:21 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* The x and y coordinates of the rect corresponds to its upper left corner. */

// int render_rect(t_info *info, t_rect rect)
// {
//     int	i;
//     int j;

//     if (info->win_ptr == NULL)
//         return (1);
//     i = rect.y;
//     while (i < rect.y + rect.height)
//     {
//         j = rect.x;
//         while (j < rect.x + rect.width)
//             mlx_pixel_put(info->mlx_ptr, info->win_ptr, j++, i, rect.color);
//         ++i;
//     }
//     return (0);
// }

// int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
//     return (red << 16 | green << 8 | blue);
// }

// int	handle_keypress(int keysym, t_info *info)
// {
//     if (keysym == XK_Escape)
//     {
//         mlx_destroy_window(info->mlx_ptr, info->win_ptr);
//         info->win_ptr = NULL;
//     }
//     return (0);
// }

// int	render(t_info *info)
// {
//     render_rect(info, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
//             100, 100, GREEN_PIXEL});
//     render_rect(info, (t_rect){0, 0, 100, 100, RED_PIXEL});

//     return (0);
// }

// int	exec_tmp(void)
// {
//     t_info	info;

//     info.mlx_ptr = mlx_init();
//     if (info.mlx_ptr == NULL)
//         return (MLX_ERROR);
//     info.win_ptr = mlx_new_window(info.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
//                                 "my window");
//     if (info.win_ptr == NULL)
//     {
//         free(info.win_ptr);
//         return (MLX_ERROR);
//     }

//     /* Setup hooks */ 
//     mlx_loop_hook(info.mlx_ptr, &render, &info);
//     mlx_hook(info.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &info);

//     mlx_loop(info.mlx_ptr);

//     /* we will exit the loop if there's no window left, and execute this code */
//     mlx_destroy_display(info.mlx_ptr);
//     free(info.mlx_ptr);
// 	return (0);
// }