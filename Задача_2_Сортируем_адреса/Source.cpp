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
	{
		city = "Неуказан";
		street = "Неуказан";
		number_home = 0;
		number_apartament = 0;
	}

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

	std::string Read_city()
	{
		return this->city;
	}

	void Sort_Address_array(Address* Address_array, int size)
	{
		for (size_t i = 0; i < size-1; i++)
		{
			std::string buf;

			for (size_t y = i; y > 0; y--)
			{
				if (Address_array[y].Read_city() > Address_array[y + 1].Read_city())
				{
					std::swap(Address_array[y], Address_array[y + 1]);
					/*buf = Address_array[y].city;
					Address_array[y].city = Address_array[y + 1].city;
					Address_array[y + 1].city = buf;
					buf = Address_array[y].street;
					Address_array[y].street = Address_array[y + 1].street;
					Address_array[y + 1].street = buf;
					std::swap(Address_array[y].number_home, Address_array[y + 1].number_home);
					std::swap(Address_array[y].number_apartament, Address_array[y + 1].number_apartament);*/

				}
			}
		}
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

	std::ifstream f_in("E:\\Project\\ООП_Абстракция_и_инкапсуляция\\Задача_2_Сортируем_адреса\\in.txt");
	std::ofstream f_out("E:\\Project\\ООП_Абстракция_и_инкапсуляция\\Задача_2_Сортируем_адреса\\out.txt");

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
	

	Address* Address_array = new Address[size];

	for (int i = 0; i < size; i++)
	{
		f_in >> city >> street >> number_home >> number_apartament;
		Address_array[i] = { city, street, number_home, number_apartament };
	}

	Address_array->Sort_Address_array(Address_array, size);



	for (size_t i = 0; i < size; i++)
	{
		f_out << Address_array[i].Writing_class();
	}


	delete[] Address_array;
	//std::cout<<Address_array[0].Writing_class();
	return 0;
}