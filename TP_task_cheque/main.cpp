#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
#include "product.h"
#include "purchase.h"
#include "cheque.h"
using namespace std;

vector<Product> list_products = { {"Курица", 189.99}, {"Макароны", 49.99}, {"Вода бутилированная", 20.99}, 
	{"Яйца куриные", 49.99},{"Свинина", 239.99}, {"Сахар", 59.99}, {"Гречка", 39.99}, {"Сыр", 129.99} };
vector<Cheque> list_purchases;

void print_list_products()
{
	cout << "Список товаров, доступных к покупке: " << endl;
	for (int i = 0; i < list_products.size(); i++)
	{
		cout << i << ". " << list_products[i].get_name() << ". Цена: " << list_products[i].get_price() << endl;
	}
}

void print_list_purchases()
{
	cout << "Товары в корзине: " << endl;
	if (list_purchases.size() != 0)
	{
		for (int i = 0; i < list_purchases.size(); i++)
		{
			cout << i << "-тый товар: " << endl;
			list_purchases[i].print_info();
		}
	}
	else
		cout << "Корзина пуста." << endl;
}

void process_purchase()
{
	cout << "Что вы хотите приобрести?" << endl;
	print_list_products();
	int id;
	int count;
	int input_flag = 1;
	while (input_flag)
	{
		cin >> id;
		if (cin.fail() || id < 0 || id >= list_products.size()) // если введен не пункт меню
		{
			cin.clear();
			cout << "Выбран неверный товар. Попробуйте еще раз: " << endl;
		}
		else
		{
			cout << "Введите количество товара: " << endl;
			
			int flag = 1;
			while (flag)
			{
				cin >> count;
				if (cin.fail() || count < 0 || id > INT32_MAX) // если введен не пункт меню
				{
					cin.clear();
					cout << "Введено некорректное количество, попробуйте еще раз:  " << endl;
				}
				else
				{
					flag = 0;
				}
				cin.ignore(32767, '\n');
			}
			cout << "Ввод завершен, нажмите Enter для продолжения." << endl;
			input_flag = 0;
		}
		cin.ignore(32767, '\n');
		
	}
	Cheque cheq = { list_products[id], count};
	list_purchases.push_back(cheq);
}

void delete_purchase()
{
	if (list_purchases.size() > 0)
	{
		cout << "Выберите, какой товар вы хотите удалить: " << endl;
		print_list_purchases();
		vector<Cheque>::iterator id = list_purchases.begin();
		int i;
		int flag = 1;
		while (flag)
		{
			cin >> i;
			if (cin.fail() || i < 0 || i >= list_purchases.size()) // если введен не пункт меню
			{
				cin.clear();
				cout << "Выбран неверный товар. Попробуйте снова: " << endl;
			}
			else
			{
				id += i;
				list_purchases.erase(id);
				flag = 0;
			}
			cin.ignore(32767, '\n');
		}
	}
	else
		cout << "Корзина пуста, нечего удалять." << endl;
}

string cashiers[3] = { "Филимоненко Г.С", "Кардимонов А. В.", "Архипова С. С." };

void print_cheque()
{
	time_t now = time(0);
	srand(now);
	tm* ltm = localtime(&now);
	ofstream fout;
	fout.open("output.txt", ofstream::app);
	fout << '\n';
	fout << "ФИО Кассира: " << cashiers[rand() % 3] << endl;
	fout << "Дата: " << ltm->tm_mday << "." << 1+ltm->tm_mon << "." << 1900 + ltm->tm_year << endl;
	fout << "Время покупки: " <<  ltm->tm_hour << ":" <<  ltm->tm_min << ":" <<  ltm->tm_sec << endl;
	fout.close();
	if (list_purchases.size() > 0)
	{
		for (int i = 0; i < list_purchases.size(); i++)
		{
			list_purchases[i].file_save();
		}
	}
	fout.open("output.txt", ofstream::app);
	fout << "ООО 'Шестерочка'" << endl;
	fout << "СПАСИБО ЗА ПОКУПКУ!" << endl;
	fout.close();
}

void print_menu()
{
	cout << "1. Просмотр списка товаров." << endl;
	cout << "2. Добавление товара в корзину." << endl;
	cout << "3. Удаление товара из корзины." << endl;
	cout << "4. Просмотр корзины." << endl;
	cout << "5. Напечатать чек." << endl;
	cout << "0. Выход из программы." << endl;
}

int choice_menu() // обработка введенного выбора пункта меню
{
	int method;
	while (true)
	{
		cin >> method;
		if (cin.fail() || method < 0 || method > 5) // если введен не пункт меню
		{
			cin.clear();
			cout << "Выбран неверный пункт меню. Попробуйте еще раз." << endl;
		}
		else
		{
			return method;
		}
		cin.ignore(32767, '\n');
	}
	return method;
}
int menu_selection(int number) // обработка выбора пункта меню.
{
	switch (number) // определение пункта меню
	{
	case 1: // вывод списка товаров
		print_list_products();
		break;
	case 2: // добавление в корзину
		process_purchase();
		break;
	case 3: // удаление из корзины
		delete_purchase();
		break;
	case 4: // печать корзины
		print_list_purchases();
		break;
	case 5: // печать чека
		print_cheque();
		break;
	case 0: // выход из программы
		exit(0);
		break;
	default: // выбран неверный пункт
		cout << "Выбран неверный пункт меню. Попробуйте еще раз." << endl;
		break;
	}
}

void main() //главная функция
{
	setlocale(LC_ALL, "Russian");
	while (1) // бесконечный цикл работы программы
	{
		print_menu(); // вывод меню
		int choice = choice_menu(); // обработка выбора пункта
		menu_selection(choice);
	}
}