#include "cheque.h"

Cheque::Cheque(Product& _product, int _count) : Purchase(_product, _count) {}

void Cheque::print_info()
{
	cout << "Наименование: " << Purchase::get_product().get_name() << " " << "Цена: " << Purchase::get_product().get_price() << endl;
	cout << "Количество товара: " << Purchase::get_count() << endl;
	cout << "Итоговая сумма: " << Purchase::get_total_price() << endl;
}

void Cheque::file_save()
{
	ofstream fout;
	fout.open("output.txt", ofstream::app);
	fout << "Наименование: " << Purchase::get_product().get_name() << " " << "Цена: " << Purchase::get_product().get_price() << endl;
	fout << "Количество товара: " << Purchase::get_count() << endl;
	fout << "Итоговая сумма: " << Purchase::get_total_price() << endl;
	fout.close();
}