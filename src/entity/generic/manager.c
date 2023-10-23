/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:05:41 by alde-fre          #+#    #+#             */
/*   Updated: 2023/10/13 11:26:11 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"

static void	_entity_update(
				t_entity *const self,
				t_data *const game,
				float const dt)
{
	(void)self;
	(void)game;
	(void)dt;
}

static void	_entity_display(t_entity *const self, t_data *const game)
{
	(void)self;
	(void)game;
}

static void	_entity_destroy(t_entity *const self, t_data *const game)
{
	(void)self;
	(void)game;
}

t_entity	*entity_add(t_data *const game, t_v3f const pos)
{
	t_entity	*ent;

	if (vector_resize(&game->entities, game->entities.size + 1))
		return (NULL);
	ent = vector_get(&game->entities, game->entities.size - 1);
	*ent = (t_entity){0};
	ent->update = &_entity_update;
	ent->display = &_entity_display;
	ent->destroy = &_entity_destroy;
	ent->data = NULL;
	ent->pos = pos;
	ent->dir = (t_v3f){0};
	ent->rot = (t_v2f){0};
	ent->mesh = &game->models[0];
	ent->time_alive = 0.0f;
	ent->uuid = 0ul;
	ent->type = ENTITY_GENERIC;
	return (ent);
}