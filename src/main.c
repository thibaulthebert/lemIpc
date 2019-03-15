/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** lemipc
*/

#include "lemipc.h"

int	main(int ac, char **av)
{
	player_t	*player = malloc(sizeof(*player));
	map_t		*shared;

	if (player == NULL || check_error(ac, av) == 84)
		return (84);
	player->team_name = atoi(av[2]);
	shared = create_segment(av[1], player);
	if (shared == NULL || init_sem(player) == 84)
		return (84);
	if (wait_teams_create(player->team_name, shared, player) == 84
	|| move_in_center(shared, player) == 84)
		return (84);
	if (player->team_name == winner_find_out(shared)) {
		sleep(2);
		shmctl(player->shm_id, IPC_RMID, NULL);
		semctl(player->sem_id, 0, IPC_RMID);
	}
	free(player);
	return (0);
}
