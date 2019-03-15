/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** gestion erreur
*/

#include "lemipc.h"

int check_args(char **argv)
{
	key_t key = ftok(argv[1], 0);

	if (key == -1)
		return (84);
	if (atoi(argv[2]) <= 0)
		return (84);
	return (0);
}

int check_nb_arg(int argc)
{
	if (argc < 3 || argc > 3)
		return (84);
	return (0);
}

int check_error(int argc, char **argv)
{
	if (check_nb_arg(argc) == 84 || check_args(argv) == 84) {
		printf("USAGE\n\t./lemipc PATH TEAM_NUMBER\n\n");
		printf("DESCRIPTION\n\t");
		printf("PATH\t\tpath you’ll give to ftok\n\t");
		printf("TEAM_NUMBER\tteam number of the current champion");
		printf("(greater than 0)\n");
		return (84);
	}
	return (0);
}
