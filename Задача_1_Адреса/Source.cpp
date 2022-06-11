#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>


class Address
{
public:

	Address()
	{}

	Address(std::string C, std::string S, int NH, int NA)
	{
		city = C;
		street = S;
		number_home = NH;
		number_apartament = NA;
	}
	std::string Writing_class() //функция создания строки
	{
		std::string s = this->city + ", " + this->street + ", " + std::to_string(this->number_home) + ", " + std::to_string(this->number_apartament) + "\n";
		return s;
	}


private:
	std::string city;
	std::string street;
	int number_home;
	int number_apartament;
};




int main()
{
	SetConsoleOutputCP(65001);

	std::ifstream f_in("E:\\Project\\ООП_Абстракция_и_инкапсуляция\\Задача_1_Адреса\\in.txt");
	std::ofstream f_out("E:\\Project\\ООП_Абстракция_и_инкапсуляция\\Задача_1_Адреса\\out.txt");

	if (f_in.is_open() == 1 && f_out.is_open() == 1) // проверка файлов на открытие
	{

	}
	else
	{
		std::cerr << "The file was not opened" << std::endl;
		return 1;
	}

	int size = 0;
	std::string city, street;
	int number_home, number_apartament;
	std::string string_buf;

	f_in >> string_buf;
	f_out << string_buf << "\n";
	size = stoi(string_buf);
	std::cout << f_in.is_open();

	Address* Address_array = new Address[size];

	for (int i = 0; i < size; i++)
	{
		f_in >> city >> street >> number_home >> number_apartament;
		Address_array[i] = { city, street, number_home, number_apartament };
	}

	for (size_t i = 0; i < size; i++)
	{
		f_out << Address_array[i].Writing_class();
	}

	delete[] Address_array;
	//std::cout<<Address_array[0].Writing_class();
	return 0;
}