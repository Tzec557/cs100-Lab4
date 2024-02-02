#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;


TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

TEST(TriangleTests, testArea) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getArea(),3.897114317029974);
}

TEST(TriangleTest, testKindIsosceles) {
    Triangle *aTriangle = new Triangle(3,3,3);
    Triangle::Kind result = aTriangle->getKind();
    EXPECT_EQ(result, Triangle::Kind::ISOSCELES);
}

TEST(TriangleTest, testKindEquilateral) {
    Triangle *aTriangle = new Triangle(3,3,3);
    Triangle::Kind result = aTriangle->getKind();
    EXPECT_EQ(result, Triangle::Kind::EQUILATERAL);
}

TEST(TriangleTest, testKindScalene) {
    Triangle *aTriangle = new Triangle(3,3,3);
    Triangle::Kind result = aTriangle->getKind();
    EXPECT_EQ(result, Triangle::Kind::SCALENE);
}

TEST(TriangleTests, testisIsosceles) {
    Triangle *aTriangle = new Triangle(3,3,4);
    EXPECT_TRUE (aTriangle->isIsosceles());
}

TEST(TriangleTests, testisEquilateral) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_TRUE (aTriangle->isEquilateral());
}

TEST(TriangleTests, testisEquilateral) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_DEATH(aTriangle->isEquilateral());
}
