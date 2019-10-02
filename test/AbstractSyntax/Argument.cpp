#include <iostream>

#include "gtest/gtest.h"

TEST(Argument, simpleSum) {
  EXPECT_EQ(1, 1) << "The sum is not correct";
}
