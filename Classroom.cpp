#pragma once

#include "Classroom.h"

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
void Classroom::Student::setAverageGrade(const double& grade)
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
char Classroom::convertGradeIntoLetterGrade(const double& grade)
{
    if (grade >= 90) return 'A';
    else if (grade >= 80) return 'B';
    else if (grade >= 70) return 'C';
    else if (grade >= 60) return 'D';
    return 'F';
}