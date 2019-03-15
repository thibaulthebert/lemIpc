/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** utils_sem
*/

#include "lemipc.h"

int 	lock(int sem_id)
{
	struct sembuf sops;

	sops.sem_num = 0;
	sops.sem_flg = 0;
	sops.sem_op = -1;
	if (semop(sem_id, &sops, 1) == -1)
		return (84);
	return (0);
}

int 	unlock(int sem_id)
{
	struct sembuf sops;

	sops.sem_num = 0;
	sops.sem_flg = 0;
	sops.sem_op = 1;
	if (semop(sem_id, &sops, 1) == -1)
		return (84);
	return (0);
}

int	init_sem(player_t *player)
{
	player->sem_id = semget(player->key_id, 1, SHM_R | SHM_W);
	if (player->sem_id == -1) {
		player->sem_id = semget(player->key_id, 1, IPC_CREAT
				| SHM_R | SHM_W);
		if (player->sem_id == -1
		|| semctl(player->sem_id, 0, SETVAL, 1) == -1)
			return (84);
	} else
		player->sem_id = semget(player->key_id, 1, IPC_CREAT
					| SHM_R | SHM_W);
	return (0);
}