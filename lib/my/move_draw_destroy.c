/*
** EPITECH PROJECT, 2019
** mouvedrawdestroy
** File description:
** fonction mouv draw destroy
*/

#include <time.h>
#include "my.h"

void move_rect(int max_value, sf *cs, nb *go)
{
    cs->time = sfClock_getElapsedTime(cs->clock);
    go->seconds = cs->time.microseconds / 200000.0;
    if (go->seconds > 1.0) {
        cs->rect.left += 110;
        if (cs->rect.left >= max_value)
            cs->rect.left = 0;
        sfClock_restart(cs->clock);
    }
}

void draw_sprite(sf *cs)
{
    sfRenderWindow_drawSprite(cs->window, cs->sprite_bg, NULL);
    sfRenderWindow_drawSprite(cs->window, cs->sprite_bird, NULL);
    sfRenderWindow_drawSprite(cs->window, cs->sprite_cross, NULL);
}

void destroy(sf *cs)
{
    sfRenderWindow_destroy(cs->window);
    sfTexture_destroy(cs->texture_bg);
    sfSprite_destroy(cs->sprite_bg);
    sfTexture_destroy(cs->texture_bird);
    sfSprite_destroy(cs->sprite_bird);
    sfTexture_destroy(cs->texture_cross);
    sfSprite_destroy(cs->sprite_cross);
}
