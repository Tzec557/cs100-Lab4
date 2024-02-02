#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;


TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

TEST(TriangleTests, testPArea) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getArea(),3.89711);
}

TEST(TriangleTest, testKindIsosceles) {
    Kind *result = triangle.getKind();
    EXPECT_EQ(result, Kind::ISOSCELES);
}

TEST(TriangleTest, testKindEquilateral) {
    Kind *result = triangle.getKind();
    EXPECT_EQ(result, Kind::EQUILATERAL);
}

TEST(TriangleTest, testKindScalene) {
    Kind *result = triangle.getKind();
    EXPECT_EQ(result, Kind::SCALENE);
}

TEST(TriangleTests, testisIsosceles) {
    Triangle *aTriangle = new Triangle(3,3,4);
    EXPECT_TRUE (aTriangle->isIsosceles());
}

TEST(TriangleTests, testisIsosceles) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_TRUE (aTriangle->isEquilateral());
}