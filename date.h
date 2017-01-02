#ifndef DATE_H
#define DATE_H

#ifndef IO_H
#define IO_H
#include <iostream>
#endif

class Student;

class Date{
private:
    unsigned short day=0;
    unsigned short month=0;
    unsigned int year=0;
    bool leapYear(unsigned int year);
    void validate(unsigned short day, unsigned short month, unsigned int year);
public:
    Date();

    Date(unsigned short day, unsigned short month, unsigned int year);

    void setDay(unsigned short day);

    void setMonth(unsigned short month);

    void setYear(unsigned int year);

    unsigned short getDay();

    unsigned short getMonth();

    unsigned int getYear();

    void operator=(Date& date);

    static Date getCurrentDate(){
        time_t t = time(0);
        struct tm * now = localtime( & t );
        Date date(now->tm_mday,now->tm_mon+1,now->tm_year+1900);

        return date;
    }

    bool operator ==(Date& date);

    bool operator !=(Date date);

    friend std::istream& operator>>(std::istream& is,Student &student);
};

std::istream& operator>>(std::istream& is,Date& date);

std::ostream& operator<<(std::ostream& os,Date& date);

#endif // DATE_H
