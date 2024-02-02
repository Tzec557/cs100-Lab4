#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;



TEST(TriangleTest, testPerimeter) {
    Triangle *aTriangle = new Triangle(5,4,3);


    ASSERT_NE(aTriangle, nullptr);
    EXPECT_EQ (aTriangle->getPerimeter(),12);
}

TEST(TriangleTest, testArea) {
    Triangle *aTriangle = new Triangle(5,4,3);


    ASSERT_NE(aTriangle, nullptr);
    EXPECT_EQ (aTriangle->getArea(),6);
}

TEST(TriangleTest, testKindEquilateral) {
    Triangle *aTriangle = new Triangle(3,3,3);
    Triangle::Kind result = aTriangle->getKind();

    ASSERT_NE(aTriangle, nullptr);
    EXPECT_EQ(result, Triangle::Kind::EQUILATERAL);
}


TEST(TriangleTest, testDeathConstructorUno) {

    EXPECT_DEATH(Triangle(3,4,5), "First side is not the longest");
}


TEST(TriangleTest, testIsEquilateral) {

    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_TRUE(aTriangle->isEquilateral()); 
}

TEST(TriangleTest, testKindIsosceles) {
    Triangle *aTriangle = new Triangle(3,3,3);
    Triangle::Kind result = aTriangle->getKind();
    EXPECT_EQ(result, Triangle::Kind::ISOSCELES);
}

TEST(TriangleTest, testKindScalene) {
    Triangle *aTriangle = new Triangle(5,4,3);
    Triangle::Kind result = aTriangle->getKind();

    ASSERT_NE(aTriangle, nullptr);
    EXPECT_EQ(result, Triangle::Kind::SCALENE);
}


