# Kathryn Silva
# Nov. 30th 2018

# Please tweak the following variable definitions as needed by your
# project, except GTEST_HEADERS, which you can use in your own targets
# but shouldn't modify.

# Points to the root of Google Test, relative to where this file is
# Remember to tweak this if you move this file.
GTEST_DIR = ../googletest/googletest

# Where to find user code.
USER_DIR = .

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = providerterminal_unittest

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

# Builds gtest.a and gtest_main.a.

# DO NOT CHANGE ANYTHING WITH "_"
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# DO NOT CHANGE THESE SECTION

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
	$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
	$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds provider terminal tests

PT_TEST.o : $(USER_DIR)/PT_TEST.cpp $(USER_DIR)/PT_TEST.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/PT_TEST.cpp

PT_test_suite.o : $(USER_DIR)/PT_test_suite.cpp $(USER_DIR)/PT_TEST.h $(GTEST_HEADERS)
		$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/PT_test_suite.cpp

scanner.o : $(USER_DIR)/scanner.cpp $(USER_DIR)/scanner.h $(GTEST_HEADERS)
		$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/scanner.cpp

providerterminal_unittest.o : $(USER_DIR)/providerterminal_unittest.cpp \
		$(USER_DIR)/PT_TEST.h $(GTEST_HEADERS)
		$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/providerterminal_unittest.cpp

providerterminal_unittest : PT_TEST.o PT_test_suite.o scanner.o \
			providerterminal_unittest.o gtest_main.a
		$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
