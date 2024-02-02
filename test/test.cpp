#include "gtest/gtest.h"
#include "gmock/gmock.h"


// Triangle 

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





// Hailstone

#include "../include/Hailstone.h"
using sequence::satisfiesHailstone;


TEST(HailstoneTests, testZeroHailstone){

	      uint64_t val = 0;

	      EXPECT_FALSE(satisfiesHailstone(val));

}

TEST(HailstoneTests, testOneHailstone){
        
	      uint64_t val = 1;

        EXPECT_TRUE(satisfiesHailstone(val));

}

TEST(HailstoneTests, testEvenHailstone){

        uint64_t val = 10;

        EXPECT_TRUE(satisfiesHailstone(val));

}

TEST(HailstoneTests, testOddHailstone){

        uint64_t val = 9;

        EXPECT_TRUE(satisfiesHailstone(val));

}

TEST(HailstoneTests, testNegativeHailstone){

        uint64_t val = -20;

        EXPECT_TRUE(satisfiesHailstone(val));

}





// Awards

#include "../include/Awards.h"

using namespace awards;
using ::testing::InSequence;

class RankListStub : public awards::RankList {
public:
    RankListStub() : currentIndex(0) {
        names.push_back("Alex");
        names.push_back("Brian");
        names.push_back("Charlie");
    }

    std::string getNext() override {
        if (currentIndex < names.size()) {
            return names[currentIndex++];
        } else {
            return "";
        }
    }

private:
    std::vector<std::string> names;
    int currentIndex;
};


class MockAwardCeremonyActions : public AwardCeremonyActions {
public:
    MOCK_METHOD(void, playAnthem, (), (override));
    MOCK_METHOD(void, awardBronze, (std::string name), (override));
    MOCK_METHOD(void, awardSilver, (std::string name), (override));
    MOCK_METHOD(void, awardGold, (std::string name), (override));
    MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
};


TEST(AwardsTests, PerformAwardCeremonyCallsMethodsInCorrectOrder) {

    RankListStub rankListStub;
    MockAwardCeremonyActions mockActions;
    InSequence seq;

    EXPECT_CALL(mockActions, playAnthem()).Times(1);
    EXPECT_CALL(mockActions, awardBronze("Alex")).Times(1);
    EXPECT_CALL(mockActions, awardSilver("Brian")).Times(1);
    EXPECT_CALL(mockActions, awardGold("Charlie")).Times(1);
    EXPECT_CALL(mockActions, turnOffTheLightsAndGoHome()).Times(1);

    performAwardCeremony(rankListStub, mockActions);

}