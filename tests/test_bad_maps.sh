#!/bin/bash

# Script Name: Parsing Tester

valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/color_invalid_rgb.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/color_missing_ceiling_rgb.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/color_missing.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/color_missing_floor_rgb.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/color_none.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/empty.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/file_letter_end.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/filetype_missing
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/filetype_wrong.buc
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/forbidden.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/map_first.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/map_middle.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/map_missing.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/map_only.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/map_too_small.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/player_multiple.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/player_none.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/player_on_edge.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/textures_dir.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/textures_duplicates.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/textures_forbidden.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/textures_invalid.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/textures_missing.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/textures_none.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/textures_not_xpm.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/wall_hole_east.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/wall_hole_north.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/wall_hole_south.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/wall_hole_west.cub
sleep 2
valgrind --leak-check=full --show-leak-kinds=all .././cub3D ../maps/bad/wall_none.cub
sleep 2
