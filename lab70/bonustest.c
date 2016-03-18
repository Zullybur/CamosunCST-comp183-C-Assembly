#include <stdlib.h>
#include "bonus.h"
#include "io.h"
#include "unity.h"

bool cmpDouble(struct bigDouble *doubleStruct1, struct bigDouble *doubleStruct2) {
    if (!doubleStruct1 || !doubleStruct1->doubleString || !doubleStruct2 || !doubleStruct2->doubleString) {
        return NULL;
    }
    
    if (doubleStruct1->negative != doubleStruct2->negative) {
	printf("Signs clash\n");
        return false;
    }

    if (doubleStruct1->numDigitsBeforeDot != doubleStruct2->numDigitsBeforeDot) {
	printf("Digits before %u vs digits before %u\n", doubleStruct1->numDigitsBeforeDot, doubleStruct2->numDigitsBeforeDot);
        return false;
    }

    if (doubleStruct1->numDigitsAfterDot != doubleStruct2->numDigitsAfterDot) {
	printf("Digits after %u vs digits after %u\n", doubleStruct1->numDigitsAfterDot, doubleStruct2->numDigitsAfterDot);
        return false;
    }
    
    unsigned i = 0;
    for (i = 0; i < doubleStruct1->stringSize; i++) {
        if (doubleStruct1->doubleString[i] != doubleStruct2->doubleString[i]) {
		printf("Digit %c vs digit %c\n", doubleStruct1->doubleString[i], doubleStruct2->doubleString[i]);
            return false;
        }
    }
    
    return true;
}

void setUp(void)
{
}

void tearDown(void)
{
}

void test_addInt1(void) {
	freopen("bonustest1.in.txt", "r", stdin);
	struct bigDouble *d1 = getDouble();
	struct bigDouble *d2 = getDouble();
	struct bigDouble *dc = getDouble();
	struct bigDouble *d3 = addDouble(d1, d2);
	printDouble(dc);
	printDouble(d3);
	TEST_ASSERT_TRUE(cmpDouble(dc, d3));
	freeDouble(d1);
	freeDouble(d2);
	freeDouble(d3);
	freeDouble(dc);
}

void test_addInt2(void) {
	freopen("bonustest2.in.txt", "r", stdin);
	struct bigDouble *d1 = getDouble();
	struct bigDouble *d2 = getDouble();
	struct bigDouble *dc = getDouble();
	struct bigDouble *d3 = addDouble(d1, d2);
	printDouble(dc);
	printDouble(d3);
	TEST_ASSERT_TRUE(cmpDouble(dc, d3));
	freeDouble(d1);
	freeDouble(d2);
	freeDouble(d3);
	freeDouble(dc);
}

void test_addInt3(void) {
	freopen("bonustest3.in.txt", "r", stdin);
	struct bigDouble *d1 = getDouble();
	struct bigDouble *d2 = getDouble();
	struct bigDouble *dc = getDouble();
	struct bigDouble *d3 = addDouble(d1, d2);
	printDouble(dc);
	printDouble(d3);
	TEST_ASSERT_TRUE(cmpDouble(dc, d3));
	freeDouble(d1);
	freeDouble(d2);
	freeDouble(d3);
	freeDouble(dc);
}

void test_addInt4(void) {
	freopen("bonustest4.in.txt", "r", stdin);
	struct bigDouble *d1 = getDouble();
	struct bigDouble *d2 = getDouble();
	struct bigDouble *dc = getDouble();
	struct bigDouble *d3 = addDouble(d1, d2);
	printDouble(dc);
	printDouble(d3);
	TEST_ASSERT_TRUE(cmpDouble(dc, d3));
	freeDouble(d1);
	freeDouble(d2);
	freeDouble(d3);
	freeDouble(dc);
}
