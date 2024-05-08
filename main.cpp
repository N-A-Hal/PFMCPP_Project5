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
#include <vector>
#include <string>
#include <unordered_set>

struct Loan
{
    double loanAmount;
    double interestRateInPercent;
    unsigned long numPayments;
    bool isSecured;
    std::vector<double> payments;

    Loan(double amount, double rate, unsigned long numPay, bool secured);
    ~Loan();
    void calculatePayments();
    double calculateOverpayment();
};
//--
Loan::Loan(double amount, double rate, unsigned long numPay, bool secured):
    loanAmount(amount), interestRateInPercent(rate), numPayments(numPay), isSecured(secured)
{
    if(isSecured)
    {
        interestRateInPercent *= 0.9;
    }
    calculatePayments();
}
//--
Loan::~Loan()
{
    std::cout << "Loan destructor called!" << std::endl;
}
//--
void Loan::calculatePayments()
{
    payments.clear();
    for(unsigned int i = 0; i < numPayments; i++)
        {
            double currentLoanAmount = loanAmount;
            double payment = currentLoanAmount * (interestRateInPercent / 12 / 100.0) + loanAmount / static_cast<double>(numPayments);
            currentLoanAmount -= loanAmount / static_cast<double>(numPayments);
            payments.push_back(payment);
        }
}
//--
double Loan::calculateOverpayment()
{
    double amountToPay = 0.0;
    for(unsigned int i = 0; i < numPayments; i++)
        {
            amountToPay += payments[i];
        }
    return amountToPay - loanAmount;
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
        std::vector<std::string> activityLog;

        Member(std::string n, int a);
        ~Member();
        void logActivity(const std::string& activity);
        void printDetails();
    };

    std::vector<Member> members;
    std::string gymName;
    int totalMembers = 0;
    double membershipPrice = 30.0;
    double monthlyRevenue = 0.0;
    bool isOpen;

    Gym(std::string name, bool open);
    ~Gym();
    void registerMember(const Member& member);
    void toggleGymStatus();
    void calculateRevenue();
};
//--
int Gym::Member::memberId = 0;
//--
Gym::Member::Member(std::string n, int a):
    name(n), age(a)
{
    memberId++;
}
//--
Gym::Member::~Member()
{
    std::cout << "Member destructor called!" << std::endl;
}
//--
void Gym::Member::logActivity(const std::string& activity) 
{
    activityLog.push_back(activity);
}
//--
void Gym::Member::printDetails()
{
    std::cout << "Member ID: " << memberId << ", Name: " << name << ", Age: " << age << ", Active: " << (isActive ? "Yes": "No") << std::endl;
    std::cout << "Activities Logged: ";
    for (const auto& act : activityLog) 
    {
        std::cout << act << " ";
    }
    std::cout << std::endl;
}
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
    members.push_back(member);
    totalMembers++;
}
//--
void Gym::toggleGymStatus() 
{
    isOpen = !isOpen;
}
//--
void Gym::calculateRevenue() 
{
    monthlyRevenue = totalMembers * membershipPrice;
}
//--
struct Classroom 
{
public:
    struct Student 
    {
        std::string name;
        static int studentId;
        int age;
        std::vector<double> grades; //grades for 0 to 100
        char finalGrade;

        Student(std::string n, int a);
        ~Student();
        void addGrade(double grade);
        void printDetails() const;
        double calculateAverageGrade() const;
        void setFinalGrade();
    };

    std::vector<Student> students;
    std::string classroomName;
    int totalStudents = 0;
    double averageGrade = 0;
    char averageLetterGrade;

    Classroom(std::string name);
    ~Classroom();
    void registerStudent(const Student& student);
    static char convertGradeIntoLetterGrade(double grade);
    void calculateAverageGrade();
    void printClassDetails();
};
//--
int Classroom::Student::studentId = 0;
//--
Classroom::Student::Student(std::string n, int a) : name(n), age(a)
{
    studentId++;
}
//--
Classroom::Student::~Student()
{
    std::cout << "Student destructor called!" << std::endl;
}
//--
void Classroom::Student::addGrade(double grade) 
{
    grades.push_back(grade);
}
//--
void Classroom::Student::printDetails() const
{
    std::cout << "Student ID: " << studentId << ", Name: " << name << ", Age: " << age << std::endl;
    std::cout << "Grades: ";
    for (double grade : grades) 
    {
        std::cout << grade << " ";
    }
    std::cout << "\nAverage Grade: " << calculateAverageGrade() << std::endl;
}
//--
void Classroom::Student::setFinalGrade()
{
    finalGrade = convertGradeIntoLetterGrade(Student::calculateAverageGrade());
}
//--
double Classroom::Student::calculateAverageGrade() const{
    if (grades.empty())
    {
        return 0.0;
    }
    double sum = 0.0;
    for (double grade : grades) 
    {
        sum += grade;
    }
    return sum / static_cast<double>(grades.size());
}
//--
Classroom::Classroom(std::string name) : 
    classroomName(name)
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
    students.push_back(student);
    totalStudents++;
}
//--
void Classroom::calculateAverageGrade()
{
    if (totalStudents == 0)
    {
        averageGrade = 0;
        averageLetterGrade = 'F';
        return;
    }
    double sum = 0.0;
    for (const auto& student : students)
    {
        sum += student.calculateAverageGrade();
    }
    averageGrade = sum / totalStudents;
    averageLetterGrade = convertGradeIntoLetterGrade(averageGrade);
}
//--
void Classroom::printClassDetails(){
    std::cout << "Classroom: " << classroomName << ", Total Students: " << totalStudents << std::endl;
    std::cout << "Class Average Grade: " << averageGrade << " (" << averageLetterGrade << ")" << std::endl;
    for (const Student& student : students) 
    {
        student.printDetails();
    }
}
//--
char Classroom::convertGradeIntoLetterGrade(double grade)
{
    if (grade >= 90) return 'A';
    else if (grade >= 80) return 'B';
    else if (grade >= 70) return 'C';
    else if (grade >= 60) return 'D';
    else return 'F';
}
//--
struct RecreationCenter 
{
    Classroom academicClassroom;
    Gym fitnessGym;

    RecreationCenter(const Classroom& classroom, const Gym& gym);
    ~RecreationCenter();

    double compareAverageAge() const; //returns difference between average age of students in academic classroom and average age of members in fitness gym
    void listUniqueNames() const;

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
double RecreationCenter::compareAverageAge() const 
{
    double classroomSum = 0;
    int studentCount = 0;
    for (const auto& student : academicClassroom.students) 
    {
        classroomSum += student.age;
        studentCount++;
    }

    double gymSum = 0;
    int memberCount = 0;
    for (const auto& member : fitnessGym.members) 
    {
        gymSum += member.age;
        memberCount++;
    }

    double classroomAverage = (studentCount > 0) ? classroomSum / studentCount : 0;
    double gymAverage = (memberCount > 0) ? gymSum / memberCount : 0;

    return classroomAverage - gymAverage;
}
//--
void RecreationCenter::listUniqueNames() const 
{
    std::unordered_set<std::string> uniqueNames;

    for (const auto& student : academicClassroom.students) 
    {
        uniqueNames.insert(student.name);
    }

    for (const auto& member : fitnessGym.members) 
    {
        uniqueNames.insert(member.name);
    }

    std::cout << "Unique Names in Recreation Center:" << std::endl;
    for (const auto& name : uniqueNames) 
    {
        std::cout << name << std::endl;
    }
}
//--
struct LoanManager 
{
    std::vector<Loan> loans;

    LoanManager();
    ~LoanManager();

    void addLoan(const Loan& loan);
    double calculateTotalMonthlyPaymentForNumMonth(unsigned int num) const;
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
    loans.push_back(loan);
    std::cout << "Loan added. Current number of loans: " << loans.size() << std::endl;
}
//--
double LoanManager::calculateTotalMonthlyPaymentForNumMonth(unsigned int num) const 
{
    double totalMonthlyPayment = 0.0;
    for (const auto& loan : loans) 
    {
        if (!loan.payments.empty()) 
        {
            totalMonthlyPayment += loan.payments[num];
        }
    }
    return totalMonthlyPayment;
}
//--
int main()
{
    std::cout << "good to go!" << std::endl;

    LoanManager manager;

    manager.addLoan(Loan(2000, 5, 24, true));
    manager.addLoan(Loan(500, 3, 12, false));
    manager.addLoan(Loan(1000, 4.5, 36, true));

    std::cout << "Total Monthly Payment: $" << manager.calculateTotalMonthlyPaymentForNumMonth(0) << std::endl;

    Classroom calculus("Calculus 101");
    calculus.students.push_back(Classroom::Student("Alice", 20));
    calculus.students.push_back(Classroom::Student("Bob", 22));

    Gym campusGym("Campus Fitness Center", true);
    campusGym.members.push_back(Gym::Member("Charlie", 25));
    campusGym.members.push_back(Gym::Member("Alice", 20));

    RecreationCenter center(calculus, campusGym);

    double ageDifference = center.compareAverageAge();
    std::cout << "Average age difference between classroom and gym: " << ageDifference << std::endl;

    center.listUniqueNames();

    
}
