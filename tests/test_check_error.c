/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** test_check_error
*/

#include <criterion/criterion.h>
#include "lemipc.h"

Test(assert, check_args)
{
	char *str[] = {"lemipc", ".", "12", NULL};
	int value = check_args(str);
	char *str2[] = {"lemipc", "./", "0", NULL};
	char *str3[] = {"lemipc", "azer", "0", NULL};

	cr_assert(value == 0);
	value = check_args(str2);
	cr_assert_not(value == 0);
	value = check_args(str3);
	cr_assert_not(value == 0);
}

Test(assert, check_nb_arg)
{
	int value = check_nb_arg(3);

	cr_assert(value == 0);
	value = check_nb_arg(1);
	cr_assert_not(value == 0);
}

Test(assert, check_error)
{
	char *str[] = {"lemipc", ".", "1", NULL};
	int value = check_error(3, str);
	char *str2[] = {"lemipc", "./", "100", NULL};

	cr_assert(value == 0);
	value = check_error(3, str2);
	cr_assert(value == 0);
}

