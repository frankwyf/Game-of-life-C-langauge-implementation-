#include "unity.h"
#include "../src/GameUi.h"

extern void setUp(void);
extern void tearDown(void);
extern void test_ClampDelay_bounds(void);
extern void test_AdjustDelay_helpers(void);
extern void test_WindowSizeForBoard_scales_by_size(void);
extern void test_CountAliveCellsInBoard_counts_cells(void);
extern void test_ToggleCellAtPoint_toggles_target_cell(void);
extern void test_ToggleCellAtPoint_rejects_out_of_bounds(void);

static void run_test(UnityTestFunction func, const char* name, int line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
    }
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

int main(void)
{
    UnityBegin("TestGameUi.c");
    run_test(test_ClampDelay_bounds, "test_ClampDelay_bounds", 29);
    run_test(test_AdjustDelay_helpers, "test_AdjustDelay_helpers", 37);
    run_test(test_WindowSizeForBoard_scales_by_size, "test_WindowSizeForBoard_scales_by_size", 44);
    run_test(test_CountAliveCellsInBoard_counts_cells, "test_CountAliveCellsInBoard_counts_cells", 51);
    run_test(test_ToggleCellAtPoint_toggles_target_cell, "test_ToggleCellAtPoint_toggles_target_cell", 56);
    run_test(test_ToggleCellAtPoint_rejects_out_of_bounds, "test_ToggleCellAtPoint_rejects_out_of_bounds", 64);
    return UnityEnd();
}
