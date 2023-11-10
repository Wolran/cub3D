/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:35:11 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/10 05:36:43 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_UTILS_H
# define GAMEPLAY_UTILS_H

# include "map.h"
# include "aabb.h"
# include "cast_ray.h"

int	ray_hit_box(
		t_map *const map,
		t_v3f const pos,
		t_aabb const *const box,
		float const dist);

#endif