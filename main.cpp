/*
 Юревич Виталий М80-207Б
 Создать класс IPAddress для работы с адресом в интернете.
 Класс состоит из четырех чисел unsigned char (a,b,c,d).
 Реализовать арифметические операции сложения, вычитания, а также операции сравнения
 (для сравнения на больше/меньше считать что левые байты главнее т.е. вначале сравниваются первые байты,
 потом вторые и т.д.).
 Также реализовать функцию, которая будет определять принадлежность адреса к подсети
 по адресу подсети (a1,b1,c1,d1) и битовой маске подсети (a2,b2,c2,d2).
 Например, адрес 192.168.1.30 принадлежит подсети 192.168.0.0 с маской 255.255.0.0.
*/

#include <iostream>
#include <limits>
#include "IPAdress.h"

void EnterAdress(IPAdress &Adress) {
    bool check; //идентификатор правильного ввода
    unsigned short IP[4];
    for (short i = 0; i < 4; ++i) {
        check = true;
        while(check)
        {
            std::cout << "Vvedite " << i + 1 << " bit: ";
            std::cin >> IP[i];
            if (std::cin.fail()) { //контроль ввода
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Oshibka vvoda. Pvtorite vvod." << std::endl;
            }
            else if (IP[i] >= 256) { //контроль ввода
                std::cout << "Oshibka vvoda. Pvtorite vvod." << std::endl;
            }
            else {
                Adress.IP[i] = (unsigned char) IP[i];
                check = false;
            }
        }
    }
}


int main() {
    unsigned int menu = 1;
    IPAdress ob1, ob2, ob3;
    bool check; //идентификатор правильного выбора пункта меню
    bool key = false; //ключ, указывающий был ли введён хотя бы один IP адрес для работы

    while (menu != 0) {
        switch(menu)
        {
            case 1: //вывод меню
                std::cout << "1 - Vyvesti meny\n2 - Vvesti IP adres\n3 - Pribavit' drygoi adres";
                std::cout << "\n4 - Vychest' drygoi adres\n5 - Sravnit' s drygim adresom";
                std::cout << "\n6 - Proverit' prinadlejnost' k podseti s pomosh'u bitivoi maski";
                std::cout << "\n7 - Vyvesti tekyshii adres";
                std::cout << "\n0 - Vyhod iz programmy" << std::endl;
                break;
            case 2: //ввести IP адрес
                std::cout << "Vvedite IP adres.\n";
                EnterAdress(ob1);
                key = true;
                std::cout << "Vveden IP adres: " << ob1 << std::endl;
                break;
            case 3: //сложить с другим IP адресом
                if (!key) {
                    std::cout << "Snachala neobhodimo vvesti adres." << std::endl;
                    break;
                }
                std::cout << "Vvedite IP adres dlya slojenia.\n";
                EnterAdress(ob2);
                ob1 = ob1 + ob2;
                break;
            case 4: //вычесть другой адрес
                if (!key) {
                    std::cout << "Snachala neobhodimo vvesti adres." << std::endl;
                    break;
                }
                std::cout << "Vvedite IP adres dlya vychetania.\n";
                EnterAdress(ob2);
                ob1 = ob1 - ob2;
                std::cout << "\nResultat vychetania adresov: " << ob1 << std::endl;
                break;
            case 5: //сравнить два адреса
                if (!key) {
                    std::cout << "Snachala neobhodimo vvesti adres." << std::endl;
                    break;
                }
                std::cout << "Vvedite IP adres dlya sravnenia.\n";
                EnterAdress(ob2);
                std::cout << "\nResultat sravnenia adresov: ";
                if (ob1 == ob2) std::cout << ob1 << "==" << ob2 << std::endl;
                else if (ob1 < ob2) std::cout << ob1 << "<" << ob2 << std::endl;
                else if (ob1 > ob2) std::cout << ob1 << ">" << ob2 << std::endl;
                break;
            case 6: //провекра принадлежности к подсети
                if (!key) {
                    std::cout << "Snachala neobhodimo vvesti adres." << std::endl;
                    break;
                }
                std::cout << "Vvedite IP adres podseti.\n";
                EnterAdress(ob3);
                std::cout << "Vvedite bitovyu masky.\n";
                EnterAdress(ob2);
                check = CheckHost(ob1, ob2, ob3);
                if (check) std::cout << ob1 << " prinadlejit podseti " << ob3 << std::endl;
                else std::cout  << ob1 << " NE prinadlejit podseti " << ob3 << std::endl;
                break;
            case 7: //вывод адреса
                if (!key) {
                    std::cout << "Snachala neobhodimo vvesti adres." << std::endl;
                    break;
                }
                std::cout << "Tekushii adres: " << ob1 << std::endl;
                break;
            default: //сообщение об ошибке
                std::cout << "Neverno vybran pynkt v menu. Poprobuite eshe raz." << std::endl;
                break;
        }
        check = true;
        while(check) {
            std::cout << "Vyberete pynkt menu: ";
            std::cin >> menu;
            if (std::cin.fail()) { //контроль вводимых данных
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Neverno vybran pynkt v menu. Poprobuite eshe raz." << std::endl;
            }
            else check = false;
        }
    }
    return(0);
}