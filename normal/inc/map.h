/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:37:59 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/02 17:35:51 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "engine.h"

# define MAX_SPRITES 6

enum	e_cell
{
	cell_air = 0,
	cell_wall = 1,
	cell_door = 254,
	cell_void = 255,
	cell_zone = 2048
};

typedef unsigned int	t_cell;
typedef struct s_map	t_map;

t_map	map_create(t_v2i const size);
void	map_destroy(t_engine *const eng, t_map *const map);

t_cell	map_get(t_map const *const map, t_v2i const pos);
t_v2i	map_size(t_map const *const map);

void	map_set(t_map *const map, t_v2i const pos, t_cell const cell);
void	map_fill(t_map *const map, t_v2i pos1, t_v2i pos2, t_cell const cell);

int		map_iterate(
			t_data *const game,
			t_map *const map,
			int (*func)(
	t_data *const game,t_map *const map, t_v2i const pos));

struct s_map
{
	t_cell		**data;
	t_v2i		size;
	t_v2f		spawn;
	t_sprite	*sprites[4];
	t_color		sky_color;
	t_color		ground_color;
};

#endif