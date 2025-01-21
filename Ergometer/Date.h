#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Date
{
private:
    int tag;
    int monat;
    int jahr;

public:
    Date() : tag(9), monat(11), jahr(2001) {}

    Date(int t, int m, int j) : tag(t), monat(m), jahr(j) {}
private:
    static bool isLeapYear(int year)
    {
        if (year % 4 != 0)
            return false;
        if (year % 100 != 0)
            return true;
        if (year % 400 == 0)
            return true;
        return false;
    }

    int daysInMonth(int month, int year) const
    {
        switch (month)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 30;
        }
    }
public:
    void setzeDatum(int t, int m, int j)
    {
        tag = t;
        monat = m;
        jahr = j;
    }

    void addDays(int days)
    {
        tag += days;
        while (tag > daysInMonth(monat, jahr))
        {
            tag -= daysInMonth(monat, jahr);
            monat++;
            if (monat > 12)
            {
                monat = 1;
                jahr++;
            }
        }
    }
    void operator+(const int days)
    {
        tag += days;
        while (tag > daysInMonth(monat, jahr))
        {
            tag -= daysInMonth(monat, jahr);
            monat++;
            if (monat > 12)
            {
                monat = 1;
                jahr++;
            }
        }
    }
    void operator-(const int days)
    {
        tag -= days;
        while (tag <= 0)
        {
            monat--;
            if (monat < 1)
            {
                monat = 12;
                jahr--;
            }
            tag += daysInMonth(monat, jahr);
        }
    }

    std::string toString() const
    {
        std::ostringstream oss;
        oss << tag << "." << monat << "." << jahr;
        return oss.str();
    }

    bool operator<(const Date& other) const
    {
        if (jahr < other.jahr)
            return true;
        if (jahr == other.jahr)
        {
            if (monat < other.monat)
                return true;
            if (monat == other.monat)
            {
                return tag < other.tag;
            }
        }
        return false;
    }

    bool operator>(const Date& other) const
    {
        if (jahr > other.jahr)
            return true;
        if (jahr == other.jahr)
        {
            if (monat > other.monat)
                return true;
            if (monat == other.monat)
            {
                return tag > other.tag;
            }
        }
        return false;
    }

    bool operator==(const Date& other) const
    {
        return tag == other.tag && other.monat == monat && other.jahr == jahr;
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& date)
    {
        os << date.toString();
        return os;
    }
};