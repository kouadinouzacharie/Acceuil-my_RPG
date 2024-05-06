/*
** EPITECH PROJECT, 2024
** files
** File description:
** files
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <criterion/criterion.h>
    #include <math.h>
    #define NUM_MENU_ITEMS 4
typedef struct tool {
    sfTexture *drawTexture;
    sfSprite *drawSprite;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfColor color;
    sfTexture *textur;
    sfTexture *text;
    sfTexture *tex;
    sfSprite *sprite;
    sfSprite *spri;
    sfSprite *s;
    int numPoints;
    int maxPoints;
    bool isDrawing;
    sfVertexArray *lines;
    sfVector2f *points;
    bool showMenu;
    sfFont* font;
    sfText* menuItems[4];
    bool isErasing;
} tool_t;
void afficher_page_aide(sfRenderWindow *window, sfSprite *sprite, sfText **help_texts, int numHelpTexts);
int MenuBar(tool_t *tool);
void init_menu(tool_t *tool);
void update_drawing(tool_t *ctx);
void render_drawing(tool_t *ctx);
void close_window(sfRenderWindow *window);
int handle_textures(tool_t *appel);
void handle_window(tool_t *appel);
void game_loop(tool_t *appel);
void analyse_event(tool_t *appel);
int window(void);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
char *my_strcpy(char *dest, char *src);
int my_strcmp(char *s1, char *s2);
void init_tools(tool_t *tool);
void draw_sprite(tool_t *tool);
int array_colors(tool_t *tool);
void render_drawing(tool_t *ctx);
void create_menu(tool_t *tool);
#endif /* !my */
