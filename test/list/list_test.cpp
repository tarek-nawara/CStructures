#include "list_test.hpp"

ListTest::ListTest() {};

ListTest::~ListTest() {};

void ListTest::SetUp() {
  list = new SingleLinkedList<int>();
};

void ListTest::TearDown() {
  delete(list);
};

TEST_F(ListTest, EmptyListSizeShouldBeZero) {
  EXPECT_EQ(true, list->empty());
  EXPECT_EQ(0, list->size());
}

TEST_F(ListTest, AddingElementToEmptyListShouldWork) {
  list->add(1);
  list->add(2);
  EXPECT_EQ(false, list->empty());
  EXPECT_EQ(2, (*list)[0]);
  EXPECT_EQ(1, (*list)[1]);
}

TEST_F(ListTest, FilterShouldWork) {
  list->add(1);
  list->add(2);
  list->filter([](int x) { return x % 2 == 0; });
  EXPECT_EQ(1, list->size());
  EXPECT_EQ(2, (*list)[0]);
}


