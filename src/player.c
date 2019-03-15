/*
** EPITECH PROJECT, 2018
** lelipc
** File description:
** ia
*/

#include <lemipc.h>

void	avoid_edge_map(player_t *player)
{
	srand(time(NULL));
	player->pos_x = rand() % MAP_HEIGHT;
	player->pos_y = rand() % MAP_WIDTH;
	if (player->pos_x == 0)
		player->pos_x++;
	else if (player->pos_x == MAP_HEIGHT - 1)
		player->pos_x--;
	if (player->pos_y == 0)
		player->pos_y++;
	else if (player->pos_y == MAP_WIDTH - 1)
		player->pos_y--;
}

void	add_players_in_map(map_t *shared, player_t *player)
{
	avoid_edge_map(player);
	if (shared->map[player->pos_x][player->pos_y] == 0)
		shared->map[player->pos_x][player->pos_y] = player->team_name;
	else {
		while (shared->map[player->pos_x][player->pos_y] != 0) {
			avoid_edge_map(player);
		}
		shared->map[player->pos_x][player->pos_y] = player->team_name;
	}
}
