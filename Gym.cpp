#pragma once

#include "Gym.h"


//--
int Gym::Member::memberId = 0;
//--
Gym::Member::Member(std::string n, int a):
    name(n), age(a)
{
    ++memberId;
}
//--
Gym::Member::~Member()
{
    std::cout << "Member destructor called!" << std::endl;
}
//--
void Gym::Member::logActivity(const std::string& activity) 
{
    lastActivity = activity;
}
//--
void Gym::Member::printDetails() const
{
    for(int i = 0; i < 20; ++i)
    {
        std::cout << "-";        
    }
    std::cout << "\nMember ID: " << memberId << ", Name: " << name << ", Age: " << age << ", Active: " << (isActive ? "Yes": "No") << std::endl;
    for(int i = 0; i < 20; ++i)
    {
        std::cout << "-";        
    }
    std::cout << "\nLast activity: " << lastActivity << std::endl;
}
//--
void Gym::Member::setActiveStatus(const bool& active)
{
    isActive = active;
}
//--
Gym::Gym(std::string name, bool open) : 
    gymName(name), isOpen(open)
{
}
//--
Gym::~Gym()
{
    std::cout << "Gym destructor called!" << std::endl;
}
//--
void Gym::registerMember(const Member& member) 
{
    lastRegisteredMembersName = member.name;
    ++totalMembers;
}
//--
void Gym::toggleGymStatus() 
{
    isOpen = !isOpen;
}
//--
void Gym::calculateRevenue() 
{
    double maintenanceCost = 0.0;
    for (int i = 0; i < totalMembers; ++i) 
    {
        maintenanceCost += 0.5 * i;  // Each member increases the maintenance cost by 0.5
    }
    monthlyRevenue = (totalMembers * membershipPrice) - maintenanceCost;
}