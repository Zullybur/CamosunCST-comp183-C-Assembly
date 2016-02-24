#include <stdlib.h>
#include "30.h"
#include "unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_doublearraysize_null(void) {
   unsigned size = 0;
   char *string = doubleArraySize(NULL, &size); 
   TEST_ASSERT_EQUAL_UINT(0, size);
   TEST_ASSERT_NULL(string);
   free(string);
}

void test_doublearraysize_empty(void) {
   unsigned size = 0;
   char *string = doubleArraySize("", &size);   
   TEST_ASSERT_EQUAL_UINT(0, size);
   TEST_ASSERT_NULL(string);
   free(string);
}

void test_doublearraysize_a(void) {
   unsigned size = 1;
   char *string = doubleArraySize("A", &size);  
   TEST_ASSERT_EQUAL_UINT(2, size);
   char expected2[2] = "A";
   TEST_ASSERT_EQUAL_MEMORY_ARRAY(expected2, string, 2, sizeof(char));
   free(string);
}

void test_doublearraysize_alphabet(void) {
   unsigned size = 26;
   char *string = doubleArraySize("ABCDEFGHIJKLMNOPQRSTUVWXYZ", &size); 
   TEST_ASSERT_EQUAL_UINT(52, size);
   char expected1[52] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   TEST_ASSERT_EQUAL_MEMORY_ARRAY(expected1, string, 52, sizeof(char));
   free(string);
}

void test_stringlength_null(void) {
   TEST_ASSERT_EQUAL_UINT(0, stringLength(NULL));
}

void test_stringlength_empty(void) {
   TEST_ASSERT_EQUAL_UINT(0, stringLength(""));
}

void test_stringlength_a(void) {
   TEST_ASSERT_EQUAL_UINT(1, stringLength("A"));
}

void test_stringlength_alphabet(void) {
   TEST_ASSERT_EQUAL_UINT(26, stringLength("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
}

void test_getfilteredstring_comp(void) {
   char *error = NULL;
   freopen("30test1.txt", "r", stdin);
   char *string = getFilteredString("Enter the course code:\n", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", &error);
   TEST_ASSERT_EQUAL_STRING("MATHEMATICS", string);
   TEST_ASSERT_NULL(error);
}

void test_getfilteredstring_comp183(void) {
   char *error = NULL;
   freopen("30test2.txt", "r", stdin);
   char *string = getFilteredString("Enter the course code:\n", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", &error);
   TEST_ASSERT_EQUAL_STRING("Found invalid character", error);
   TEST_ASSERT_NULL(string);
}