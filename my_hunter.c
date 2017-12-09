/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** my_hunter
*/

#include "my.h"
#include "hunter.h"

void speed_increase(all_t *all)
{
	if (all->score == 9)
		all->speed = 42;
	if (all->score == 6)
		all->speed = 30;
	if (all->score == 3)
		all->speed = 20;
}

int check_hit(all_t *all)
{
	if (all->event.mouseButton.x >= all->position.x
	&& all->event.mouseButton.x <= all->position.x + 110
 	&& all->event.mouseButton.y >= all->position.y
 	&& all->event.mouseButton.y <= all->position.y + 110) {
		all->score++;
		my_printf("\033[32mYeah, Score: %d\n\033[00m", all->score);
		all->position.x = -330;
		all->position.y = rand() % 600;
		return(SUCCESS);
	} else {
		my_printf("\033[31mOups, Score: %d\n\033[00m", all->score);
		all->score--;
	}
	return (FAILURE);
}

int get_events(all_t *all)
{
	while (sfRenderWindow_pollEvent(all->window, &all->event)) {
		if (all->event.type == sfEvtClosed)
			sfRenderWindow_close(all->window);
		if (all->event.type == sfEvtMouseButtonPressed) {
			check_hit(all);
			sfMusic_play(all->gun);
		}
	}
	return (SUCCESS);
}

int check_score(texture_t *texture, all_t *all)
{
	if (all->score == 10) {
		my_putstr("You win !!\n");
		clean(texture, all);
		return (SUCCESS);
	}
	if (all->score < 0) {
		my_putstr("You loose !!\n");
		clean(texture, all);
		return (SUCCESS);
	}
	return (42);
}

int game(short x, short y)
{
	texture_t *texture = tex();
	all_t *all = set_all();
	sfVideoMode mode = {x, y, 60};
	char const name[9] = "My_hunter";

	all->window = sfRenderWindow_create(mode, name, sfClose, NULL);
	if (!all->window || !all->music)
		return (FAILURE);
	set_items(texture, all);
	sfMusic_play(all->music);
	while (sfRenderWindow_isOpen(all->window)) {
	sfText_setString(all->text, "score:");
		all->time = sfClock_getElapsedTime(all->cl);
		all->sec = sfTime_asSeconds(all->time);
		all->position.x = all->position.x + all->speed;
		get_events(all);
		speed_increase(all);
		if (check_score(texture, all) == SUCCESS)
			return (SUCCESS);
		checking_all(texture, all, x);
		sfSprite_setPosition(texture->sp_duck, all->position);
		draw(texture, all);
	}
	clean(texture, all);
    	return (SUCCESS);
}