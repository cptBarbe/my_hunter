/*
** EPITECH PROJECT, 2017
** textures
** File description:
** textures
*/

#include "my.h"
#include "hunter.h"

void clean(texture_t *texture, all_t *all)
{
	sfSprite_destroy(texture->sp_duck);
	sfSprite_destroy(texture->sp_back);
	sfTexture_destroy(texture->tex_duck);
	sfTexture_destroy(texture->tex_back);
	sfClock_destroy(all->cl);
	sfText_destroy(all->text);
	sfRenderWindow_destroy(all->window);
	sfMusic_destroy(all->music);
	sfMusic_destroy(all->gun);
	free(all);
	free(texture->ar);
	free(texture);
}

void draw(texture_t *texture, all_t *all)
{
	sfRenderWindow_clear(all->window, sfBlack);
	sfRenderWindow_drawSprite(all->window, texture->sp_back, NULL);
	sfRenderWindow_drawSprite(all->window, texture->sp_duck, NULL);
	sfRenderWindow_drawText(all->window, all->text, NULL);
	sfRenderWindow_display(all->window);
}

void set_items(texture_t *texture, all_t *all)
{
	sfText_setFont(all->text, all->font);
	sfText_setPosition(all->text, texture->text_position);
	sfSprite_setTexture(texture->sp_back, texture->tex_back, sfTrue);
	sfSprite_setTexture(texture->sp_duck, texture->tex_duck, sfFalse);
	sfRenderWindow_setFramerateLimit(all->window, 50);
}

void checking_all(texture_t *texture, all_t *all, short x)
{
	if (all->position.x > x) {
		all->position.x = -110;
		all->position.y = rand() % 600;
	}
	if (all->i >= 225)
		all->i = 0;
	if (all->sec > 0.1) {
		texture->ar->left = all->i;
		all->i += 80;
		sfSprite_setTextureRect(texture->sp_duck,
		*texture->ar);
		sfClock_restart(all->cl);
	}
}