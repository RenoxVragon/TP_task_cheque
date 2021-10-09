#pragma once
#include "product.h"

using namespace std;

class Purchase 
{
private:
	Product product;
	int count;
	double total_price = 0.0;

	
public:

	Purchase(Product& _product, int _count = 0);
	~Purchase() = default;
	virtual void print_info() = 0;
	void set_product(Product& _product);
	Product get_product();
	void set_count(int _count);
	int get_count();
	void set_total_price();
	double get_total_price();
};