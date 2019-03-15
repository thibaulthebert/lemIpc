/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** move_in_center
*/

#include <criterion/criterion.h>
#include "lemipc.h"

Test(assert, move_horizontally)
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
	value = move_horizontally(shared, player);
	cr_assert(value == 0);
}

Test(assert, move_vertically)
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
	value = move_vertically(shared, player);
	cr_assert(value == 0);
}

Test(assert, already_in_center)
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
	value = already_in_center(shared, player);
	cr_assert(value == 0);
}

Test(assert, move_in_center)
{
	player_t *player = malloc(sizeof(*player));
	map_t *shared;
	int value = 0;

	if (player == NULL)
		exit(84);
	player->team_name = 2;
	shared = create_segment(".", player);
	add_players_in_map(shared, player);
	value = move_in_center(shared, player);
	cr_assert(value == 0);
}
