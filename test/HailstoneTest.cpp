#include "gtest/gtest.h"
#include "../include/Hailstone.h"  
using sequence::satisfiesHailstone;

TEST(HailstoneTests, SatisfiesHailstoneWithZero) {
    EXPECT_FALSE(satisfiesHailstone(0));
}

TEST(HailstoneTests, SatisfiesHailstoneWithOne) {
    EXPECT_TRUE(satisfiesHailstone(1));
}

TEST(HailstoneTests, SatisfiesHailstoneWithEven) {
    EXPECT_TRUE(satisfiesHailstone(2));
    EXPECT_TRUE(satisfiesHailstone(4));
    EXPECT_TRUE(satisfiesHailstone(6));
}

TEST(HailstoneTests, SatisfiesHailstoneWithOdd) {
    EXPECT_TRUE(satisfiesHailstone(3));
    EXPECT_TRUE(satisfiesHailstone(5));
    EXPECT_TRUE(satisfiesHailstone(7));
}

TEST(HailstoneTests, SatisfiesHailstoneWithLarge) {
    EXPECT_TRUE(satisfiesHailstone(999));
}