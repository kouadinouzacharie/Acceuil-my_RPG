// #include "../include/my.h"

// void gerer_evenements(sfRenderWindow* window)
// {
//     sfEvent event;
//     while (sfRenderWindow_pollEvent(window, &event))
//     {
//         if (event.type == sfEvtClosed)
//             sfRenderWindow_close(window);
//     }
// }

// void afficher_fenetre(sfRenderWindow *window, sfSprite *sprite, sfText **texts, int numTexts)
// {
//     sfRenderWindow_clear(window, sfBlack);
//     sfRenderWindow_drawSprite(window, sprite, NULL);
//     for (int i = 0; i < numTexts; i++)
//         sfRenderWindow_drawText(window, texts[i], NULL);
//     sfRenderWindow_display(window);
// }

// void jouer_musique(sfMusic *music)
// {
//     sfMusic_setLoop(music, sfTrue);
//     sfMusic_play(music);
// }

// int main(void)
// {
//     int numTexts = 5;
//     int i;
//     sfVideoMode mode = {1920, 1080, 64};

//     sfRenderWindow *window;
//     sfTexture *texture;
//     sfSprite *sprite;
//     sfFont *font;
//     sfText *texts[5];
//     sfMusic *music;
//     window = sfRenderWindow_create(mode, "window", sfResize | sfClose, NULL);
//     texture = sfTexture_createFromFile("src/cut.jpg", NULL);
//     sprite = sfSprite_create();
//     sfSprite_setTexture(sprite, texture, sfTrue);
//     font = sfFont_createFromFile("src/zelda.ttf");
//     music = sfMusic_createFromFile("src/song.ogg");
//     jouer_musique(music);
//     for (i = 0; i < 5; i++)
//     {
//         texts[i] = sfText_create();
//         sfText_setFont(texts[i], font);
//         sfText_setCharacterSize(texts[i], 50);
//         sfText_setFillColor(texts[i], sfWhite);
//     }
//     sfText_setString(texts[0], "A Knight's Quest");
//     sfText_setString(texts[1], "Play");
//     sfText_setString(texts[2], "Option");
//     sfText_setString(texts[3], "Help");
//     // sfText_setString(texts[4], "Settings");
//     sfFloatRect game_name = sfText_getGlobalBounds(texts[0]);
//     sfVector2f name_position;
//     name_position.x = (mode.width - game_name.width) / 2;
//     name_position.y = 0;
//     sfText_setPosition(texts[0], name_position);
//     sfFloatRect boutton_play = sfText_getGlobalBounds(texts[1]);
//     sfVector2f play_position;
//     play_position.x = (mode.width - boutton_play.width) / 2;
//     play_position.y = (mode.height - boutton_play.height - 400) / 2;
//     sfText_setPosition(texts[1], play_position);
//     sfFloatRect boutton_option = sfText_getGlobalBounds(texts[2]);
//     sfVector2f option_position;
//     option_position.x = play_position.x;
//     option_position.y = play_position.y + 100;
//     sfText_setPosition(texts[2], option_position);
//     sfFloatRect boutton_help = sfText_getGlobalBounds(texts[3]);
//     sfVector2f help_position;
//     help_position.x = option_position.x;
//     help_position.y = option_position.y + 100;
//     sfText_setPosition(texts[3], help_position);
//     sfColor textColors[5] = {sfWhite, sfWhite, sfWhite, sfWhite, sfWhite};
//     sfColor hoverColors[5] = {sfRed, sfBlue, sfGreen, sfYellow, sfMagenta};
//     while (sfRenderWindow_isOpen(window))
//     {
//         gerer_evenements(window);
//         sfVector2i mousePosition = sfMouse_getPositionRenderWindow(window);
//         for (i = 0; i < numTexts; i++) {
//             sfFloatRect textBounds = sfText_getGlobalBounds(texts[i]);
//             if (sfFloatRect_contains(&textBounds, mousePosition.x, mousePosition.y))
//                 sfText_setFillColor(texts[i], hoverColors[i]);
//             else
//                 sfText_setFillColor(texts[i], textColors[i]);
//         }
//         afficher_fenetre(window, sprite, texts, numTexts);
//     }
//     sfMusic_destroy(music);
//     for (i = 0; i < numTexts; i++)
//         sfText_destroy(texts[i]);
//     sfFont_destroy(font);
//     sfSprite_destroy(sprite);
//     sfTexture_destroy(texture);
//     sfRenderWindow_destroy(window);
//     return 0;
// }
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/my.h"

void gerer_evenements(sfRenderWindow* window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event))
    {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void afficher_fenetre(sfRenderWindow *window, sfSprite *sprite, sfText **texts, int numTexts)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    for (int i = 0; i < numTexts; i++)
        sfRenderWindow_drawText(window, texts[i], NULL);
    sfRenderWindow_display(window);
}

void jouer_musique(sfMusic *music)
{
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
}

void initialiser_textes(sfText **texts, sfFont *font, sfVideoMode mode)
{
    sfText_setString(texts[0], "A Knight's Quest");
    sfText_setString(texts[1], "Play");
    sfText_setString(texts[2], "Option");
    sfText_setString(texts[3], "Help");
    // sfText_setString(texts[4], "Settings");
    sfFloatRect game_name = sfText_getGlobalBounds(texts[0]);
    sfVector2f name_position;
    name_position.x = (mode.width - game_name.width) / 2;
    name_position.y = 0;
    sfText_setPosition(texts[0], name_position);
    sfFloatRect boutton_play = sfText_getGlobalBounds(texts[1]);
    sfVector2f play_position;
    play_position.x = (mode.width - boutton_play.width) / 2;
    play_position.y = (mode.height - boutton_play.height - 400) / 2;
    sfText_setPosition(texts[1], play_position);
    sfFloatRect boutton_option = sfText_getGlobalBounds(texts[2]);
    sfVector2f option_position;
    option_position.x = play_position.x;
    option_position.y = play_position.y + 100;
    sfText_setPosition(texts[2], option_position);
    sfFloatRect boutton_help = sfText_getGlobalBounds(texts[3]);
    sfVector2f help_position;
    help_position.x = option_position.x;
    help_position.y = option_position.y + 100;
    sfText_setPosition(texts[3], help_position);
}

void modifier_couleur_textes(sfText **texts, sfVector2i mousePosition, sfColor *textColors, sfColor *hoverColors)
{
    for (int i = 0; i < 5; i++)
    {
        sfFloatRect textBounds = sfText_getGlobalBounds(texts[i]);
        if (sfFloatRect_contains(&textBounds, mousePosition.x, mousePosition.y))
            sfText_setFillColor(texts[i], hoverColors[i]);
        else
            sfText_setFillColor(texts[i], textColors[i]);
    }
}

int main(void)
{
    int numTexts = 5;
    int i = 0;
    sfVideoMode mode = {1920, 1080, 64};
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *texts[5];
    sfMusic *music;
    sfColor textColors[5] = {sfWhite, sfWhite, sfWhite, sfWhite, sfWhite};
    sfColor hoverColors[5] = {sfBlack, sfBlack, sfBlack, sfBlack, sfBlack};

    window = sfRenderWindow_create(mode, "window", sfResize | sfClose, NULL);
    texture = sfTexture_createFromFile("src/cut.jpg", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    font = sfFont_createFromFile("src/zelda.ttf");
    music = sfMusic_createFromFile("src/song.ogg");
    jouer_musique(music);
    for (i = 0; i < 5; i++)
    {
        texts[i] = sfText_create();
        sfText_setFont(texts[i], font);
        sfText_setCharacterSize(texts[i], 50);
        sfText_setFillColor(texts[i], sfWhite);
    }
    initialiser_textes(texts, font, mode);
    while (sfRenderWindow_isOpen(window))
    {
        gerer_evenements(window);
        sfVector2i mousePosition = sfMouse_getPositionRenderWindow(window);
        modifier_couleur_textes(texts, mousePosition, textColors, hoverColors);
        afficher_fenetre(window, sprite, texts, numTexts);
    }
    sfMusic_destroy(music);
    for (i = 0; i < numTexts; i++)
        sfText_destroy(texts[i]);
    sfFont_destroy(font);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return 0;
}
