#pragma once

#include "LeakedObjectDetector.h"


struct Gym 
{
    struct Member 
    {
        std::string name;
        static int memberId;
        int age;
        bool isActive = true;
        std::string lastActivity;

        Member(std::string n, int a);
        ~Member();
        void logActivity(const std::string& activity);
        void printDetails() const;
        void setActiveStatus(const bool& active);

        JUCE_LEAK_DETECTOR(Member)
    };

    std::string gymName;
    std::string lastRegisteredMembersName;
    int totalMembers = 0;
    double membershipPrice = 30.0;
    double monthlyRevenue = 0.0;
    bool isOpen;

    Gym(std::string name, bool open);
    ~Gym();
    void registerMember(const Member& member);
    void toggleGymStatus();
    void calculateRevenue();

    JUCE_LEAK_DETECTOR(Gym)
};
