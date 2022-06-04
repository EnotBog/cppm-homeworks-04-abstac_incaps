#include <cstdio>
#include <windows.h>

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <windows.h>
#include <locale.h>
#include <fstream>




static std::ifstream f_in("E:\\Project\\ООП_Абстракция_и_инкапсуляция\\Задача_1_Адрес\\in.txt");
static std::ofstream f_out("E:\\Project\\ООП_Абстракция_и_инкапсуляция\\Задача_1_Адрес\\out.txt");

class Address
{
public:

	std::string city;
	std::string street;
	int number_home;
	int number_apartament;
	Address();
	void Fill_class() { Filling_class(); };
	void Write_class() { Writing_class(); }
private:
	int complited = 0;// индикатор заполнения класса

	void Filling_class() //функция заполнения класса
	{
		std::string buf_fill_class;
		int buf;
		f_in >> buf_fill_class;
		this->city = buf_fill_class;
		f_in >> buf_fill_class;
		this->street = buf_fill_class;
		f_in >> buf;
		this->number_home = buf;
		f_in >> buf;
		this->number_apartament = buf;
		this->complited = 1; //статус класса
	}

	void Writing_class() //функция записи в файл
	{
		if (complited == 1)
		{
			f_out << this->city << ", ";
			f_out << this->street << ", ";
			f_out << this->number_home << ", ";
			f_out << this->number_apartament << std::endl;
		}
		else { std::cout << " The class is not filled"; }
	}

};

Address::Address()
{

}


void Create_head()
{
	std::string buf;
	f_in >> buf;
	f_out << buf << "\n";
};


void close_file()
{
	f_in.close();
	f_out.close();
};


int main()
{
	SetConsoleOutputCP(65001);


	if (f_in.is_open() == 1 && f_out.is_open() == 1) // проверка файлов на открытие
	{

	}
	else
	{
		std::cerr << "The file was not opened";
		return 0;
	}

	Create_head();//создание заголовка

	Address A1, A2, A3, A4, A5, A6, A7, A8, A9, A10;
	// функционал класса 
	//Fill_class заполнить класс из файла in.txt
	//Write_class записать класс в файл out.txt


	A1.Fill_class();
	A1.Write_class();
	A2.Fill_class();
	A2.Write_class();



	close_file();
}