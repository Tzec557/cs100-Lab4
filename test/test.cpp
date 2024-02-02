#include "gtest/gtest.h"
#include "../include/Awards.h"  

using awards::RankList;
using awards::AwardCeremonyActions;

class RankListStub : public awards::RankList {
public:
    RankListStub() : currentIndex(0) {
        names.push_back("Alice");
        names.push_back("Bob");
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
    size_t currentIndex;
};

#ifndef MOCK_AWARD_CEREMONY_ACTIONS_H
#define MOCK_AWARD_CEREMONY_ACTIONS_H

class MockAwardCeremonyActions : public awards::AwardCeremonyActions {
public:
    MOCK_METHOD(void, playAnthem, (), (override));
    MOCK_METHOD(void, awardBronze, (const std::string& name), (override));
    MOCK_METHOD(void, awardSilver, (const std::string& name), (override));
    MOCK_METHOD(void, awardGold, (const std::string& name), (override));
    MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
};
#endif

TEST(AwardsTests, PerformAwardCeremonyCallsMethodsInCorrectOrder) {
    
    RankListStub rankListStub;
    MockAwardCeremonyActions mockActions;
    Awards awards(&mockActions, &rankListStub);

    EXPECT_CALL(mockActions, playAnthem()).Times(1);
    EXPECT_CALL(mockActions, awardBronze("Alice")).Times(1);
    EXPECT_CALL(mockActions, awardSilver("Bob")).Times(1);
    EXPECT_CALL(mockActions, awardGold("Charlie")).Times(1);
    EXPECT_CALL(mockActions, turnOffTheLightsAndGoHome()).Times(1);

    
    awards.performAwardCeremony();

}