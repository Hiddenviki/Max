//
// Created by Виктория Веселкова on 23.05.2022.
//

#include <iostream>
#include <fstream>
#include "letter1.h"
#include "StreamTable.h"

std::ofstream record; //поток для записи в файл
std::ifstream read; //поток для чтения из файла

int CheckDay();
int CheckYear();
std::string CheckMonth();

std::string CheckRecipientCountry();
std::string CheckRecipientCity();
std::string CheckRecipientBuilding();

std::string CheckRecipientName();
std::string CheckRecipientSurname();
std::string CheckRecipientPatronymic();

int the_longest_Address;//для таблицы
int the_longest_FIO; //для таблицы

void letter1::show_data1()
{
    letter1 *Obj = this;

    StreamTable st(std::cout);
    st.AddCol(22);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_FIO+2);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Date" << "Recipient's address" << " Recipient's FIO" ;

    for (int i = 0; i < letter1::count_letter1; i++)
    {
        {
            st << Obj[i].when_get.show_pretty_date() << Obj[i].recipient_address.show_pretty_address() << Obj[i].recipient_fio.show_full_fio();
        }
    }
}

void letter1::add_data()
{

    this->when_get.day=CheckDay();
    this->when_get.month=CheckMonth();
    this->when_get.year=CheckYear();

    this->recipient_address.country=CheckRecipientCountry();
    this->recipient_address.city=CheckRecipientCity();
    this->recipient_address.building_number=CheckRecipientBuilding();

    this->recipient_fio.person_name=CheckRecipientName();
    this->recipient_fio.person_surname=CheckRecipientSurname();
    this->recipient_fio.person_patronymic=CheckRecipientPatronymic();

    if ((this->recipient_address.show_pretty_address()).length() > the_longest_Address){the_longest_Address=(this->recipient_address.show_pretty_address()).length();}
    if ((this->recipient_fio.show_full_fio()).length() > the_longest_FIO){the_longest_FIO = (this->recipient_fio.show_full_fio()).length();}
}

letter1 &letter1::operator=(const letter1 &equal) {
    if (this == &equal)
        return *this;

    recipient_address.country=equal.recipient_address.country;
    recipient_address.city=equal.recipient_address.city;
    recipient_address.building_number=equal.recipient_address.building_number;

    recipient_fio.person_name=equal.recipient_fio.person_name;
    recipient_fio.person_surname=equal.recipient_fio.person_surname;
    recipient_fio.person_patronymic=equal.recipient_fio.person_patronymic;

    when_get.day=equal.when_get.day;
    when_get.month=equal.when_get.month;
    when_get.year=equal.when_get.year;

    return *this;
}

void letter1::new_data() {
    letter1 *tmpletter1;

    if (count_letter1 == 0)
    {
        letter1_array = new letter1[count_letter1 + 1];
        letter1_array[count_letter1].add_data();
        count_letter1++;
    }
    else if(count_letter1 != 0)
    {

        tmpletter1 = new letter1[count_letter1+1];

        for (int i = 0; i < count_letter1; i++)
        {
            tmpletter1[i] = letter1_array[i];
        }

        delete[] letter1_array;
        letter1_array = tmpletter1;

        letter1_array[count_letter1].add_data();

        count_letter1++;
    }
    else{
        std::cout<<"Ошибка в letter1.cpp--new_data()"<<std::endl;
    }

}

void letter1::saveDataOnDisk() {

    record.open("file1.txt"); //открываю файл для ЗАПИСИ
    record<<count_letter1<<std::endl; //сначала записываю количество данных в первую строку

    for (int i=0; i < count_letter1; i++)
    {

        record<<supplierInfo_array[i].fio_class.person_name<<" "<<supplierInfo_array[i].fio_class.person_surname<<" "<<supplierInfo_array[i].fio_class.person_patronymic<<
              " "<<firmInfo_array[i].firm_name<<" "<<firmInfo_array[i].type_of_supplier<<" "<<firmInfo_array[i].address_class.country<<" "<<firmInfo_array[i].address_class.city<<" "<<firmInfo_array[i].address_class.building_number<<
              " "<<common_array[i].saldo<<" "<< supplierInfo_array[i].date_class.day<<" "<<supplierInfo_array[i].date_class.month<<" "<<supplierInfo_array[i].date_class.year<<std::endl;

    } //ну вот, записали

    record.close(); //закрываю файл окончательно, типа знаю хороший тон АХАХА
}

void letter1::readDataFromDisk() {
    if (std::filesystem::is_empty("file1.txt")){std::cout<<"Ранее добавленных объектов1 не найдено"<<std::endl;}
    else
    {
        read.open("file1.txt"); //открываю файл для ЧТЕНИЯ
        int current_count;

        read>>current_count; //сначала записываю количество данных из первой строки в память
        count_letter1=current_count;

        letter1_array = new letter1[count_letter1];

        for(int i=0; i<count_letter1; i++)
        {
            std::string personName,personSurname,personPatronymic,firmName,country,city,building,current_month;
            double new_saldo;
            int current_type,current_day,current_year;
            read >>personName>>personSurname>>personPatronymic>>firmName>>current_type>>country>>city>>building>>new_saldo
                 >>current_day>>current_month>>current_year;

            supplierInfo_array[i].fio_class.person_name = personName;
            supplierInfo_array[i].fio_class.person_surname = personSurname;
            supplierInfo_array[i].fio_class.person_patronymic = personPatronymic;

            supplierInfo_array[i].date_class.day = current_day;
            supplierInfo_array[i].date_class.month = current_month;
            supplierInfo_array[i].date_class.year = current_year;

            firmInfo_array[i].firm_name = firmName;
            firmInfo_array[i].type_of_supplier = (current_type == 1 ? Firm_info::RAW_MATERIAL_SUPPLIER : Firm_info::EQUIPMENT_SUPPLIER);

            firmInfo_array[i].address_class.country = country;
            firmInfo_array[i].address_class.city = city;
            firmInfo_array[i].address_class.building_number = building;
            common_array[i].saldo = new_saldo;


            if ((supplierInfo_array[i].fio_class.show_pretty_fio()).length() > the_longest_FIO){the_longest_FIO=(supplierInfo_array[i].fio_class.show_pretty_fio()).length();}
            if ((firmInfo_array[i].firm_name).length() > the_longest_Name){the_longest_Name=(firmInfo_array[i].firm_name).length();}
            if((firmInfo_array[i].address_class.show_pretty_address()).length()>the_longest_Address){the_longest_Address = (firmInfo_array[i].address_class.show_pretty_address()).length();}
        }
        read.close();
        std::cout<<"Количество считанных объектов1: "<<count_letter1<<std::endl;
    }
}

