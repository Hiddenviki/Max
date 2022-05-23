#include <iostream>
#include <fstream>

#include "common.h"
#include "Address.h"
#include "letter.h"
#include "letter1.h"



int CheckMenu()
{
    while (true)
    {
        std::cout << "___________Диалоговое окно:__________" << std::endl;
        std::cout << "1-----Показать таблицу с данными-----" << std::endl;
        std::cout << "2-----Добавить новое-----------------" << std::endl;
        std::cout << "3-----Поиск письма по получателю----- " << std::endl;
        std::cout << "4-----Сортировать по росту стоимости-" << std::endl;
        std::cout << "5-----Сохранить и выйти--------------" << std::endl;
        std::cout << "________Введите число от 1 до 5______" << std::endl;
        int c;
        std::cin >> c;

        if (std::cin.fail() or (c < 1) or (c > 5))
        {
            std::cout<<"Вы ввели хуйню, надо вводить от 1 до 5. Давайте заново"<<std::endl;
            std::cin.clear();
            std::cin.ignore(32767,'\n');
        }
        else
            return c;
    }
}

static int the_longest_Address;//для таблицы
static int the_longest_FIO; //для таблицы

int main() {

    the_longest_Address=30;
    the_longest_FIO=30;

    letter letter_element;
    letter1 letter1_element;

    letter_element.readDataFromDisk();
    letter1_element.readDataFromDisk();

    int c;
    do {
        c=CheckMenu();
        switch (c)
        {
            case 1:
                std::cout<<" "<<std::endl;
                std::cout<<"Table 1:"<<std::endl;
                letter_element.show_data();
                std::cout<<" "<<std::endl;
                std::cout<<"Table 2:"<<std::endl;
                letter1_element.show_data();
                std::cout<<" "<<std::endl;
                break;

            case 2:
                letter_element.new_data();
                letter1_element.new_data();
                break;

            case 3:
                letter_element.find_by_sender(&letter_element); //хз работает ли
                break;

            case 4:
                sort(&letter_element); //хз работает ли
                break;

            case 5:
                //если что, они сохраняются в 2 разных файла (и считываются из разных)
                letter_element.saveDataOnDisk(); //этот в file.txt
                letter1_element.saveDataOnDisk(); //а этот в file1.txt
                break;

        }
    } while (c != 5);





    return 0;
}
