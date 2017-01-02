#include <QCoreApplication>
#include "student.h"
#include "date.h"
#include "constants.h"
#include <fstream>
#include <vector>

#ifndef IO_H
#define IO_H
#include <iostream>
#endif

typedef void function(std::vector<Student>&);

using namespace std;

void readParams(vector<Student>& students){
    fstream fin;
    int loops;

    Student student;

    fin.open(FILE_NAME.c_str(),ios::in);

    if(!fin.is_open()){
        cout<<"Can't find";
        fin.close();
        return;
    }

    fin>>loops;

    while (loops--){
        fin>>student;
        students.push_back(student);
    }

    fin.close();

}

void printMaxGradeStrundet(vector<Student> &students){
    int potochi;
    cin>>potochi;
    Student max;
    max=students.front();
    for(int i{0};i<students.size();i++){
        if(students[i].getPotoche()==potochi){
            if(students[i].getAvGrade()>max.getAvGrade()){
                max=students[i];
            }
        }
    }

    cout<<max;
}



void printAllBetween18And26(vector<Student> &students){
     Date currentDate=Date::getCurrentDate();
     for(int i{0};i<students.size();i++){
        if(students[i].getStudentYears(currentDate)>18&&students[i].getStudentYears(currentDate)<26){
            cout<<students[i];
        }
    }
}

void printStudentYears(vector<Student> &students){
    Student sStudent;
    Date currentDate = Date::getCurrentDate();
    cin>>sStudent;
    for(int i{0};i<students.size();i++){
        if(sStudent==students[i]){
            cout<<sStudent.getStudentYears(currentDate);
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int i;
    vector<Student> students;
    function *p[3]={printMaxGradeStrundet,printAllBetween18And26,printStudentYears};

    readParams(students);

    while(1){
        cout<<"Choose option:"<<endl;
        cout<<"1. Print Student with highest grade"<<endl;
        cout<<"2. Ptint Students between 18 and 26 years"<<endl;
        cout<<"3. Print Student years"<<endl;
        cin>>i;
        p[i-1](students);

    }

    return a.exec();
}











