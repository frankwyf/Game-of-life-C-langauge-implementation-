#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL3/SDL.h>
#include "GameWindow.h"
#include "DataStructure.h"

// structures to get time and display timestamps in terminal
static time_t t;
static struct tm *lt;

static void print_timestamp_prefix(void) {
    time(&t);
    lt = localtime(&t);
    printf("%d/%d/%d %d:%d:%d", lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
}

// function to create the window
int InitWindow() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Unable to initialise SDL: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    window = SDL_CreateWindow("Conway's Game of Life", 600, 600, 0);
    if (window == NULL) {
        printf("Unable to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    render = SDL_CreateRenderer(window, NULL);
    if (render == NULL) {
        printf("Unable to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    move = 1;
    return 0;
}

void show(int **Game) {
    alive = 0;

    if (render == NULL || Row <= 0 || Column <= 0) {
        return;
    }

    const float cell_w = 600.0f / (float)Column;
    const float cell_h = 600.0f / (float)Row;

    SDL_SetRenderDrawColor(render, 123, 123, 122, 255);
    SDL_RenderClear(render);

    for (int y = 0; y < Row; y++) {
        for (int x = 0; x < Column; x++) {
            alive += Game[y][x];
            if (Game[y][x] > 0) {
                SDL_FRect square = {
                    .x = x * cell_w,
                    .y = y * cell_h,
                    .w = cell_w - 1.0f,
                    .h = cell_h - 1.0f,
                };
                SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
                SDL_RenderFillRect(render, &square);
            }
        }
    }

    SDL_RenderPresent(render);
    title(move);
    SDL_Delay(Delay);
}

// the function to initialize a window for click
void click() {
    printf("Click to change the state of the cells!\nPress enter when finished, Esc to exit the game.\n");

    if (window == NULL || render == NULL) {
        if (InitWindow() != 0) {
            return;
        }
    }

    show(Game);

    bool setting = true;
    while (setting) {
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
                case SDL_EVENT_MOUSE_BUTTON_DOWN: {
                    float mx = 0.0f;
                    float my = 0.0f;
                    SDL_GetMouseState(&mx, &my);

                    int row = (int)(my / (600.0f / (float)Row));
                    int col = (int)(mx / (600.0f / (float)Column));

                    if (row >= 0 && row < Row && col >= 0 && col < Column) {
                        Game[row][col] = (Game[row][col] > 0) ? 0 : 1;
                        show(Game);
                    }
                    break;
                }
                case SDL_EVENT_KEY_DOWN:
                    switch (e.key.key) {
                        case SDLK_RETURN:
                            printf("\n**********************\n    Setting over!\n**********************\n\n");
                            setting = false;
                            break;
                        case SDLK_ESCAPE:
                            printf("-------------------\nTerminated at initial state.\nSaving is ignored.\n");
                            setting = false;
                            exit(1);
                        default:
                            break;
                    }
                    break;
                case SDL_EVENT_QUIT:
                    setting = false;
                    break;
                default:
                    break;
            }
        }
    }

    WriteResult(game);
}

// lightweight title/message helper for SDL3 migration stage
int title(int round) {
    if (round == -2) {
        printf("Welcome to Conway's Game of Life.\n");
        return 0;
    }
    if (round == -1) {
        printf("Controls: Backspace=re-initialize, Enter=replay, Esc=quit.\n");
        return 0;
    }
    if (round == -3) {
        printf("End of game at ");
        print_timestamp_prefix();
        printf(".\n");
        return 0;
    }
    if (round == -4) {
        printf("Replay starts at ");
        print_timestamp_prefix();
        printf(".\n");
        return 0;
    }
    if (round == -5) {
        printf("Preparing board re-establish mode.\n");
        return 0;
    }

    int deaded = Row * Column - alive;
    printf("Step %d | Alive: %d | Dead: %d | ", round - 1, alive, deaded);
    print_timestamp_prefix();
    printf("\n");
    return 0;
}
