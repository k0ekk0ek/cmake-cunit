#include <stdio.h>
#include <CUnit/Theory.h>

static float a = 8.0;
static float b = 9.0;

CU_Init(bar)
{
  printf("init (%s:%u) called\n", __FILE__, __LINE__);
  return 0;
}

CU_Clean(bar)
{
  printf("clean (%s:%u) called\n", __FILE__, __LINE__);
  return 0;
}

static void test_init(void)
{
  printf("test_init (%s:%u) called\n", __FILE__, __LINE__);
}

static void test_fini(void)
{
  printf("test_fini (%s:%u) called\n", __FILE__, __LINE__);
}

CU_Test(bar, baz, .timeout=2, .init = test_init, .fini = test_fini)
{
  printf("test (%s:%u) called.\n", __FILE__, __LINE__);
}

