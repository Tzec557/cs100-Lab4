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

#include <string>
#include <vector>

using ::testing::InSequence;

using awards::RankList;
using awards::AwardCeremonyActions;

using std::string;
using std::vector;




class MockRankList : public RankList {

	vector<string> names = {"Adam", "Beethoven", "Carl"};
	size_t current = 0;

	public: 
		
		string getNext() override {
			
			if (current < names.size()) {
				return names[current++];
			}

			return "";
		}

};


class MockAwardCeremonyActions : public AwardCeremonyActions
{
	public:
		MOCK_METHOD(void, playAnthem, (), (override));
		MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
		MOCK_METHOD(void, awardBronze, (string recipient), (override));
		MOCK_METHOD(void, awardSilver, (string recipient), (override));
		MOCK_METHOD(void, awardGold, (string recipient), (override));
};



TEST(AwardsTest, testPerformAwardCeremony) {


	MockAwardCeremonyActions mock;
	MockRankList mockRankList;

	string GoldPlayer   = "Adam";
        string SilverPlayer = "Beethoven";
	string BronzePlayer = "Carl";

	{
	
		InSequence seq;

		EXPECT_CALL(mock, playAnthem());
		EXPECT_CALL(mock, awardBronze(BronzePlayer));
		EXPECT_CALL(mock, awardSilver(SilverPlayer));
		EXPECT_CALL(mock, awardGold(GoldPlayer));
		EXPECT_CALL(mock, turnOffTheLightsAndGoHome());

	}

	performAwardCeremony(mockRankList, mock);
}