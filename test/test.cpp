#include "gtest/gtest.h"
#include "gmock/gmock.h"
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