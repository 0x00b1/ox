#include <iostream>

#include "gtest/gtest.h"

TEST(BlockStatement, simpleSum) {
  EXPECT_EQ(1, 1) << "The sum is not correct";
}
