#ifndef STUDENT_H
#define STUDENT_H


#ifndef STRING_H
#define STRING_H
#include <string>
#endif

#include "date.h"

class Student{
private:
    unsigned int facNum;
    std::string name;
    float avGrade;
    Date birthDate;
    unsigned int potoche;
    unsigned int group;
public:
    Student();

    Student(unsigned int facNum,std::string name, float avGrade,const Date &birthDate, unsigned int potoche, unsigned int group);

    unsigned int getFacNum() const;

    void setFacNum(unsigned int value);

    std::string getName() const;

    void setName(const std::string &value);

    float getAvGrade() const;

    void setAvGrade(float value);

    Date getBirthDate() const;

    void setBirthDate(Date& value);

    int getStudentYears(Date& currentYear);

    unsigned int getPotoche() const;

    void setPotoche(unsigned int value);

    unsigned int getGroup() const;
    void setGroup(unsigned int value);

    bool operator ==(Student &student);

    friend std::istream& operator >>(std::istream& is,Student &student);
    friend std::ostream& operator <<(std::ostream& os,Student &student);

};
#endif // STUDENT_H

