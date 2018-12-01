#include <iostream>
#include <fstream>
#include <stdio.h>
#include "PT_TEST.h"
#include "gtest/gtest.h"

using namespace std;

namespace {
PT_TEST provider_terminal_test_obj;

TEST(PT_TEST, ValidateProvider) {
    freopen("input.txt", "r", stdin);
    EXPECT_TRUE(true == test_ValidateProvider(&provider_terminal_test_obj));
}

TEST(PT_TEST, ValidateMember) {
    EXPECT_TRUE(true == test_ValidateMember(&provider_terminal_test_obj));
    fclose(stdin); 
}
}



 

