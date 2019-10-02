#include <iostream>

#include "gtest/gtest.h"

TEST(Operator, simpleSum) {
  EXPECT_EQ(1, 1) << "The sum is not correct";
}
