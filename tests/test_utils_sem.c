/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** test utils_sem
*/


#include <criterion/criterion.h>
#include "lemipc.h"

Test(assert, utils_sem)
{
	player_t *player = malloc(sizeof(*player));
	int value;

	if (player == NULL)
		exit(84);
	value = init_sem(player);
	cr_assert(value == 0);
	value = unlock(player->sem_id);
	cr_assert(value == 0);
	value = lock(player->sem_id);
	cr_assert(value == 0);
	unlock(player->sem_id);
}
