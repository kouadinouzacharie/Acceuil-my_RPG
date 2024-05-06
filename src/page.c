#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include "../include/my.h"
#define NUM_TEXTS 5
#define NUM_HELP_TEXTS 3
#define NUM_BUTTONS 5

bool show_help = false;
int boutton_actuel = 1;
void deplacer_selection_bouton(int direction)
{
    boutton_actuel += direction;
    if (boutton_actuel >= NUM_BUTTONS)
        boutton_actuel = 0;
    else if (boutton_actuel < 0)
        boutton_actuel = NUM_BUTTONS - 1;
}

void selectionner_bouton(sfRenderWindow *window)
{
    switch(boutton_actuel) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            show_help = true;
            break;
        case 4:
            sfRenderWindow_close(window);
            break;
    }
}

void gerer_evenements(sfRenderWindow *window, sfText **texts, sfText **help_texts)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyQ)
                show_help = false;
            else if (event.key.code == sfKeyDown)
                deplacer_selection_bouton(1);
            else if (event.key.code == sfKeyUp)
                deplacer_selection_bouton(-1);
            else if (event.key.code == sfKeyReturn)
                selectionner_bouton(window);
        }
    }
}

void jouer_musique(sfMusic *music)
{
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
}

sfText *game_name(sfRenderWindow *window)
{
    sfText *nom_jeu_text;
    nom_jeu_text = sfText_create();
    sfText_setFont(nom_jeu_text, sfFont_createFromFile("src/zelda.ttf"));
    sfText_setString(nom_jeu_text, "A Knight's Quest");
    sfText_setCharacterSize(nom_jeu_text, 48);
    sfText_setFillColor(nom_jeu_text, sfWhite);
    sfFloatRect game_name_bounds = sfText_getLocalBounds(nom_jeu_text);
    sfVector2f game_name_position;
    game_name_position.x = (sfRenderWindow_getSize(window).x - game_name_bounds.width) / 2;
    game_name_position.y = 20;
    sfText_setPosition(nom_jeu_text, game_name_position);
    return nom_jeu_text;
}

void afficher_fenetre(sfRenderWindow *window, sfSprite *sprite, sfText **texts, sfText **help_texts)
{
    sfText *nom_jeu_text = game_name(window);
    if (show_help)
        afficher_page_aide(window, sprite, help_texts, NUM_HELP_TEXTS);
    else {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawText(window, nom_jeu_text, NULL);
        for (int i = 0; i < NUM_TEXTS; i++)
            sfRenderWindow_drawText(window, texts[i], NULL);
        sfRenderWindow_display(window);
    }
}

void afficher_page_aide(sfRenderWindow *window, sfSprite *sprite, sfText **help_texts, int num_help_texts)
{
    sfTexture *texture = sfTexture_createFromFile("src/parchemin.jpg", NULL);
    sfSprite *background = sfSprite_create();
    sfSprite_setTexture(background, texture, sfTrue);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_drawText(window, help_texts[0], NULL);
    for (int i = 0; i < num_help_texts; i++)
        sfRenderWindow_drawText(window, help_texts[i], NULL);
    sfText *return_message = sfText_create();
    sfText_setFont(return_message, sfFont_createFromFile("src/zelda.ttf"));
    sfText_setString(return_message, "Si vous souhaitez revenir au menu, appuyez sur la touche Q");
    sfText_setCharacterSize(return_message, 36);
    sfText_setFillColor(return_message, sfBlack);
    sfVector2f return_message_position;
    return_message_position.x = 20;
    return_message_position.y = sfRenderWindow_getSize(window).y - 50;
    sfText_setPosition(return_message, return_message_position);
    sfRenderWindow_drawText(window, return_message, NULL);
    sfText_destroy(return_message);
    sfTexture_destroy(texture);
    sfRenderWindow_display(window);
}

void initialiser_welcome_help(sfText *text, sfFont *font, sfVideoMode mode)
{
    sfFloatRect return_button = sfText_getGlobalBounds(text);
    sfVector2f return_position;

    return_position.x = (mode.width - return_button.width) / 2;
    return_position.y = mode.height - return_button.height - 1000;
    sfText_setPosition(text, return_position);
}


void initialiser_message_help(sfText *text, sfFont *font, sfVideoMode mode)
{
    sfFloatRect help_page_text = sfText_getGlobalBounds(text);
    sfVector2f help_page_position;

    help_page_position.x = (mode.width - help_page_text.width) / 2;
    help_page_position.y = (mode.height - help_page_text.height) - 500;
    sfText_setPosition(text, help_page_position);
}

void initialiser_textes_aide(sfText **help_texts, sfFont *font, sfVideoMode mode)
{
    sfText_setString(help_texts[0], "Welcome to the help page!");
    sfText_setString(help_texts[1], "In this adventure, you are the\
    chosen hero tasked with defeating the evil forces that threaten our \
    land.\nTo navigate the world, use the arrow keys or WASD keys.\nPress k\
    to strike a sword blow\npress j to use shield\nPress i to open inventory ");
    sfText_setCharacterSize(help_texts[2], 24);
    sfText_setFillColor(help_texts[0], sfBlack);
    sfText_setFillColor(help_texts[1], sfBlack);
    initialiser_welcome_help(help_texts[0], font, mode);
    initialiser_message_help(help_texts[1], font, mode);
}

void modifier_couleur_textes(sfText **texts, sfVector2i mousepos, sfColor *textColors, sfColor *hoverColors)
{
    int i = 0;

    for (i = 0; i < NUM_TEXTS; i++) {
        sfFloatRect textBounds = sfText_getGlobalBounds(texts[i]);
        if (sfFloatRect_contains(&textBounds, mousepos.x, mousepos.y))
            sfText_setFillColor(texts[i], hoverColors[i]);
        else
            sfText_setFillColor(texts[i], textColors[i]);
    }
     sfText_setFillColor(texts[boutton_actuel], hoverColors[boutton_actuel]);
}

void initialiser_texte_play(sfText *text, sfFont *font, sfVideoMode mode)
{
    sfVector2f play_position;
    sfFloatRect boutton_play = sfText_getGlobalBounds(text);

    sfText_setString(text, "Play");
    play_position.x = 70;
    play_position.y = (mode.height - boutton_play.height - 500) / 2;
    sfText_setPosition(text, play_position);
}

void initialiser_texte_option(sfText *text, sfFont *font, sfVideoMode mode)
{
    sfText_setString(text, "Option");
    sfFloatRect boutton_option = sfText_getGlobalBounds(text);
    sfVector2f option_position;
    option_position.x = 70;
    option_position.y = (mode.height - boutton_option.height - 400) / 2 + 100;
    sfText_setPosition(text, option_position);
}

void initialiser_texte_help(sfText *text, sfFont *font, sfVideoMode mode)
{
    sfText_setString(text, "Help");
    sfFloatRect boutton_help = sfText_getGlobalBounds(text);
    sfVector2f help_position;
    help_position.x = 70;
    help_position.y = (mode.height - boutton_help.height - 400) / 2 + 200;
    sfText_setPosition(text, help_position);
}

void initialiser_texte_quit(sfText *text, sfFont *font, sfVideoMode mode)
{
    sfText_setString(text, "Quit");
    sfFloatRect boutton_quit = sfText_getGlobalBounds(text);
    sfVector2f quit_position;
    quit_position.x = 70;
    quit_position.y = (mode.height - boutton_quit.height - 400) / 2 + 300;
    sfText_setPosition(text, quit_position);
}

void initialiser_textes(sfText **texts, sfFont *font, sfVideoMode mode)
{
    initialiser_texte_play(texts[1], font, mode);
    initialiser_texte_option(texts[2], font, mode);
    initialiser_texte_help(texts[3], font, mode);
    initialiser_texte_quit(texts[4], font, mode);
}

void creer_textes(sfText **texts, sfFont *font, int tailleTexte, sfColor couleurTexte)
{
    for (int i = 0; i < NUM_TEXTS; i++) {
        texts[i] = sfText_create();
        sfText_setFont(texts[i], font);
        sfText_setCharacterSize(texts[i], tailleTexte);
        sfText_setFillColor(texts[i], couleurTexte);
    }
}

void destroy_texts(sfText **texts, sfText **help_texts, int num_texts, int num_help_texts)
{
    int i = 0;

    for (i = 0; i < num_texts; i++)
        sfText_destroy(texts[i]);
    for (i = 0; i < num_help_texts; i++)
        sfText_destroy(help_texts[i]);
}

void destroy_resources(sfMusic *music, sfFont *font, sfSprite *sprite, sfTexture *texture)
{
    sfMusic_destroy(music);
    sfFont_destroy(font);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

int main(void)
{
    int i = 0;
    sfVideoMode mode = {1920, 1080, 64};
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *texts[NUM_TEXTS];
    sfText *help_texts[NUM_HELP_TEXTS];
    sfMusic *music;
    sfColor textColors[NUM_TEXTS] = {sfBlack, sfBlack, sfBlack, sfBlack, sfBlack};
    sfColor hoverColors[NUM_TEXTS] = {sfWhite, sfWhite, sfWhite, sfWhite, sfWhite};
    window = sfRenderWindow_create(mode, "window", sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    texture = sfTexture_createFromFile("src/cu.jpg", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    font = sfFont_createFromFile("src/zelda.ttf");
    music = sfMusic_createFromFile("src/song.ogg");
     jouer_musique(music);
    creer_textes(texts, font, 50, sfWhite);
    initialiser_textes(texts, font, mode);
    creer_textes(help_texts, font, 30, sfWhite);
    initialiser_textes_aide(help_texts, font, mode);
    while (sfRenderWindow_isOpen(window)){
        gerer_evenements(window, texts, help_texts);
        sfVector2i mousepos = sfMouse_getPositionRenderWindow(window);
        modifier_couleur_textes(texts, mousepos, textColors, hoverColors);
        afficher_fenetre(window, sprite, texts, help_texts);
         sfFloatRect quit_bounds = sfText_getGlobalBounds(texts[4]);
    if (sfFloatRect_contains(&quit_bounds, mousepos.x, mousepos.y)&&
    sfMouse_isButtonPressed(sfMouseLeft))
        sfRenderWindow_close(window);
    }
    destroy_texts(texts, help_texts, NUM_TEXTS, NUM_HELP_TEXTS);
    destroy_resources(music, font, sprite, texture);
    sfRenderWindow_destroy(window);
    return 0;
}
