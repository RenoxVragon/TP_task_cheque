#pragma once
#include "purchase.h"
#include <fstream>

class Cheque :public Purchase
{
public:
	Cheque(Product& _product, int _count = 0);
	~Cheque() = default;
	virtual void print_info();
	void file_save();
};