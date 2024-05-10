/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
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
        void printDetails();
        void setActiveStatus(bool active);
    };

    std::string gymName;
    std::string lastRegisteredMembersName;
    int totalMembers = 0;
    double membershipPrice = 30.0;
    double monthlyRevenue = 0.0;
    bool isOpen;

    Gym(std::string name, bool open);
    ~Gym();
    void registerMember(Member member);
    void toggleGymStatus();
    void calculateRevenue();
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
void Gym::Member::printDetails()
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
void Gym::registerMember(Member member) 
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
        void printDetails();
        void setFinalGrade();
        void setAverageGrade(double grade);
    };

    std::string lastRegisteredStudentName;
    std::string classroomName;
    int totalStudents = 0;
    double averageGradeLastYear;
    char minimumLetterGradeToPass;

    Classroom(std::string name, double averGrade, char minGrade);
    ~Classroom();
    void registerStudent(Student student);
    static char convertGradeIntoLetterGrade(double grade);
    void printClassDetails();
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
void Classroom::Student::printDetails()
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
void Classroom::registerStudent(Student student) 
{
    lastRegisteredStudentName = student.name;
    ++totalStudents;
}
//--
void Classroom::printClassDetails()
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
struct RecreationCenter 
{
    Classroom academicClassroom;
    Gym fitnessGym;

    RecreationCenter(Classroom classroom, Gym gym);
    ~RecreationCenter();

    bool isLastRegisteredPersonSame();
    void compareNumMembers();

};
//--
RecreationCenter::RecreationCenter(Classroom classroom, Gym gym)
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
bool RecreationCenter::isLastRegisteredPersonSame()
{
    return academicClassroom.lastRegisteredStudentName == fitnessGym.lastRegisteredMembersName;
}
//--
void RecreationCenter::compareNumMembers()
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
struct LoanManager 
{
    double totalPayment = 0;
    LoanManager();
    ~LoanManager();

    void addLoan(Loan loan);
    void printTotalPayment();
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
void LoanManager::addLoan(Loan loan) 
{
    totalPayment += loan.totalPayment; 
}
//--
void LoanManager::printTotalPayment() 
{
    std::cout << "Total payment: " << totalPayment << std::endl;
}
//--
int main()
{
    std::cout << "good to go!" << std::endl;

    
    LoanManager manager;

    manager.addLoan(Loan(2000, 5, 24, true));
    manager.addLoan(Loan(500, 3, 12, false));
    manager.addLoan(Loan(1000, 4.5, 36, true));

    manager.printTotalPayment();

    Classroom calculus("Calculus 101", 80, 'D');
    calculus.registerStudent(Classroom::Student("Bob", 22));
    calculus.registerStudent(Classroom::Student("Alice", 20));

    Gym campusGym("Campus Fitness Center", true);
    campusGym.registerMember(Gym::Member("Charlie", 25));
    campusGym.registerMember(Gym::Member("Alice", 20));

    RecreationCenter center(calculus, campusGym);

    if(center.isLastRegisteredPersonSame())
    {
        std::cout << "The last registered person is the same in both the academic classroom and the gym." << std::endl;
    }
    
    center.compareNumMembers();
    
    
    Loan l = Loan(5000, 6, 24, false);
    
    std::cout << "Loan amount: " << l.loanAmount << "\nOverpayment: " << l.calculateOverpayment() << std::endl;
    
    l.printOverpayment();

}
