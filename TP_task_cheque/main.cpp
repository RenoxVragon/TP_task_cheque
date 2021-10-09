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

vector<Product> list_products = { {"������", 189.99}, {"��������", 49.99}, {"���� ��������������", 20.99}, 
	{"���� �������", 49.99},{"�������", 239.99}, {"�����", 59.99}, {"������", 39.99}, {"���", 129.99} };
vector<Cheque> list_purchases;

void print_list_products()
{
	cout << "������ �������, ��������� � �������: " << endl;
	for (int i = 0; i < list_products.size(); i++)
	{
		cout << i << ". " << list_products[i].get_name() << ". ����: " << list_products[i].get_price() << endl;
	}
}

void print_list_purchases()
{
	cout << "������ � �������: " << endl;
	if (list_purchases.size() != 0)
	{
		for (int i = 0; i < list_purchases.size(); i++)
		{
			cout << i << "-��� �����: " << endl;
			list_purchases[i].print_info();
		}
	}
	else
		cout << "������� �����." << endl;
}

void process_purchase()
{
	cout << "��� �� ������ ����������?" << endl;
	print_list_products();
	int id;
	int count;
	int input_flag = 1;
	while (input_flag)
	{
		cin >> id;
		if (cin.fail() || id < 0 || id >= list_products.size()) // ���� ������ �� ����� ����
		{
			cin.clear();
			cout << "������ �������� �����. ���������� ��� ���: " << endl;
		}
		else
		{
			cout << "������� ���������� ������: " << endl;
			
			int flag = 1;
			while (flag)
			{
				cin >> count;
				if (cin.fail() || count < 0 || id > INT32_MAX) // ���� ������ �� ����� ����
				{
					cin.clear();
					cout << "������� ������������ ����������, ���������� ��� ���:  " << endl;
				}
				else
				{
					flag = 0;
				}
				cin.ignore(32767, '\n');
			}
			cout << "���� ��������, ������� Enter ��� �����������." << endl;
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
		cout << "��������, ����� ����� �� ������ �������: " << endl;
		print_list_purchases();
		vector<Cheque>::iterator id = list_purchases.begin();
		int i;
		int flag = 1;
		while (flag)
		{
			cin >> i;
			if (cin.fail() || i < 0 || i >= list_purchases.size()) // ���� ������ �� ����� ����
			{
				cin.clear();
				cout << "������ �������� �����. ���������� �����: " << endl;
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
		cout << "������� �����, ������ �������." << endl;
}

string cashiers[3] = { "����������� �.�", "���������� �. �.", "�������� �. �." };

void print_cheque()
{
	time_t now = time(0);
	srand(now);
	tm* ltm = localtime(&now);
	ofstream fout;
	fout.open("output.txt", ofstream::app);
	fout << '\n';
	fout << "��� �������: " << cashiers[rand() % 3] << endl;
	fout << "����: " << ltm->tm_mday << "." << 1+ltm->tm_mon << "." << 1900 + ltm->tm_year << endl;
	fout << "����� �������: " <<  ltm->tm_hour << ":" <<  ltm->tm_min << ":" <<  ltm->tm_sec << endl;
	fout.close();
	if (list_purchases.size() > 0)
	{
		for (int i = 0; i < list_purchases.size(); i++)
		{
			list_purchases[i].file_save();
		}
	}
	fout.open("output.txt", ofstream::app);
	fout << "��� '����������'" << endl;
	fout << "������� �� �������!" << endl;
	fout.close();
}

void print_menu()
{
	cout << "1. �������� ������ �������." << endl;
	cout << "2. ���������� ������ � �������." << endl;
	cout << "3. �������� ������ �� �������." << endl;
	cout << "4. �������� �������." << endl;
	cout << "5. ���������� ���." << endl;
	cout << "0. ����� �� ���������." << endl;
}

int choice_menu() // ��������� ���������� ������ ������ ����
{
	int method;
	while (true)
	{
		cin >> method;
		if (cin.fail() || method < 0 || method > 5) // ���� ������ �� ����� ����
		{
			cin.clear();
			cout << "������ �������� ����� ����. ���������� ��� ���." << endl;
		}
		else
		{
			return method;
		}
		cin.ignore(32767, '\n');
	}
	return method;
}
int menu_selection(int number) // ��������� ������ ������ ����.
{
	switch (number) // ����������� ������ ����
	{
	case 1: // ����� ������ �������
		print_list_products();
		break;
	case 2: // ���������� � �������
		process_purchase();
		break;
	case 3: // �������� �� �������
		delete_purchase();
		break;
	case 4: // ������ �������
		print_list_purchases();
		break;
	case 5: // ������ ����
		print_cheque();
		break;
	case 0: // ����� �� ���������
		exit(0);
		break;
	default: // ������ �������� �����
		cout << "������ �������� ����� ����. ���������� ��� ���." << endl;
		break;
	}
}

void main() //������� �������
{
	setlocale(LC_ALL, "Russian");
	while (1) // ����������� ���� ������ ���������
	{
		print_menu(); // ����� ����
		int choice = choice_menu(); // ��������� ������ ������
		menu_selection(choice);
	}
}