/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "30.h"
#include <stdlib.h>

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_doublearraysize_null(void);
extern void test_doublearraysize_empty(void);
extern void test_doublearraysize_a(void);
extern void test_doublearraysize_alphabet(void);
extern void test_stringlength_null(void);
extern void test_stringlength_empty(void);
extern void test_stringlength_a(void);
extern void test_stringlength_alphabet(void);
extern void test_getfilteredstring_comp(void);
extern void test_getfilteredstring_comp183(void);


//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  UnityBegin("L30test.c");
  RUN_TEST(test_doublearraysize_null, 13);
  RUN_TEST(test_doublearraysize_empty, 21);
  RUN_TEST(test_doublearraysize_a, 29);
  RUN_TEST(test_doublearraysize_alphabet, 38);
  RUN_TEST(test_stringlength_null, 47);
  RUN_TEST(test_stringlength_empty, 51);
  RUN_TEST(test_stringlength_a, 55);
  RUN_TEST(test_stringlength_alphabet, 59);
  RUN_TEST(test_getfilteredstring_comp, 63);
  RUN_TEST(test_getfilteredstring_comp183, 71);

  return (UnityEnd());
}