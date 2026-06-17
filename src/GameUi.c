#include "GameUi.h"

int ClampDelay(int delay)
{
    if (delay < 10) {
        return 10;
    }
    if (delay > 2000) {
        return 2000;
    }
    return delay;
}

int IncreaseDelay(int delay)
{
    return ClampDelay(delay + 25);
}

int DecreaseDelay(int delay)
{
    return ClampDelay(delay - 25);
}

int WindowSizeForBoard(int rows, int cols)
{
    int max_dimension = rows > cols ? rows : cols;

    if (max_dimension <= 35) {
        return 900;
    }
    if (max_dimension <= 80) {
        return 780;
    }
    return 640;
}

int CountAliveCellsInBoard(int **game, int rows, int cols)
{
    int alive = 0;
    int row;
    int col;

    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            alive += game[row][col];
        }
    }

    return alive;
}

int ToggleCellAtPoint(int **game, int rows, int cols, int window_size, float x, float y)
{
    int row;
    int col;
    float cell_w;
    float cell_h;

    if (rows <= 0 || cols <= 0 || window_size <= 0) {
        return 0;
    }

    if (x < 0 || y < 0 || x >= window_size || y >= window_size) {
        return 0;
    }

    cell_w = (float)window_size / (float)cols;
    cell_h = (float)window_size / (float)rows;
    row = (int)(y / cell_h);
    col = (int)(x / cell_w);

    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return 0;
    }

    game[row][col] = game[row][col] > 0 ? 0 : 1;
    return 1;
}
