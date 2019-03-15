/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** create map
*/

#include "lemipc.h"

void	display_map(map_t *shared)
{
	for (int x = 0 ; x < MAP_HEIGHT ; x++) {
		for (int y = 0 ; y < MAP_WIDTH ; y++) {
			if ((y == 0 || y == MAP_WIDTH - 1)
			&& (x != 0 && x != MAP_HEIGHT - 1))
				printf("|");
			if (x == 0 || x == MAP_HEIGHT - 1)
				printf("_");
			if ((y != 0 && y != MAP_WIDTH - 1)
			&& (x != 0 && x != MAP_HEIGHT - 1)
			&& shared->map[x][y] == 0)
				printf(".");
			else if ((y != 0 && y != MAP_WIDTH - 1)
			&& (x != 0 && x != MAP_HEIGHT - 1)
			&& shared->map[x][y] != 0)
				printf("%d", shared->map[x][y]);
		}
		printf("\n");
	}
}

void	get_map(map_t *shared)
{
	for (int x = 0 ; x < MAP_HEIGHT ; x++) {
		for (int y = 0 ; y < MAP_WIDTH ; y++)
			shared->map[x][y] = 0;
	}
}

map_t	*create_map(map_t *shared, key_t key_id)
{
	int		shm_id;

	shm_id = shmget(key_id, sizeof(map_t)
				, IPC_CREAT | SHM_R | SHM_W);
	shared = (map_t *)shmat(shm_id, NULL, SHM_R | SHM_W);
	if (shared == (void *) - 1)
		return (NULL);
	get_map(shared);
	return (shared);
}
