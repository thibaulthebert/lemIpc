/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** lemipc create team
*/

#include "lemipc.h"

int	check_full_team(team_t *team)
{
	int	check = 0;

	for (team_t *elem = team ; elem != NULL ; elem = elem->next) {
		if (elem->nb_player == 2)
			check++;
	}
	if (check < 2)
		return (-1);
	return (0);
}

team_t	*add_elem_in_list(int team, team_t *list)
{
	team_t	*new;

	for (team_t *elem = list ; elem != NULL ; elem = elem->next) {
		if (elem->team_name == team) {
			elem->nb_player++;
			return (list);
		}
	}
	new = malloc(sizeof(team_t));
	if (new == NULL)
		return (NULL);
	new->next = list;
	new->team_name = team;
	new->nb_player = 1;
	return (new);
}

int	start_init_list(int team_nb, player_t *info, msg_t msg)
{
	team_t	*player = malloc(sizeof(team_t));
	int	msg_id;
	if (player == NULL)
		return (-1);
	player->team_name = team_nb;
	player->nb_player = 1;
	player->next = NULL;
	if (lock(info->sem_id) == 84)
		return (84);
	msg_id = msgget(info->key_id, IPC_CREAT | SHM_R | SHM_W);
	if (msg_id == -1)
		return (84);
	while (check_full_team(player) == -1) {
		if (msgrcv(msg_id, &msg, sizeof(msg), 12, 0) == -1)
			return (84);
		player = add_elem_in_list(msg.team, player);
		if (player == NULL)
			return (84);
	}
	return (0);
}

int	msg_add_player(int team_nb, int msg_id, msg_t msg)
{
	bzero(&msg, sizeof(msg));
	msg.type = 12;
	msg.team = team_nb;
	if (msgsnd(msg_id, &msg, sizeof(msg), 0) == -1)
		return (84);
	return (0);
}

int	wait_teams_create(int team_nb, map_t *shared, player_t *player)
{
	msg_t	msg;
	player->msg_id = msgget(player->key_id, SHM_R | SHM_W);
	if (player->msg_id == -1 && player->is_father == true) {
		add_players_in_map(shared, player);
		if (start_init_list(team_nb, player, msg) == 84
			|| unlock(player->sem_id) == 84)
				return (84);
	}
	else {
		if (msg_add_player(team_nb, player->msg_id, msg) == 84)
			return (84);
		add_players_in_map(shared, player);
		if (lock(player->sem_id) == 84 || unlock(player->sem_id) == 84)
			return (84);
		msgctl(player->msg_id, IPC_RMID, NULL);
	}
	return (0);
}
