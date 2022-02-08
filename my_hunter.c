/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** game
*/

#include <time.h>
#include "lib/my/my.h"

static void create(sf *cs, nb *go)
{
    cs->texture_bg = sfTexture_createFromFile("lib/my/back.jpg", NULL);
    cs->texture_bird = sfTexture_createFromFile("lib/my/bird.png", NULL);
    cs->texture_cross = sfTexture_createFromFile("lib/my/crosshair.png", NULL);
    cs->sprite_cross = sfSprite_create();
    cs->sprite_bg = sfSprite_create();
    cs->sprite_bird = sfSprite_create();
    go->speed = 0.15;
    go->heart = 3;
    cs->rect.top = 0;
    cs->rect.left = 0;
    cs->rect.width = 110;
    cs->rect.height = 110;
    sfSprite_setTexture(cs->sprite_bird, cs->texture_bird, sfTrue);
    sfSprite_setTexture(cs->sprite_bg, cs->texture_bg, sfTrue);
    sfSprite_setTexture(cs->sprite_cross, cs->texture_cross, sfTrue);
}

static void event(sf *cs, nb *go)
{
    if (cs->event.type == sfEvtMouseButtonPressed) {
        cs->position_bird2.x = sfSprite_getPosition(cs->sprite_bird).x;
        cs->position_bird2.y = sfSprite_getPosition(cs->sprite_bird).y;
        if (cs->position_mouse_f.x > cs->position_bird2.x &&
            cs->position_mouse_f.x < cs->position_bird2.x + 110 &&
            cs->position_mouse_f.y > cs->position_bird2.y &&
            cs->position_mouse_f.y < cs->position_bird2.y + 110) {
            cs->position_bird1.x = -10;
            cs->position_bird1.y = rand() % 480;
            go->score++;
            go->score5++;
        }
    }
    if (cs->event.type == sfEvtClosed)
        sfRenderWindow_close(cs->window);
}

static void duck_speed_heart(sf *cs, nb *go)
{
    cs->position_bird1.x += go->speed;
    if (go->score5 == 5) {
        go->speed *= 1.5;
        go->score5 = 0;
    }
    if (cs->position_bird1.x >= 1000 && go->heart != 0) {
        cs->position_bird1.x = -10;
        cs->position_bird1.y = rand() % 480;
        go->heart--;
    } else if (go->heart == 0) {
        my_putstr("Score: ");
        my_put_nbr(go->score);
        my_putchar('\n');
        sfRenderWindow_close(cs->window);
    }
}

static void game_loop(sf *cs, nb *go)
{
    move_rect(330, cs, go);
    cs->position_cross_i = sfMouse_getPositionRenderWindow(cs->window);
    cs->position_cross_f.x = cs->position_cross_i.x - 256;
    cs->position_cross_f.y = cs->position_cross_i.y - 300;
    cs->position_mouse_f.x = cs->position_cross_i.x;
    cs->position_mouse_f.y = cs->position_cross_i.y;
    sfSprite_setTextureRect(cs->sprite_bird, cs->rect);
    sfSprite_setPosition(cs->sprite_bird, cs->position_bird1);
    sfSprite_setPosition(cs->sprite_cross, cs->position_cross_f);
    sfSprite_move(cs->sprite_bird, cs->position_bird1);
    sfRenderWindow_display(cs->window);
    draw_sprite(cs);
    while (sfRenderWindow_pollEvent(cs->window, &cs->event))
    {
        event(cs, go);
    }
    duck_speed_heart(cs, go);
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sf *cs = malloc(sizeof(sf));
    nb *go = malloc(sizeof(nb));

    cs->window = sfRenderWindow_create(mode, "SFML window",
                                       sfDefaultStyle, NULL);
    create(cs, go);
    srand(time(0));
    cs->position_bird1.x = -10;
    cs->position_bird1.y = rand() % 480;
    cs->clock = sfClock_create();
    sfRenderWindow_setMouseCursorVisible(cs->window, sfFalse);
    while (sfRenderWindow_isOpen(cs->window)) {
        game_loop(cs, go);
    }
    destroy(cs);
    return (0);
}
