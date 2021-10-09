#include "purchase.h"

Purchase::Purchase(Product& _product, int _count)
{
	this->set_product(_product);
	this->set_count(_count);
	this->set_total_price();
}

void Purchase::set_product(Product& _product)
{
	product = _product;
}

Product Purchase::get_product()
{
	return product;
}

void Purchase::set_count(int _count)
{
	count = _count;
}

int Purchase::get_count()
{
	return count;
}

void Purchase::set_total_price()
{
	total_price = count * product.get_price();
}

double Purchase::get_total_price()
{
	return total_price;
}