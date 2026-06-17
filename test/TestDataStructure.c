
#include "DataStructure.h"
#include "unity.h"
#include <stdio.h>

static void set_test_input(const char *content)
{
  FILE *input = fopen("test_input.txt", "w");
  TEST_ASSERT_NOT_NULL(input);
  fputs(content, input);
  fclose(input);
  TEST_ASSERT_NOT_NULL(freopen("test_input.txt", "r", stdin));
}


void setUp(void)
{
  Row=-1;
  Column=-1;
  Step=-1;
  Delay=-1;
}

void tearDown(void)
{
  remove("test_input.txt");
}
/* All of these should pass */
void test_Readfile_emptyFile(void){
  game=fopen("empty.txt","r");
  TEST_ASSERT_EQUAL_INT(-1,Readfile(game));
  remove("Game.txt");
}

void test_Readfile_badFile(void){
  game=fopen("Bad.txt","r");
  TEST_ASSERT_EQUAL_INT(-1,Readfile(game));
  remove("Game.txt");
}

void test_Readfile_NoFile(void){
  game=NULL;
  TEST_ASSERT_EQUAL_INT(-1,Readfile(game));
  remove("Game.txt");
}

void test_stepAnddelay_validinput(void)
{
  Step=123;
  Delay=1000;
  set_test_input("0\nn\n");
  TEST_ASSERT_EQUAL_INT(0, steps());
  TEST_ASSERT_EQUAL_INT(Delay, delay());
}

void test_stepAnddelay_Invalidinput(void)
{
  set_test_input("0\na\n");
  TEST_ASSERT_EQUAL_INT(0, steps());
  TEST_ASSERT_EQUAL_INT(-1, delay());
}

void test_map_invalidinput(void)
{
  set_test_input("a\n");
  TEST_ASSERT_EQUAL_INT(1, map());
}

void test_map_invalidinput_toolarge(void)
{
  Row=201;
  Column=201;
  set_test_input("201\n");
  TEST_ASSERT_EQUAL_INT(1, map());
}

void test_map_validinput(void)
{
  Row=123;
  Column=123;
  set_test_input("a\n");
  TEST_ASSERT_EQUAL_INT(1, map());
}