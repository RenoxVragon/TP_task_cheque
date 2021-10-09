#pragma once
#include <iostream>
using namespace std;

class Product
{
private:
	string name;
	double price;
public:
	Product(string _name = "", double _price = 0.0);
	~Product() = default;
	void set_name(string _name);
	string get_name();
	void set_price(double _price);
	double get_price();
};