/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** header
*/

#ifndef LEMIPC_H
	#define LEMIPC_H

	extern const int	EXIT_ERROR;
	extern const int	EXIT_SUCESS;
	#define	MAP_HEIGHT	20
	#define MAP_WIDTH	20

	#include <stdio.h>
	#include <stdbool.h>
	#include <string.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <sys/ipc.h>
	#include <sys/types.h>
	#include <sys/shm.h>
	#include <sys/sem.h>
	#include <time.h>
	#include <errno.h>
	#include <sys/msg.h>

	typedef struct	s_map {
		int	map[MAP_HEIGHT][MAP_WIDTH];
	}		map_t;

	typedef struct	s_team {
		int	team_name;
		int	nb_player;
		struct s_team *next;
	}		team_t;

	typedef struct s_player {
		bool	is_father;
		key_t	key_id;
		int	shm_id;
		int	sem_id;
		int	msg_id;
		int	pos_x;
		int	pos_y;
		int	team_name;
	}		player_t;

	typedef struct	s_msg {
		long	type;
		int	team;
	}		msg_t;

	int     check_error(int, char **);
	void    add_players_in_map(map_t *, player_t *);
	void	fill_segment(void *);
	void	display_map(map_t *);
	int	lock(int);
	int	unlock(int);
	int	init_players(key_t);
	int	search_winner(map_t *);
	void	check_surround(map_t *, player_t *);
	int	move_in_center(map_t *, player_t *);
	int	choose_direction(map_t *, player_t *);
	map_t	*create_map(map_t *, key_t);
	map_t	*create_segment(char *, player_t *);
	int	init_sem(player_t *);
	int	winner_find_out(map_t *);
	int	wait_teams_create(int, map_t *, player_t *);
	int 	already_in_center(map_t *shared, player_t *play);
	int 	move_horizontally(map_t *shared, player_t *play);
	int 	move_vertically(map_t *shared, player_t *play);
	void 	move_randomly(map_t *shared, player_t *play, int x, int y);
	int 	check_args(char **argv);
	int	check_nb_arg(int argc);
	team_t	*add_elem_in_list(int team, team_t *list);
#endif
