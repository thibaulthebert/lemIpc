/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** winner
*/

#include "lemipc.h"

int search_winner(map_t *shared)
{
	int enemy = 1;
	int num = 0;
	int pass = 0;
	for (int x = 0; x != MAP_HEIGHT; x++) {
		for (int y = 0; y != MAP_WIDTH; y++) {
			if (shared->map[x][y] != 0 && pass == 0) {
				num = shared->map[x][y];
				pass = 1;
			} if (num != 0
				&& (shared->map[x][y] == 0
				|| num == shared->map[x][y]))
				enemy = 0;
			else if (num != 0
				&& (shared->map[x][y] != 0
				|| num != shared->map[x][y])) {
				return (1);
			}
		}
	}
	return (enemy);
}

int winner_find_out(map_t *shared)
{
	int team;

	for (int x = 0; x != MAP_HEIGHT; x++)
		for (int y = 0; y != MAP_WIDTH; y++)
			if (shared->map[x][y] != 0)
				team = shared->map[x][y];
	return (team);
}