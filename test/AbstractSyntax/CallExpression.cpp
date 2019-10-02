#include <iostream>

#include "gtest/gtest.h"

TEST(CallExpression, simpleSum) {
  EXPECT_EQ(1, 1) << "The sum is not correct";
}
