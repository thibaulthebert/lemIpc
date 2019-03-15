/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** ia
*/

#include "lemipc.h"

int display_current_state(map_t *shared, player_t *play)
{
	if (lock(play->sem_id) == 84)
		return (84);
	check_surround(shared, play);
	if (unlock(play->sem_id) == 84)
		return (84);
	if (play->is_father == true) {
		display_map(shared);
		printf("\n");
	}
	sleep(1);
	return (0);
}

int move_vertically(map_t *shared, player_t *play)
{
	int center_x = MAP_WIDTH / 2;

	if (lock(play->sem_id) == 84)
		return (84);
	if (play->pos_x > center_x
	&& shared->map[play->pos_x - 1][play->pos_y] == 0) {
		shared->map[play->pos_x - 1][play->pos_y]
		= shared->map[play->pos_x][play->pos_y];
		shared->map[play->pos_x][play->pos_y] = 0;
		play->pos_x--;
	} else if (play->pos_x < center_x
	&& shared->map[play->pos_x + 1][play->pos_y] == 0) {
		shared->map[play->pos_x + 1][play->pos_y]
		= shared->map[play->pos_x][play->pos_y];
		shared->map[play->pos_x][play->pos_y] = 0;
		play->pos_x++;
	} if (unlock(play->sem_id) == 84
	|| display_current_state(shared, play) == 84)
		return (84);
	return (0);
}

int move_horizontally(map_t *shared, player_t *play)
{
	int center_y = MAP_WIDTH / 2;

	if (lock(play->sem_id) == 84)
		return (84);
	if (play->pos_y > center_y
	&& shared->map[play->pos_x][play->pos_y - 1] == 0) {
		shared->map[play->pos_x][play->pos_y - 1]
		= shared->map[play->pos_x][play->pos_y];
		shared->map[play->pos_x][play->pos_y] = 0;
		play->pos_y--;
	} else if (play->pos_y < center_y
	&& shared->map[play->pos_x][play->pos_y + 1] == 0) {
		shared->map[play->pos_x][play->pos_y + 1]
		= shared->map[play->pos_x][play->pos_y];
		shared->map[play->pos_x][play->pos_y] = 0;
		play->pos_y++;
	} if (unlock(play->sem_id) == 84
	|| display_current_state(shared, play) == 84)
		return (84);
	return (0);
}


int already_in_center(map_t *shared, player_t *play)
{
	int center_x = MAP_HEIGHT / 2;
	int center_y = MAP_WIDTH / 2;

	if (play->pos_x == center_x && play->pos_y == center_y)
		if (choose_direction(shared, play) == 84)
			return (84);
	if (display_current_state(shared, play) == 84)
		return (84);
	return (0);
}

int move_in_center(map_t *shared, player_t *play)
{
	int center_x = MAP_HEIGHT / 2;
	int center_y = MAP_WIDTH / 2;

	while (search_winner(shared) == 1) {
		if (play->pos_x != center_x)
			if (move_vertically(shared, play) == 84)
				return (84);
		if (play->pos_y != center_y)
			if (move_horizontally(shared, play) == 84)
				return (84);
		if (already_in_center(shared, play) == 84)
			return (84);
	} if (play->is_father == true) {
		display_map(shared);
		printf("Team %d win ! Game Over !\n", winner_find_out(shared));
	}
	return (0);
}
