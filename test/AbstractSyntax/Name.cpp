#include <iostream>

#include "gtest/gtest.h"

TEST(Name, simpleSum) {
  EXPECT_EQ(1, 1) << "The sum is not correct";
}
