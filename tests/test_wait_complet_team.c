/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** test wait complet team
*/

#include <criterion/criterion.h>
#include "lemipc.h"

Test(assert, start_init_list)
{
	team_t	*player = malloc(sizeof(team_t));
	player_t *info = malloc(sizeof(player_t));

	if (player == NULL || info == NULL)
		exit(84);
	player->team_name = 2;
	init_sem(info);
	add_elem_in_list(2, player);
	cr_assert_not(player == 0);
}
