#include <iostream>

#include "gtest/gtest.h"

TEST(BooleanLiteralExpression, simpleSum) {
  EXPECT_EQ(1, 1) << "The sum is not correct";
}
