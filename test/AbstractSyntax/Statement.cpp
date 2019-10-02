#include <iostream>

#include "gtest/gtest.h"

TEST(Statement, simpleSum) {
  EXPECT_EQ(1, 1) << "The sum is not correct";
}
