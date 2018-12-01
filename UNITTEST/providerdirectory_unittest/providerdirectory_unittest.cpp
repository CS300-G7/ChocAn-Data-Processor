// Copyright (c) 2018 Yiming Lin
// Five unit tests for provider directory handler
// Followings are tested:
// (1) ProviderDirectoryEntry constructors
// (2) ProviderDitectoryEntry copy constructors
// (3) ProviderDirectoryHandler insertion
// (4) ProviderDirectoryHandler retrieve by service code
// (5) ProviderDirectoryHandler removing entries

#include "pd.h"
#include "gtest/gtest.h"

namespace {
char code1[] = "111111";
char name1[] = "service name 1";
float fee1 = 1.1;
char code2[] = "222222";
char name2[] = "service name 2";
float fee2 = 2.2;
char code3[] = "333333";
char name3[] = "service name 3";
float fee3 = 3.3;
char code4[] = "444444";
char name4[] = "service name 4";
float fee4 = 4.4;
char code5[] = "555555";
char name5[] = "service name 5";
float fee5 = 5.5;
char code6[] = "666666";
char name6[] = "service name 6";
float fee6 = 6.6;
char code7[] = "777777";
char name7[] = "service name 7";
float fee7 = 7.7;
char code8[] = "888888";
char name8[] = "service name 8";
float fee8 = 8.8;
char code9[] = "999999";
char name9[] = "service name 9";
float fee9 = 9.9;


// Test ProviderDirectoryEntry constructor
TEST(ProviderDirectoryEntry, Constructor) {
    ProviderDirectoryEntry e1(code1, name1, fee1);
    ProviderDirectoryEntry e2(code2, name2, fee2);
    ProviderDirectoryEntry e3(code3, name3, fee3);
    ProviderDirectoryEntry e4(code4, name4, fee4);

    // Asserts that each field of object is same as input values
    EXPECT_EQ(0, strcmp(e1.get_service_code(), code1));
    EXPECT_EQ(0, strcmp(e2.get_service_code(), code2)); 
    EXPECT_EQ(0, strcmp(e3.get_service_code(), code3));
    EXPECT_EQ(0, strcmp(e4.get_service_code(), code4));
    EXPECT_EQ(fee1, e1.get_fee());
    EXPECT_EQ(fee2, e2.get_fee());
    EXPECT_EQ(fee3, e3.get_fee());
    EXPECT_EQ(fee4, e4.get_fee());
}

// Test ProviderDirectoryEntry copy constructor
TEST(ProviderDirectoryEntry, CopyConstructor) {
    ProviderDirectoryEntry e11(code1, name1, fee1);
    ProviderDirectoryEntry e21(code2, name2, fee2);
    ProviderDirectoryEntry e31(code3, name3, fee3);
    ProviderDirectoryEntry e41(code4, name4, fee4);
    ProviderDirectoryEntry e1 = e11;
    ProviderDirectoryEntry e2 = e21;
    ProviderDirectoryEntry e3 = e31;
    ProviderDirectoryEntry e4 = e41;
    
    // Asserts that service code and fee are same between two objects 
    EXPECT_EQ(0, strcmp(e1.get_service_code(), code1));
    EXPECT_EQ(0, strcmp(e2.get_service_code(), code2)); 
    EXPECT_EQ(0, strcmp(e3.get_service_code(), code3));
    EXPECT_EQ(0, strcmp(e4.get_service_code(), code4));
    EXPECT_EQ(fee1, e1.get_fee());
    EXPECT_EQ(fee2, e2.get_fee());
    EXPECT_EQ(fee3, e3.get_fee());
    EXPECT_EQ(fee4, e4.get_fee());
}

PdEntry e1(code1, name1, fee1);
PdEntry e2(code2, name2, fee2);
PdEntry e3(code3, name3, fee3);
PdEntry e4(code4, name4, fee4);
PdEntry e5(code5, name5, fee5);
PdEntry e6(code6, name6, fee6);
PdEntry e7(code7, name7, fee7);
PdEntry e8(code8, name8, fee8);
PdEntry e9(code9, name9, fee9);
ProviderDirectoryHandler handler;

// Test ProviderDirectoryHandler insertion
TEST(ProviderDirectoryHandler, Insert) {
    PdEntry dup1(code1, name2, fee2);
    PdEntry dup2(code2, name3, fee3);
    PdEntry dup3(code3, name4, fee4);
    PdEntry dup4(code4, name5, fee5);
    PdEntry dup5(code5, name6, fee6);

    // Asserts that if the code doesn't exist, it can be inserted
    // into the provider directory
    EXPECT_TRUE(true == handler.Insert(&e1));
    EXPECT_TRUE(true == handler.Insert(&e2));
    EXPECT_TRUE(true == handler.Insert(&e3));
    EXPECT_TRUE(true == handler.Insert(&e4));
    EXPECT_TRUE(true == handler.Insert(&e5));
    EXPECT_TRUE(true == handler.Insert(&e6));
    EXPECT_TRUE(true == handler.Insert(&e7));
    EXPECT_TRUE(true == handler.Insert(&e8));
    EXPECT_TRUE(true == handler.Insert(&e9));
    EXPECT_TRUE(false == handler.Insert(&dup1)); 
    EXPECT_TRUE(false == handler.Insert(&dup2));    
    EXPECT_TRUE(false == handler.Insert(&dup3));
    EXPECT_TRUE(false == handler.Insert(&dup4));
    EXPECT_TRUE(false == handler.Insert(&dup5));
}

// Test provider directory retrieve by search key -- service code
TEST(ProviderDirectoryHandler, Retrieve) {
    char receiver[256];
    
    // Asserts that searched name and fee are consistent
    EXPECT_TRUE(true == handler.SearchServiceName(code1, receiver) && fee1 == handler.SearchFee(code1));
    EXPECT_EQ(0, strcmp(receiver, name1));
    EXPECT_TRUE(true == handler.SearchServiceName(code2, receiver) && fee2 == handler.SearchFee(code2));
    EXPECT_EQ(0, strcmp(receiver, name2));
    EXPECT_TRUE(true == handler.SearchServiceName(code3, receiver) && fee3 == handler.SearchFee(code3));
    EXPECT_EQ(0, strcmp(receiver, name3));
    EXPECT_TRUE(true == handler.SearchServiceName(code4, receiver) && fee4 == handler.SearchFee(code4));
    EXPECT_EQ(0, strcmp(receiver, name4));
    EXPECT_TRUE(true == handler.SearchServiceName(code5, receiver) && fee5 == handler.SearchFee(code5));
    EXPECT_EQ(0, strcmp(receiver, name5));
    EXPECT_TRUE(true == handler.SearchServiceName(code6, receiver) && fee6 == handler.SearchFee(code6));
    EXPECT_EQ(0, strcmp(receiver, name6));
    EXPECT_TRUE(true == handler.SearchServiceName(code7, receiver) && fee7 == handler.SearchFee(code7));
    EXPECT_EQ(0, strcmp(receiver, name7));
    EXPECT_TRUE(true == handler.SearchServiceName(code8, receiver) && fee8 == handler.SearchFee(code8));
    EXPECT_EQ(0, strcmp(receiver, name8));
    EXPECT_TRUE(true == handler.SearchServiceName(code9, receiver) && fee9 == handler.SearchFee(code9));
    EXPECT_EQ(0, strcmp(receiver, name9));
    EXPECT_TRUE(false == handler.SearchServiceName("341313", receiver) && -1 == handler.SearchFee("341313"));
    EXPECT_TRUE(false == handler.SearchServiceName("000000", receiver) && -1 == handler.SearchFee("000000"));
    EXPECT_TRUE(false == handler.SearchServiceName("342345", receiver) && -1 == handler.SearchFee("342345"));
    EXPECT_TRUE(false == handler.SearchServiceName("123456", receiver) && -1 == handler.SearchFee("123456")); 
    EXPECT_TRUE(false == handler.SearchServiceName("987654", receiver) && -1 == handler.SearchFee("987654"));
}

// Test provider directory entry removing
TEST(ProviderDirectoryHandler, Remove) {
    // Asserts that if the pos. num. is less than 
    // the number of entries, it can be removed
    EXPECT_TRUE(false == handler.RemoveAtPos(10));
    EXPECT_TRUE(false == handler.RemoveAtPos(11));
    EXPECT_TRUE(true == handler.RemoveAtPos(9));
    EXPECT_TRUE(true == handler.RemoveAtPos(8));
    EXPECT_TRUE(true == handler.RemoveAtPos(7));
    EXPECT_TRUE(true == handler.RemoveAtPos(6));
    EXPECT_TRUE(true == handler.RemoveAtPos(5));
    EXPECT_TRUE(true == handler.RemoveAtPos(4));
    EXPECT_TRUE(true == handler.RemoveAtPos(3));
    EXPECT_TRUE(true == handler.RemoveAtPos(2));
    EXPECT_TRUE(true == handler.RemoveAtPos(1));
    EXPECT_TRUE(false == handler.RemoveAtPos(2));
    EXPECT_TRUE(false == handler.RemoveAtPos(1));
}
} // namespace