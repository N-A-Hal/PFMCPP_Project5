#pragma once

#include "LeakedObjectDetector.h"

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
        void setAverageGrade(const double& grade);

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
    static char convertGradeIntoLetterGrade(const double& grade);
    void printClassDetails() const;

    JUCE_LEAK_DETECTOR(Classroom)
};
