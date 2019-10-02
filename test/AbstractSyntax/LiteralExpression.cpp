#include <iostream>

#include "gtest/gtest.h"

TEST(LiteralExpression, simpleSum) {
  EXPECT_EQ(1, 1) << "The sum is not correct";
}
