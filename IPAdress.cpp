#include "IPAdress.h"

IPAdress :: IPAdress(unsigned char a1, unsigned char a2, unsigned char a3, unsigned char a4)
{
    IP[0] = a1;
    IP[1] = a2;
    IP[2] = a3;
    IP[3] = a4;
}

IPAdress :: IPAdress() : IPAdress(0, 0, 0, 0) {};

IPAdress operator+(const IPAdress &lhv, const IPAdress &rhv) {
    IPAdress result;
    unsigned short a, b, sum;
    for  (short i = 0; i < 4; ++i) { //выполняем сложение по модулю 256 каждого из 4х битов
        a = (unsigned short) lhv.IP[i];
        b = (unsigned short) rhv.IP[i];
        sum = a + b;
        if (sum >= 256) sum %= 256;
        result.IP[i] = (unsigned char) sum;
    }
    return(result);
}

IPAdress operator-(const IPAdress &lhv, const IPAdress &rhv) {
    IPAdress result;
    unsigned short a, b, diff;
    for (short i = 0; i < 4; ++i) { //выполняем вычитание по модулю 256 каждого из 4х битов
        a = (unsigned short) lhv.IP[i];
        b = (unsigned short) rhv.IP[i];
        a += 256;
        diff = a - b;
        if (diff >= 256) diff %= 256;
        result.IP[i] = (unsigned char) diff;
    }
    return(result);
}

bool operator==(const IPAdress &lhv, const IPAdress &rhv) {
    if (lhv.value == rhv.value) return(true);
    else return(false);
}

bool operator!=(const IPAdress &lhv, const IPAdress &rhv) {
    return(!(lhv == rhv));
}

bool operator<(const IPAdress &lhv, const IPAdress &rhv) {
    if (lhv.value < rhv.value) return(true);
    else return(false);
}

bool operator>(const IPAdress &lhv, const IPAdress &rhv) {
    return(!(lhv < rhv));
}

bool operator<=(const IPAdress &lhv, const IPAdress &rhv) {
    if ((lhv == rhv) || (lhv < rhv)) return(true);
    else return(false);
}

bool operator>=(const IPAdress &lhv, const IPAdress &rhv) {
    if ((lhv == rhv) || (lhv > rhv)) return(true);
    else return(false);
}

bool CheckHost (const IPAdress &Net, const IPAdress &Mask, const IPAdress &Host) {
    IPAdress Net_Host;
    for (short i = 0; i < 4; ++i) {
        Net_Host.IP[i] = Net.IP[i] & Mask.IP[i]; //выполняем побитовое И каждого байта IP с каждым байтом маски
    }
    if (Net_Host == Host) return(true); //если в результате адрес равен поступившему адресу, следовательно принадлежит
    else return(false);
}

std::ostream &operator<<(std::ostream &os, const IPAdress &Adress) {
    os << (unsigned short) Adress.IP[0] << "." << (unsigned short) Adress.IP[1] << ".";
    os << (unsigned short) Adress.IP[2] << "." << (unsigned short) Adress.IP[3];
    return (os);
}

