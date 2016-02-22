#include <stdlib.h>
#include "40.h"
#include "io.h"
#include "unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_getInt(void) {
	freopen("40test1.txt", "r", stdin);
	int result = getInt();
	TEST_ASSERT_EQUAL_INT(-183, result);
}

void test_getLong(void) {
	freopen("40test1.txt", "r", stdin);
	long result = getLong();
	TEST_ASSERT_EQUAL_INT64(2999999999L, result);
}

void test_getUnsigned(void) {
	freopen("40test1.txt", "r", stdin);
	unsigned result = getUnsigned();
	TEST_ASSERT_EQUAL_INT(176, result);
}

void test_getFilteredString_valid(void) {
	char *error = NULL;
	freopen("30test1.txt", "r", stdin);
	char *string = getFilteredString("Enter the course code:\n", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", &error);
	TEST_ASSERT_EQUAL_STRING("MATHEMATICS", string);
	TEST_ASSERT_NULL(error);
    free(string);
}

void test_getFilteredString_invalid(void) {
	char *error = NULL;
	freopen("30test2.txt", "r", stdin);
	char *string = getFilteredString("Enter the course code:\n", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", &error);
	TEST_ASSERT_EQUAL_STRING("Found invalid character", error);
	TEST_ASSERT_NULL(string);
    free(string);
}

void test_getFilteredString_nofilter(void) {
	char *error = NULL;
	freopen("30test2.txt", "r", stdin);
	char *string = getFilteredString("Enter the course code:\n", NULL, &error);
	TEST_ASSERT_EQUAL_STRING("Found invalid character", error);
	TEST_ASSERT_NULL(string);
    free(string);
}

#define NUM_RESORTS 5
#define BUF_SIZE 255

void test_resorts_valid(void) {
	char *error = NULL;
	freopen("40test2.txt", "r", stdin);
	struct resortType *resorts = getResorts(NUM_RESORTS);
	TEST_ASSERT_NOT_NULL(resorts);
	printResorts(resorts, NUM_RESORTS, "40test2.act");
	FILE *fpAct = fopen("40test2.act", "r");
	FILE *fpExp = fopen("40test2.exp", "r");
	char act[BUF_SIZE + 1] = { '\0' };
	char exp[BUF_SIZE + 1] = { '\0' };
	fgets(act, BUF_SIZE, fpAct);
	fgets(exp, BUF_SIZE, fpExp);
	TEST_ASSERT_EQUAL_MEMORY_ARRAY(exp, act, BUF_SIZE, sizeof(char));
    free(resorts);
}

void test_sortedresorts_valid(void) {
	char *error = NULL;
	freopen("40test2.txt", "r", stdin);
	struct resortType *resorts = getResorts(NUM_RESORTS);
	TEST_ASSERT_NOT_NULL(resorts);
	sortResorts(resorts, NUM_RESORTS);
	printResorts(resorts, NUM_RESORTS, "40test2.act2");
	FILE *fpAct = fopen("40test2.act2", "r");
	FILE *fpExp = fopen("40test2.exp2", "r");
	char act[BUF_SIZE + 1] = { '\0' };
	char exp[BUF_SIZE + 1] = { '\0' };
	fgets(act, BUF_SIZE, fpAct);
	fgets(exp, BUF_SIZE, fpExp);
	TEST_ASSERT_EQUAL_MEMORY_ARRAY(exp, act, BUF_SIZE, sizeof(char));
    free(resorts);
}

void test_resorts_invalid(void) {
	char *error = NULL;
	freopen("40test3.txt", "r", stdin);
	struct resortType *resorts = getResorts(NUM_RESORTS);
	TEST_ASSERT_NOT_NULL(resorts);
	sortResorts(resorts, NUM_RESORTS);
	printResorts(resorts, NUM_RESORTS, "40test3.act");
	FILE *fpAct = fopen("40test3.act", "r");
	FILE *fpExp = fopen("40test3.exp", "r");
	char act[BUF_SIZE + 1] = { '\0' };
	char exp[BUF_SIZE + 1] = { '\0' };
	fgets(act, BUF_SIZE, fpAct);
	fgets(exp, BUF_SIZE, fpExp);
	TEST_ASSERT_EQUAL_MEMORY_ARRAY(exp, act, BUF_SIZE, sizeof(char));
    free(resorts);
}


