#include "product.h"

Product::Product(string _name, double _price) 
{
	this->set_name(_name);
	this->set_price(_price);
}

void Product::set_name(string _name)
{
	name = _name;
}

void Product::set_price(double _price)
{
	price = _price;
}

double Product::get_price()
{
	return price;
}

string Product::get_name()
{
	return name;
}