#include "cheque.h"

Cheque::Cheque(Product& _product, int _count) : Purchase(_product, _count) {}

void Cheque::print_info()
{
	cout << "������������: " << Purchase::get_product().get_name() << " " << "����: " << Purchase::get_product().get_price() << endl;
	cout << "���������� ������: " << Purchase::get_count() << endl;
	cout << "�������� �����: " << Purchase::get_total_price() << endl;
}

void Cheque::file_save()
{
	ofstream fout;
	fout.open("output.txt", ofstream::app);
	fout << "������������: " << Purchase::get_product().get_name() << " " << "����: " << Purchase::get_product().get_price() << endl;
	fout << "���������� ������: " << Purchase::get_count() << endl;
	fout << "�������� �����: " << Purchase::get_total_price() << endl;
	fout.close();
}