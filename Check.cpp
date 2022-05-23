//
// Created by Виктория Веселкова on 23.05.2022.
//

#include <iostream>
#include <vector>


int CheckDay()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "День: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <=0) or (a>31)) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"Введите нормально день\n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}
int CheckYear()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Год: ";
        int a;
        std::cin >> a;

        if (std::cin.fail() or (a <=0) or (a>2022)) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"Год нужно вводить без посторонних символов в промежутке [1,2022]\n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}

//////4 CheckMonth//////
std::vector<std::string>months {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
bool in_array(const std::string &value, const std::vector<std::string> &array)
{
    return std::find(array.begin(), array.end(), value) != array.end();
}
bool found(const std::string& any_str){
    if (in_array(any_str, months)){
        return true;
    }
    else{
        return false;
    }
}
//////4 CheckMonth//////

std::string CheckMonth()
{

    std::string str;
    bool not_found;
    do{
        std::cout<<"Месяц: ";
        std::cin>>str;

        if (not found(str)){
            std::cout<<"Месяц нужно вводить СЛОВАМИ и с БОЛЬШОЙ буквы"<<std::endl<<"Повторите ввод"<<std::endl;
            not_found = true; //не нашли
        }
        else{
            not_found = false; //опа, нашли
        }

    }while(not_found);

    return str;
}

double CheckPrice()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Цена письма: ";
        double a;
        std::cin >> a;

        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout<<"Введите нормально пожалуйста тут везде точно есть проверка \n";
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}


std::string CheckRecipientCountry()
{
    int i;
    std::string str;
    do{
        std::cout<<"Страна получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Страну нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}
std::string CheckRecipientCity()
{
    int i;
    std::string str;
    do{
        std::cout<<"Город получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Город нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}
std::string CheckRecipientBuilding()
{
    int i;
    std::string str;
    do{
        std::cout<<"Строение получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if( (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') )
                break;
        }

        if( str[i]){std::cout<<"Строение нужно вводить без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}

std::string CheckSenderCountry()
{
    int i;
    std::string str;
    do{
        std::cout<<"Страна отправителя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Страну нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}
std::string CheckSenderCity()
{
    int i;
    std::string str;
    do{
        std::cout<<"Город отправителя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Город нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}
std::string CheckSenderBuilding()
{
    int i;
    std::string str;
    do{
        std::cout<<"Строение отправителя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if( (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') )
                break;
        }

        if( str[i]){std::cout<<"Строение нужно вводить без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}


std::string CheckRecipientName()
{
    int i;
    std::string str;
    do{
        std::cout<<"Имя получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Имя нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}
std::string CheckRecipientSurname()
{
    int i;
    std::string str;
    do{
        std::cout<<"Фамилия получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Фамилию нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}
std::string CheckRecipientPatronymic()
{
    int i;
    std::string str;
    do{
        std::cout<<"Отчество получателя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Отчество нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}

std::string CheckSenderName()
{
    int i;
    std::string str;
    do{
        std::cout<<"Имя отправителя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Имя нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}
std::string CheckSenderSurname()
{
    int i;
    std::string str;
    do{
        std::cout<<"Фамилия отправителя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Фамилию нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}
std::string CheckSenderPatronymic()
{
    int i;
    std::string str;
    do{
        std::cout<<"Отчество отправителя: ";
        std::cin>>str;

        for(i=0;str[i];i++)
        {
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{') or (str[0]!=toupper(str[0])) )
                break;
        }

        if( str[i]){std::cout<<"Отчество нужно вводить с Большой буквы и без посторонних символов"<<std::endl<<"Повторите ввод"<<std::endl; }



    }while(str[i]);

    return str;
}