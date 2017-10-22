#include "single_linked_list.hpp"
#include "list_test.hpp"


ListTest::ListTest() {};

ListTest::~ListTest() {};

void ListTest::SetUp() {};

void ListTest::TearDown() {};

TEST_F(ListTest, ByDefaultBazFalseIsFalse) {
  EXPECT_EQ(true, true);
}

