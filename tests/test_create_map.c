/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** test create map
*/

#include <criterion/criterion.h>
#include "lemipc.h"


Test(assert, create_map)
{
	map_t *shared;
	player_t *player = malloc(sizeof(player_t));
	key_t key = ftok(".", 0);

	shared = create_segment(".", player);
	create_map(shared, key);
	cr_assert_not(shared == NULL);
}
