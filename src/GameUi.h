#ifndef GameUi_GUARD__H
#define GameUi_GUARD__H

int ClampDelay(int delay);
int IncreaseDelay(int delay);
int DecreaseDelay(int delay);
int WindowSizeForBoard(int rows, int cols);
int CountAliveCellsInBoard(int **game, int rows, int cols);
int ToggleCellAtPoint(int **game, int rows, int cols, int window_size, float x, float y);

#endif
