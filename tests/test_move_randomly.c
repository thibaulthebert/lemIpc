/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** test move random
*/

#include <criterion/criterion.h>
#include "lemipc.h"

Test(assert, choose_direction)
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
	value = choose_direction(shared, player);
	cr_assert(value == 0);
}
