#include "student.h"


Student::Student(){

}

Student::Student(unsigned int facNum,std::string name, float avGrade,const Date &birthDate, unsigned int potoche, unsigned int group):
    facNum(facNum),name(name),avGrade(avGrade),birthDate(birthDate),potoche(potoche),group(group){

}

int Student::getStudentYears(Date& currentYear){
    if(currentYear.getMonth()>birthDate.getMonth()||(currentYear.getMonth()==birthDate.getMonth() && currentYear.getDay()>birthDate.getDay())){
        return currentYear.getYear()-birthDate.getYear()-1;
    }else{
        return currentYear.getYear()-birthDate.getYear();
    }
}

std::string Student::getName() const
{
    return name;
}

void Student::setName(const std::string &value)
{
    name = value;
}

float Student::getAvGrade() const
{
    return avGrade;
}

void Student::setAvGrade(float value)
{
    avGrade = value;
}

Date Student::getBirthDate() const
{
    return birthDate;
}

void Student::setBirthDate(Date &value)
{
    birthDate = value;
}

unsigned int Student::getPotoche() const
{
    return potoche;
}

void Student::setPotoche(unsigned int value)
{
    potoche = value;
}

unsigned int Student::getFacNum() const
{
    return facNum;
}

unsigned int Student::getGroup() const
{
    return group;
}

void Student::setGroup(unsigned int value)
{
    group = value;
}

void Student::setFacNum(unsigned int value)
{
    facNum = value;
}

bool Student::operator ==(Student& student){
    if(this->avGrade!=student.getAvGrade()){
        return false;
    }else if(this->birthDate!=student.getBirthDate()){
        return false;
    }else if(this->facNum!=student.getFacNum()){
        return false;
    }else if(this->group!=student.getGroup()){
        return false;
    }else if(this->name!=student.getName()){
        return false;
    }else if(this->potoche!=student.getPotoche()){
        return false;
    }else {
        return true;
    }
}

std::istream& operator >>(std::istream& is,Student &student){
    std::string param_name;

    is>>param_name>>student.facNum;
    is>>param_name>>student.name;
    is>>param_name>>student.avGrade;
    is>>param_name>>student.birthDate;
    is>>param_name>>student.potoche;
    is>>param_name>>student.group;


    return is;
}

std::ostream& operator <<(std::ostream& os,Student &student){
    os<<"Name: "<<student.name<<std::endl;
    os<<"Birth Date: "<<student.birthDate<<std::endl;
    os<<"Faculty number: "<<student.facNum<<std::endl;
    os<<"Potochi: "<<student.potoche<<std::endl;
    os<<"Group: "<<student.group<<std::endl;
    os<<"Average grade: "<<student.avGrade<<std::endl;
}
