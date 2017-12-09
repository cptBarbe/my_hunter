/*
** EPITECH PROJECT, 2017
** set_structures
** File description:
** set_structures
*/

#include "my.h"
#include "hunter.h"

texture_t *tex()
{
	texture_t *text = malloc(sizeof(texture_t));

	text->ar = malloc(sizeof(sfIntRect));
	text->ar->left = 0;
	text->ar->top = 0;
	text->ar->width = 225;
	text->ar->height = 58;
	text->tex_duck = sfTexture_createFromFile("./assets/sprite.png",
	 				     text->ar);
	text->ar->width = 68;
	text->tex_back = sfTexture_createFromFile("./assets/background.png",
						     NULL);
	text->sp_back = sfSprite_create();
	text->sp_duck = sfSprite_create();
	text->text_position.x = 1000;
	text->text_position.y = 700;
	return (text);
}

all_t *set_all()
{
	all_t *all = malloc(sizeof(all_t));

	all->i = 0;
	all->sec = 0;
	all->text = sfText_create();
	all->font = sfFont_createFromFile("assets/Gameplay.ttf");
	all->music = sfMusic_createFromFile("assets/Music.ogg");
	all->gun = sfMusic_createFromFile("assets/gun.ogg");
	all->position.x = -110;
	all->position.y = rand() % 600;
	all->cl = sfClock_create();

	all->score = 0;
	all->speed = 10;
	return (all);
}