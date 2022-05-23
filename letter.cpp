//
// Created by Виктория Веселкова on 23.05.2022.
//
#include <iostream>
#include <fstream>
#include "letter.h"
#include "StreamTable.h"

std::ofstream record; //поток для записи в файл
std::ifstream read; //поток для чтения из файла

std::string CheckSenderCountry();
std::string CheckSenderCity();
std::string CheckSenderBuilding();

double CheckPrice();

std::string CheckRecipientCountry();
std::string CheckRecipientCity();
std::string CheckRecipientBuilding();

std::string CheckRecipientName();
std::string CheckRecipientSurname();
std::string CheckRecipientPatronymic();

int the_longest_Address;//для таблицы
int the_longest_FIO; //для таблицы

letter::letter(){}
letter::~letter(){}

void letter::find_by_sender(letter *Obj)
{
    std::string wantedCountry=CheckSenderCountry();
    std::string wantedCity=CheckSenderCity();
    std::string wantedBuilding=CheckSenderBuilding();

    StreamTable st(std::cout);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_FIO+2);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Recipient's address" << "Sender's address" << "Recipient's FIO" << "Price";

    bool no_any = true;


    for (int i = 0; i < count_letter; i++)
    {
        std::string Country1=Obj[i].recipient_address.country;
        std::string City1=Obj[i].recipient_address.city;
        std::string Building1=Obj[i].recipient_address.building_number;

        if ( (wantedCountry == Country1) and (wantedCity == City1) and (wantedBuilding == Building1))
        {
            st << Obj[i].recipient_address.show_pretty_address() << Obj[i].sender_address.show_pretty_address() << Obj[i].recipient_fio.show_full_fio() << Obj[i].price;
            no_any = false;
        }
    }

    if (no_any)
    {
        std::cout<<"Не найдено"<<std::endl<<std::endl;
    }
}

void sort(letter *Obj)
{
    for (int i = 0; i <  letter::count_letter; i++)
    {
        for (int j = letter::count_letter - 1; j > i; j--)
        {
            if (Obj[j].price < Obj[j - 1].price)
            {
                std::swap(Obj[j], Obj[j-1]);
            }
        }
    }
    StreamTable st(std::cout);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_FIO+2);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Address Recipient" << "Address Sender" << "FIO" << "Price";

    for (int i = 0; i < letter::count_letter; i++)
    {
        {
            st << Obj[i].recipient_address.show_pretty_address() << Obj[i].sender_address.show_pretty_address() << Obj[i].recipient_fio.show_full_fio() << Obj[i].price;
        }
    }


}

letter &letter::operator=(const letter &equal) {
    if (this == &equal)
        return *this;

    sender_address.country=equal.sender_address.country;
    sender_address.city=equal.sender_address.city;
    sender_address.building_number=equal.sender_address.building_number;

    price=equal.price;

    recipient_address.country=equal.recipient_address.country;
    recipient_address.city=equal.recipient_address.city;
    recipient_address.building_number=equal.recipient_address.building_number;

    recipient_fio.person_name=equal.recipient_fio.person_name;
    recipient_fio.person_surname=equal.recipient_fio.person_surname;
    recipient_fio.person_patronymic=equal.recipient_fio.person_patronymic;

    return *this;
}

void letter::show_data() {
    letter *Obj = this;

    StreamTable st(std::cout);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_Address+2);
    st.AddCol(the_longest_FIO+2);
    st.AddCol(15);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "Address Recipient" << "Address Sender" << "FIO" << "Price";

    for (int i = 0; i < letter::count_letter; i++)
    {
        {
            st << Obj[i].recipient_address.show_pretty_address() << Obj[i].sender_address.show_pretty_address() << Obj[i].recipient_fio.show_full_fio() << Obj[i].price;
        }
    }
}

void letter::add_data() {

    this->sender_address.country=CheckSenderCountry();
    this->sender_address.city=CheckSenderCity();
    this->sender_address.building_number=CheckSenderBuilding();

    this->recipient_address.country=CheckRecipientCountry();
    this->recipient_address.city=CheckRecipientCity();
    this->recipient_address.building_number=CheckRecipientBuilding();

    this->price=CheckPrice();

    this->recipient_fio.person_name=CheckRecipientName();
    this->recipient_fio.person_surname=CheckRecipientSurname();
    this->recipient_fio.person_patronymic=CheckRecipientPatronymic();


    if ((this->sender_address.show_pretty_address()).length() > the_longest_Address){the_longest_Address=(this->sender_address.show_pretty_address()).length();}
    if ((this->recipient_address.show_pretty_address()).length() > the_longest_Address){the_longest_Address=(this->recipient_address.show_pretty_address()).length();}
    if ((this->recipient_fio.show_full_fio()).length() > the_longest_FIO){the_longest_FIO = (this->recipient_fio.show_full_fio()).length();}
}

void letter::new_data() {
    letter *tmpletter;

    if (count_letter == 0)
    {
        letter_array = new letter[count_letter + 1];
        letter_array[count_letter].add_data();
        count_letter++;
    }
    else if(count_letter != 0)
    {

        tmpletter = new letter[count_letter+1];

        for (int i = 0; i < count_letter; i++)
        {
            tmpletter[i] = letter_array[i];
        }

        delete[] letter_array;
        letter_array = tmpletter;

        letter_array[count_letter].add_data();

        count_letter++;
    }
    else{
        std::cout<<"Ошибка в letter.cpp--new_data()"<<std::endl;
    }

}

void letter::saveDataOnDisk() {

    record.open("file.txt"); //открываю файл для ЗАПИСИ
    record<<count_letter<<std::endl; //сначала записываю количество данных в первую строку

    for (int i=0; i < count_letter; i++)
    {

        record<<supplierInfo_array[i].fio_class.person_name<<" "<<supplierInfo_array[i].fio_class.person_surname<<" "<<supplierInfo_array[i].fio_class.person_patronymic<<
              " "<<firmInfo_array[i].firm_name<<" "<<firmInfo_array[i].type_of_supplier<<" "<<firmInfo_array[i].address_class.country<<" "<<firmInfo_array[i].address_class.city<<" "<<firmInfo_array[i].address_class.building_number<<
              " "<<common_array[i].saldo<<" "<< supplierInfo_array[i].date_class.day<<" "<<supplierInfo_array[i].date_class.month<<" "<<supplierInfo_array[i].date_class.year<<std::endl;

    } //ну вот, записали

    record.close(); //закрываю файл окончательно, типа знаю хороший тон АХАХА
}

void letter::readDataFromDisk() {
    if (std::filesystem::is_empty("file.txt")){std::cout<<"Ранее добавленных объектов не найдено"<<std::endl;}
    else
    {
        read.open("file.txt"); //открываю файл для ЧТЕНИЯ
        int current_count;

        read>>current_count; //сначала записываю количество данных из первой строки в память
        count_letter=current_count;

        letter_array = new letter[count_letter];

        for(int i=0; i<count_letter; i++)
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
        std::cout<<"Количество считанных объектов: "<<count_letter<<std::endl;
    }


}






