/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** surround by enemies
*/

#include "lemipc.h"

void can_kill(map_t *shared, player_t *play, int *save)
{
	int nb;

	for (int end = 0; end < 8; end++) {
		for (int lap = 0; lap < 8; lap++) {
			if (save[end] == 0)
				continue;
			nb = save[end];
			if (nb == save[lap] && end != lap) {
				shared->map[play->pos_x][play->pos_y] = 0;
				return;
			}
		}
	}
}

void check_surround(map_t *shared, player_t *play)
{
	int save[8] = {shared->map[play->pos_x - 1][play->pos_y - 1]
			, shared->map[play->pos_x - 1][play->pos_y]
			, shared->map[play->pos_x - 1][play->pos_y + 1]
			, shared->map[play->pos_x][play->pos_y - 1]
			, shared->map[play->pos_x][play->pos_y + 1]
			, shared->map[play->pos_x + 1][play->pos_y - 1]
			, shared->map[play->pos_x + 1][play->pos_y]
			, shared->map[play->pos_x + 1][play->pos_y + 1]};

	can_kill(shared, play, save);
}
