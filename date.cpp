#include "date.h"
#include <ctime>
#define toDigit(c) (c-'0')


bool Date::leapYear(unsigned int year){
    if(year%4==0){
        return true;
    }else{
        return false;
    }
}
void Date::validate(unsigned short day, unsigned short month, unsigned int year){
    switch(month)
    {
    case 2:
        if(leapYear(year)) {
            if(day > 29){
                throw std::logic_error("Nevalidna data bonak");
            }
        }
        else{
            if(day > 28){
                throw std::logic_error("Nevalidna data bonak");
            }
        }
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if(day > 31){
            throw std::logic_error("Nevalidna data bonak");
        }break;
    case 4: case 6: case 9: case 11:
        if(day > 30){
            throw std::logic_error("Nevalidna data bonak");
        }break;
    default:
        throw std::logic_error("Nevaliden mesec bonache");
        break;
    }
}

Date::Date(){

}

Date::Date(unsigned short day, unsigned short month, unsigned int year){
    this->validate(day,month,year);

    this->day=day;
    this->month=month;
    this->year=year;
}

void Date::setDay(unsigned short day){
    if(month!=0&&year!=0){
        this->validate(day,this->month,this->year);
    }
    this->day=day;
}

void Date::setMonth(unsigned short month){
    if(day!=0&&year!=0){
        this->validate(this->day,month,this->year);
    }
    this->month=month;
}

void Date::setYear(unsigned int year){
    if(day!=0&&month!=0){
        this->validate(this->day,this->month,year);
    }
    this->year=year;
}

unsigned short Date::getDay(){
    return day;
}

unsigned short Date::getMonth(){
    return month;
}

unsigned int Date::getYear(){
    return year;
}



std::istream& operator >>(std::istream& is,Date& date){

    std::string sDate;

    is>>sDate;
    unsigned short day=0,month=0;
    unsigned int year=0,i=0;

    const char* p=sDate.c_str();

    while(*p != '.'){
        day=day*10+toDigit(*p);
        p++;
    }

    p++;

    while(*p!='.'){
        month=month*10+toDigit(*p);
        p++;
    }

    p++;

    while(*p!='\0'){
        year=year*10 + toDigit(*p);
        p++;
    }

    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);

    return is;
}

bool Date::operator ==(Date& date){
 if(this->day!=date.getDay()){
     return false;
 }else if(this->month!=date.getMonth()){
     return false;
 }else if(this->year!=date.getYear()){
     return false;
 }
 return true;
}

bool Date::operator !=(Date date){
    return !this->operator ==(date);
}

std::ostream& operator<<(std::ostream& os,Date& date){
    os<<date.getDay()<<"/"<<date.getMonth()<<"/"<<date.getYear()<<std::endl;
    return os;
}

void Date::operator =(Date& date){
    this->day=date.getDay();
    this->month=date.getMonth();
    this->year=date.getYear();
}



