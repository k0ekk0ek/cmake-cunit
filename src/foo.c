#include <stdio.h>
#include <CUnit/Theory.h>

static float a = 8.0;
static float b = 9.0;

CU_Init(foo)
{
  printf("init (%s:%u) called\n", __FILE__, __LINE__);
  return 0;
}

CU_Clean(foo)
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

CU_Test(foo, foo)
{
  printf("test (%s:%u) called.\n", __FILE__, __LINE__);
}

CU_Test(foo, baz, .timeout=2, .init = test_init, .fini = test_fini)
{
  printf("test (%s:%u) called.\n", __FILE__, __LINE__);
}

static void theory_fini(void)
{
  printf("theory_fini (%s:%u) called\n", __FILE__, __LINE__);
}

CU_TheoryDataPoints(foo, bar) = {
  CU_DataPoints(int, 2, 3),
  CU_DataPoints(double, 2.0, 3.5),
  CU_DataPoints(const float *const, &a, &b),
};

CU_Theory((int foo, double bar, const float *const baz), foo, bar, .timeout=10, .init = test_init, .fini = theory_fini)
{
  printf("theory (%s:%u) called. foo: %d, bar: %lf, baz: %f\n", __FILE__, __LINE__, foo, bar, *baz);
}

