/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** lemipc
*/

#include "lemipc.h"

map_t	*create_segment(char *path, player_t *player)
{
	map_t	*shared = NULL;

	player->key_id = ftok(path, 0);
	if (player->key_id == -1)
		return (NULL);
	player->shm_id = shmget(player->key_id, sizeof(map_t), SHM_R | SHM_W);
	if (player->shm_id == -1) {
		shared = create_map(shared, player->key_id);
		if (shared == NULL)
			return (NULL);
		player->is_father = true;
	} else {
		shared = (map_t *)shmat(player->shm_id, NULL, SHM_R | SHM_W);
		if (shared == (void *) - 1)
			return (NULL);
		player->is_father = false;
	}
	return (shared);
}
