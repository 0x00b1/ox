#include <iostream>

#include "gtest/gtest.h"

TEST(ValueExpression, simpleSum) {
  EXPECT_EQ(1, 1) << "The sum is not correct";
}
