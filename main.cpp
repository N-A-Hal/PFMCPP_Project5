/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

/*
 copied UDT 1:
 */

/*
 copied UDT 2:
 */

/*
 copied UDT 3:
 */

/*
 new UDT 4:
 with 2 member functions
 */

/*
 new UDT 5:
 with 2 member functions
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

}
