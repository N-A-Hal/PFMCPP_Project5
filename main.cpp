/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */






/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
#include <string>
#include "LeakedObjectDetector.h"

struct Loan
{
    double loanAmount;
    double interestRateInPercent;
    double numPayments;
    bool isSecured;
    double totalPayment = 0;

    Loan(double amount, double rate, double numPay, bool secured);
    ~Loan();
    void calculateTotalPayment();
    double calculateOverpayment();
    void printOverpayment();

    JUCE_LEAK_DETECTOR(Loan)
};
//--
Loan::Loan(double amount, double rate, double numPay, bool secured):
    loanAmount(amount), interestRateInPercent(rate), numPayments(numPay), isSecured(secured)
{
    if(isSecured)
    {
        interestRateInPercent *= 0.9;
    }
    calculateTotalPayment();
}
//--
Loan::~Loan()
{
    std::cout << "Loan destructor called!" << std::endl;
}
//--
void Loan::calculateTotalPayment()
{
    double currentLoanAmount = loanAmount;
    totalPayment = 0;
    for(unsigned int i = 0; i < numPayments; ++i)
    {
        double interestPayment = currentLoanAmount * (interestRateInPercent / 12 / 100.0);
        double principalPayment = loanAmount / numPayments;
        double payment = interestPayment + principalPayment;

        totalPayment += payment;
        currentLoanAmount -= principalPayment;
    }
}
//--
double Loan::calculateOverpayment()
{
    return totalPayment - loanAmount;
}
//--
void Loan::printOverpayment()
{
    std::cout << "Loan amount: " << this->loanAmount << "\nOverpayment: " << this->calculateOverpayment() << std::endl;
}
//--
struct LoanWrapper
{
    LoanWrapper( Loan* ptr ) : pointerToLoan( ptr ) {}
    ~LoanWrapper()
    {
        delete pointerToLoan;
    }

    Loan* pointerToLoan = nullptr;
};
//--
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
        void logActivity(std::string activity);
        void printDetails() const;
        void setActiveStatus(bool active);

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
void Gym::Member::logActivity(std::string activity) 
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
void Gym::Member::setActiveStatus(bool active)
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
//--
struct MemberWrapper
{
    MemberWrapper( Gym::Member* ptr ) : pointerToMember( ptr ) {}
    ~MemberWrapper()
    {
        delete pointerToMember;
    }

    Gym::Member* pointerToMember = nullptr;
};
//--
struct GymWrapper
{
    GymWrapper( Gym* ptr ) : pointerToGym( ptr ) {}
    ~GymWrapper()
    {
        delete pointerToGym;
    }

    Gym* pointerToGym = nullptr;
};
//--
struct Classroom 
{
    struct Student 
    {
        std::string name;
        static int studentId;
        int age;
        double averageGrade = 0; //grades for 0 to 100
        char finalGrade = 'F';

        Student(std::string n, int a);
        ~Student();
        void printDetails() const;
        void setFinalGrade();
        void setAverageGrade(double grade);

        JUCE_LEAK_DETECTOR(Student)
    };

    std::string lastRegisteredStudentName;
    std::string classroomName;
    int totalStudents = 0;
    double averageGradeLastYear;
    char minimumLetterGradeToPass;

    Classroom(std::string name, double averGrade, char minGrade);
    ~Classroom();
    void registerStudent(const Student& student);
    static char convertGradeIntoLetterGrade(double grade);
    void printClassDetails() const;

    JUCE_LEAK_DETECTOR(Classroom)
};
//--
int Classroom::Student::studentId = 0;
//--
Classroom::Student::Student(std::string n, int a) : name(n), age(a)
{
    ++studentId;
}
//--
Classroom::Student::~Student()
{
    std::cout << "Student destructor called!" << std::endl;
}
//--
void Classroom::Student::printDetails() const
{
    for(int i = 0; i < 20; ++i)
    {
        std::cout << "-";        
    }
    std::cout << "\nStudent ID: " << studentId << ", Name: " << name << ", Age: " << age << std::endl;
    for(int i = 0; i < 20; ++i)
    {
        std::cout << "-";        
    }
    std::cout << "\nFinal Grade: " << finalGrade << std::endl;
}
//--
void Classroom::Student::setFinalGrade()
{
    finalGrade = convertGradeIntoLetterGrade(averageGrade);
}
//--
void Classroom::Student::setAverageGrade(double grade)
{
    averageGrade = grade;
}
//--
Classroom::Classroom(std::string name, double averGrade, char minGrade) : 
    classroomName(name), averageGradeLastYear(averGrade), minimumLetterGradeToPass(minGrade)
{
}
//--
Classroom::~Classroom()
{
    std::cout << "Classroom destructor called!" << std::endl;
}
//--
void Classroom::registerStudent(const Student& student) 
{
    lastRegisteredStudentName = student.name;
    ++totalStudents;
}
//--
void Classroom::printClassDetails() const
{
    for(int i = 0; i < 20; ++i)
    {
        std::cout << "-";        
    }
    std::cout << "\nClassroom: " << classroomName << ", Total Students: " << totalStudents << std::endl;
    for(int i = 0; i < 20; ++i)
    {
        std::cout << "-";        
    }
}
//--
char Classroom::convertGradeIntoLetterGrade(double grade)
{
    if (grade >= 90) return 'A';
    else if (grade >= 80) return 'B';
    else if (grade >= 70) return 'C';
    else if (grade >= 60) return 'D';
    return 'F';
}
//--
struct StudentWrapper
{
    StudentWrapper( Classroom::Student* ptr ) : pointerToStudent( ptr ) {}
    ~StudentWrapper()
    {
        delete pointerToStudent;
    }

    Classroom::Student* pointerToStudent = nullptr;
};
//--
struct ClassroomWrapper
{
    ClassroomWrapper( Classroom* ptr ) : pointerToClassroom( ptr ) {}
    ~ClassroomWrapper()
    {
        delete pointerToClassroom;
    }

    Classroom* pointerToClassroom = nullptr;
};
//--
struct RecreationCenter 
{
    Classroom academicClassroom;
    Gym fitnessGym;

    RecreationCenter(const Classroom& classroom, const Gym& gym);
    ~RecreationCenter();

    bool isLastRegisteredPersonSame() const;
    void compareNumMembers() const;

};
//--
RecreationCenter::RecreationCenter(const Classroom& classroom, const Gym& gym)
    : academicClassroom(classroom), fitnessGym(gym)
{
    std::cout << "RecreationCenter constructor called!" << std::endl;
}
//--
RecreationCenter::~RecreationCenter()
{
    std::cout << "RecreationCenter destructor called!" << std::endl;
}
//--
bool RecreationCenter::isLastRegisteredPersonSame() const
{
    return academicClassroom.lastRegisteredStudentName == fitnessGym.lastRegisteredMembersName;
}
//--
void RecreationCenter::compareNumMembers() const
{
    if (academicClassroom.totalStudents > fitnessGym.totalMembers)
    {
        std::cout << "There are more members in the academic classroom than the gym." << std::endl;
    }
    else if (academicClassroom.totalStudents > fitnessGym.totalMembers)
    {
        std::cout << "There are more members in the gym than the academic classroom." << std::endl;
    }
    else
    {
        std::cout << "There are the same number of members in both the gym and the academic classrom." << std::endl;
    }
}
//--
struct RecreationCenterWrapper
{
    RecreationCenterWrapper( RecreationCenter* ptr ) : pointerToRecreationCenter( ptr ) {}
    ~RecreationCenterWrapper()
    {
        delete pointerToRecreationCenter;
    }

    RecreationCenter* pointerToRecreationCenter = nullptr;
};
//--
struct LoanManager 
{
    double totalPayment = 0;
    LoanManager();
    ~LoanManager();

    void addLoan(const Loan& loan);
    void printTotalPayment() const;
};
//--
LoanManager::LoanManager()
{
    std::cout << "LoanManager constructor called!" << std::endl;
}
//--
LoanManager::~LoanManager()
{
    std::cout << "LoanManager destructor called!" << std::endl;
}
//--
void LoanManager::addLoan(const Loan& loan) 
{
    totalPayment += loan.totalPayment; 
}
//--
void LoanManager::printTotalPayment() const
{
    std::cout << "Total payment: " << totalPayment << std::endl;
}
//--
struct LoanManagerWrapper
{
    LoanManagerWrapper( LoanManager* ptr ) : pointerToLoanManager( ptr ) {}
    ~LoanManagerWrapper()
    {
        delete pointerToLoanManager;
    }

    LoanManager* pointerToLoanManager = nullptr;
};
//--
int main()
{
    std::cout << "good to go!" << std::endl;

    
    LoanManagerWrapper manager(new LoanManager());

    manager.pointerToLoanManager->addLoan(Loan(2000, 5, 24, true));
    manager.pointerToLoanManager->addLoan(Loan(500, 3, 12, false));
    manager.pointerToLoanManager->addLoan(Loan(1000, 4.5, 36, true));

    manager.pointerToLoanManager->printTotalPayment();

    ClassroomWrapper calculus(new Classroom("Calculus 101", 80, 'D'));

    calculus.pointerToClassroom->registerStudent(Classroom::Student("Bob", 22));
    calculus.pointerToClassroom->registerStudent(Classroom::Student("Alice", 20));

    GymWrapper campusGym(new Gym("Campus Fitness Center", true));
    
    campusGym.pointerToGym->registerMember(Gym::Member("Charlie", 25));
    campusGym.pointerToGym->registerMember(Gym::Member("Alice", 20));

    RecreationCenterWrapper center(new RecreationCenter(*calculus.pointerToClassroom, *campusGym.pointerToGym));

    if(center.pointerToRecreationCenter->isLastRegisteredPersonSame())
    {
        std::cout << "The last registered person is the same in both the academic classroom and the gym." << std::endl;
    }
    
    center.pointerToRecreationCenter->compareNumMembers();
    

    LoanWrapper l(new Loan(5000, 6, 24, false));
    
    std::cout << "Loan amount: " << l.pointerToLoan->loanAmount << "\nOverpayment: " << l.pointerToLoan->calculateOverpayment() << std::endl;
    
    l.pointerToLoan->printOverpayment();

}
