#include "unity.h"
#include "../src/GameUi.h"
#include <stdlib.h>

static int **board;

void setUp(void)
{
    int row;

    board = (int **)malloc(sizeof(*board) * 2);
    for (row = 0; row < 2; row++) {
        board[row] = (int *)malloc(sizeof(**board) * 2);
    }

    board[0][0] = 0;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 0;
}

void tearDown(void)
{
    int row;

    for (row = 0; row < 2; row++) {
        free(board[row]);
    }
    free(board);
}

void test_ClampDelay_bounds(void)
{
    TEST_ASSERT_EQUAL_INT(10, ClampDelay(0));
    TEST_ASSERT_EQUAL_INT(10, ClampDelay(9));
    TEST_ASSERT_EQUAL_INT(2000, ClampDelay(5000));
    TEST_ASSERT_EQUAL_INT(250, ClampDelay(250));
}

void test_AdjustDelay_helpers(void)
{
    TEST_ASSERT_EQUAL_INT(125, IncreaseDelay(100));
    TEST_ASSERT_EQUAL_INT(10, DecreaseDelay(20));
    TEST_ASSERT_EQUAL_INT(2000, IncreaseDelay(1990));
}

void test_WindowSizeForBoard_scales_by_size(void)
{
    TEST_ASSERT_EQUAL_INT(900, WindowSizeForBoard(20, 20));
    TEST_ASSERT_EQUAL_INT(780, WindowSizeForBoard(60, 40));
    TEST_ASSERT_EQUAL_INT(640, WindowSizeForBoard(120, 60));
}

void test_CountAliveCellsInBoard_counts_cells(void)
{
    TEST_ASSERT_EQUAL_INT(2, CountAliveCellsInBoard(board, 2, 2));
}

void test_ToggleCellAtPoint_toggles_target_cell(void)
{
    TEST_ASSERT_EQUAL_INT(1, ToggleCellAtPoint(board, 2, 2, 100, 10.0f, 10.0f));
    TEST_ASSERT_EQUAL_INT(1, board[0][0]);
    TEST_ASSERT_EQUAL_INT(1, ToggleCellAtPoint(board, 2, 2, 100, 60.0f, 10.0f));
    TEST_ASSERT_EQUAL_INT(0, board[0][1]);
}

void test_ToggleCellAtPoint_rejects_out_of_bounds(void)
{
    TEST_ASSERT_EQUAL_INT(0, ToggleCellAtPoint(board, 2, 2, 100, -1.0f, 10.0f));
    TEST_ASSERT_EQUAL_INT(0, ToggleCellAtPoint(board, 2, 2, 100, 101.0f, 10.0f));
}
