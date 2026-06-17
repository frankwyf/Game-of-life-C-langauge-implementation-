#ifndef GameWindow_GUARD__H 
#define GameWindow_GUARD__H

#ifdef SDL3_AVAILABLE
#include <SDL3/SDL.h>

#define DEFAULT_WINDOW_SIZE 900
/*
  This head file is used to store the functions and variables 
  used in SDL windows and renders
*/
/*SDL window pointer*/
SDL_Window *window;
/*SDL surface pointer*/
SDL_Surface *surface;
/*SDL event*/
SDL_Event e;
/*the number of cells that are alive*/
int alive;
/*SDL variables for the intro text window*/
SDL_Window *text;
SDL_Renderer *render;
SDL_Surface *intro;
SDL_Texture *introText;
SDL_Event event;
int WindowSize;
bool Paused;

/*the function to initialize a window for display*/
int InitWindow();
/*the function to show next generation in SDL mode*/
void show(int **Game);
/*the function to intialize a window for click*/
void click();

#else
/* SDL3 not available - stub implementations */
#define DEFAULT_WINDOW_SIZE 900
int alive;
int WindowSize;
bool Paused;
static inline int InitWindow() { return -1; }
static inline void show(int **Game) { }
static inline void click() { printf("SDL3 not available - UI mode disabled.\n"); }
#endif
/*the function to display message on the window*/
int title(int round);
void RandomizeBoard();
void ClearBoard();

#endif