/*
** EPITECH PROJECT, 2019
** my
** File description:
** all my
*/

#ifndef __MY_H__
#define __MY_H__

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stddef.h>
#include <stdlib.h>
#include <SFML/System/Clock.h>

typedef struct sf_struct
{
    sfClock *clock;
    sfTime time;
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture_cross;
    sfTexture *texture_bg;
    sfTexture *texture_bird;
    sfSprite *sprite_cross;
    sfSprite *sprite_bg;
    sfSprite *sprite_bird;
    sfVector2f position_bird1;
    sfVector2f position_bird2;
    sfVector2f position_mouse_f;
    sfVector2i position_cross_i;
    sfVector2f position_cross_f;
    sfIntRect rect;
} sf;

typedef struct nb_struct
{
    int score;
    int score5;
    int heart;
    float speed;
    float seconds;
} nb;

void move_rect(int max_value, sf *cs, nb *go);
void draw_sprite(sf *cs);
void destroy(sf *cs);
void my_putchar(char c);
void my_put_nbr(int nb);
int my_putstr(char const *str);

#endif
