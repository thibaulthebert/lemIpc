/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** move randomly
*/

#include "lemipc.h"

void move_randomly(map_t *shared, player_t *play, int x, int y)
{
	int save = shared->map[play->pos_x][play->pos_y];

	if (shared->map[play->pos_x + x][play->pos_y + y] == 0) {
		shared->map[play->pos_x + x][play->pos_y + y] = save;
		shared->map[play->pos_x][play->pos_y] = 0;
		play->pos_x += x;
		play->pos_y += y;
	}
}

void	check_random(int side, map_t *shared, player_t *play)
{
	switch (side) {
		case 1:
			move_randomly(shared, play, -1, 0);
			break;
		case 2:
			move_randomly(shared, play, 0, 1);
			break;
		case 3:
			move_randomly(shared, play, 1, 0);
			break;
		case 4:
			move_randomly(shared, play, 0, -1);
			break;
		}
}

int choose_direction(map_t *shared, player_t *play)
{
	int side;
	if (lock(play->sem_id) == 84)
		return (84);
	for (int i = 0; i < 2; i++) {
		srand(time(NULL));
		side = rand() % 5;
		check_random(side, shared, play);
	}
	if (unlock(play->sem_id) == 84)
		return (84);
	return (0);
}
