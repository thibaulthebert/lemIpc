/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** test winner
*/

#include <criterion/criterion.h>
#include "lemipc.h"

Test(assert, search_winner)
{
	player_t *player = malloc(sizeof(*player));
	map_t *shared;
	int value = 0;

	if (player == NULL)
		exit(84);
	player->team_name = 2;
	shared = create_segment(".", player);
	init_sem(player);
	add_players_in_map(shared, player);
	value = search_winner(shared);
	cr_assert(value == 0);
}

Test(assert, winner_find_out)
{
	player_t *player = malloc(sizeof(*player));
	map_t *shared;
	int value = 0;

	if (player == NULL)
		exit(84);
	player->team_name = 2;
	shared = create_segment(".", player);
	init_sem(player);
	add_players_in_map(shared, player);
	value = winner_find_out(shared);
	cr_assert(value > 0);
}
