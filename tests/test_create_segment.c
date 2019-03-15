/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** test create segement
*/

#include <criterion/criterion.h>
#include "lemipc.h"

Test(assert, create_segment_with_null)
{
	player_t *player = malloc(sizeof(*player));
	map_t *shared;

	if (player == NULL)
		exit(84);
	shared = create_segment("dont work", player);
	cr_assert(shared == NULL);
}

Test(assert, create_segment)
{
	player_t *player = malloc(sizeof(*player));
	map_t *shared;

	if (player == NULL)
		exit(84);
	shared = create_segment(".", player);
	cr_assert_not(shared == NULL);
}
