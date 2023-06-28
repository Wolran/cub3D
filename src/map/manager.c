/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:48:47 by vmuller           #+#    #+#             */
/*   Updated: 2023/06/27 17:43:40 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	map_create(t_v3i const size)
{
	t_map	map;
	t_v3i	pos;

	if (size[x] <= 0 || size[y] <= 0 || size[z] <= 0)
		return ((t_map){0});
	map.data = malloc(sizeof(t_cell **) * size[x]);
	pos[x] = 0;
	while (pos[x] < size[x])
	{
		map.data[pos[x]] = malloc(sizeof(t_cell *) * size[y]);
		pos[y] = 0;
		while (pos[y] < size[y])
		{
			map.data[pos[x]][pos[y]] = malloc(sizeof(t_cell) * size[z]);
			ft_memset(map.data[pos[x]][pos[y]], 0, sizeof(t_cell) * size[z]);
			pos[y]++;
		}
		pos[x]++;
	}
	map.size = size;
	ft_memset(map.sprites, 0, sizeof(t_sprite *) * 6);
	return (map);
}

void	map_destroy(t_engine *const eng, t_map *const map)
{
	t_v3i	pos;

	pos[x] = 0;
	while (pos[x] < map->size[x])
	{
		pos[y] = 0;
		while (pos[y] < map->size[y])
		{
			free(map->data[pos[x]][pos[y]]);
			pos[y]++;
		}
		free(map->data[pos[x]]);
		pos[x]++;
	}
	free(map->data);
	map->size = (t_v3i){0, 0, 0};
	ft_destroy_sprite(eng, map->sprites[0]);
	ft_destroy_sprite(eng, map->sprites[1]);
	ft_destroy_sprite(eng, map->sprites[2]);
	ft_destroy_sprite(eng, map->sprites[3]);
	ft_destroy_sprite(eng, map->sprites[4]);
	ft_destroy_sprite(eng, map->sprites[5]);
}
