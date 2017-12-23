/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"
#include "hunter.h"

int main(int argc, char **argv)
{
	if (argc > 1 && my_strcmp(argv[1], "-h") == SUCCESS) {
		my_putstr("Usage:\n\tkill 10 ducks and have fun !\n");
		return (SUCCESS);
	}
	if (game(1280, 769) == FAILURE) {
		my_puterr("Window error\n");
		return (FAILURE);
	}
	return (SUCCESS);
}