/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:37:59 by vmuller           #+#    #+#             */
/*   Updated: 2023/06/27 14:26:23 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "engine.h"
# include "vec3.h"

# define MAX_SPRITES 6

typedef unsigned char	t_cell;
typedef struct s_map	t_map;

t_map	map_create(t_v3i const size);
void	map_destroy(t_engine *const eng, t_map *const map);

t_cell	map_get(t_map const *const map, t_v3i const pos);
t_v3i	map_size(t_map const *const map);

void	map_set(t_map *const map, t_v3i const pos, t_cell const cell);
void	map_fill(t_map *const map, t_v3i pos1, t_v3i pos2, t_cell const cell);

void	map_render_iso(t_engine *const eng, t_map *const map, t_sprite *const spr);

struct s_map
{
	t_cell		***data;
	t_v3i		size;
	t_v3f		spawn;
	t_sprite	*sprites[6];
	t_color		sky_color;
	t_color		ground_color;
};

#endif