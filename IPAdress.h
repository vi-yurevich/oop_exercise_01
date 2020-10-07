
#pragma once
#ifndef OOP_EXERCISE_01_IPADRESS_H
#define OOP_EXERCISE_01_IPADRESS_H

#include <iostream>

union IPAdress {
    unsigned char IP[4];
    unsigned int value;

    IPAdress(unsigned char a1, unsigned char a2, unsigned char a3, unsigned char a4);
    IPAdress();

    friend IPAdress operator+(const IPAdress& lhv, const IPAdress& rhv);
    friend IPAdress operator-(const IPAdress& lhv, const IPAdress& rhv);
    friend bool operator==(const IPAdress& lhv, const IPAdress& rhv);
    friend bool operator!=(const IPAdress& lhv, const IPAdress& rhv);
    friend bool operator<(const IPAdress& lhv, const IPAdress& rhv);
    friend bool operator>(const IPAdress& lhv, const IPAdress& rhv);
    friend bool operator<=(const IPAdress& lhv, const IPAdress& rhv);
    friend bool operator>=(const IPAdress& lhv, const IPAdress& rhv);
    friend bool CheckHost (const IPAdress &Net, const IPAdress &Mask, const IPAdress &Host);
    friend std::ostream &operator<<(std::ostream &os, const IPAdress &Adress);
};

IPAdress operator+(const IPAdress& lhv, const IPAdress& rhv);
IPAdress operator-(const IPAdress& lhv, const IPAdress& rhv);
bool operator==(const IPAdress& lhv, const IPAdress& rhv);
bool operator!=(const IPAdress& lhv, const IPAdress& rhv);
bool operator<(const IPAdress& lhv, const IPAdress& rhv);
bool operator>(const IPAdress& lhv, const IPAdress& rhv);
bool operator<=(const IPAdress& lhv, const IPAdress& rhv);
bool operator>=(const IPAdress& lhv, const IPAdress& rhv);
bool CheckHost (const IPAdress &Net, const IPAdress &Mask, const IPAdress &Host);

#endif //OOP_EXERCISE_01_IPADRESS_H
