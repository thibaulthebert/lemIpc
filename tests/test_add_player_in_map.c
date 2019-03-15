/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** test move in center
*/

#include <criterion/criterion.h>
#include "lemipc.h"

Test(assert, add_player_in_map)
{
	player_t *player = malloc(sizeof(*player));
	map_t *shared;
	int value = 0;

	if (player == NULL)
		exit(84);
	player->team_name = 2;
	shared = create_segment(".", player);
	add_players_in_map(shared, player);
	for (int x = 0 ; x < MAP_HEIGHT ; x++) {
		for (int y = 0 ; y < MAP_WIDTH ; y++) {
			if (shared->map[x][y] != 0)
				value = 1;
		}
	}
	cr_assert(value == 1);
}
