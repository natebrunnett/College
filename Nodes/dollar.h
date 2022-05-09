#pragma once
#include "currency.h"

class Dollar : public Currency {

	void print() {
		double value = this->getBills() + this->getCents();
		cout << value << " Dollar" << endl;
	};

	void add(string currency, double value) override 
	{
		if (currency == "dollar")
		{	
			//isolate decimal portion of input
			double whole, fractional;
			fractional = std::modf(value, &whole);

			this->setBills(this->getBills() + whole);
			this->setCents(this->getCents() + fractional);
		}
		else 
			std::cout << "invalid addition " << endl; 
		
	
	};

	void subtract(string currency, double value) override {
		if (currency == "dollar")
		{
			//isolate decimal portion of input
			double whole, fractional;
			fractional = std::modf(value, &whole);

			this->setBills(this->getBills() - whole);
			this->setCents(this->getCents() - fractional);
		}
		else
			std::cout << "invalid subtraction " << endl;
	}

	void isEqual(string currency, double value) override
	{
		if (currency == "dollar")
		{
			std::cout << "Enter value e.x: 50.00 dollar" << endl;
			double value2; string currency2;
			cin >> value2; cin >> currency2;
			if (currency2 == "dollar")
			{
				if (value == value2)
					std::cout << "true\n" << endl;
				else
					std::cout << "false\n" << endl;
			}
			else std::cout << "invalid isEqual comparison --inner loop" << endl;
		}
		else
			std::cout << "invalid isEqual comparison " << endl;
	}

	void isGreater(string currency, double value) override
	{
		if (currency == "dollar")
		{
			std::cout << "Enter value e.x: 50.00 dollar" << endl;
			double value2; string currency2;
			cin >> value2; cin >> currency2;
			if (currency2 == "dollar")
			{
				if (value > value2)
					std::cout << value << " is greater than " << value2 << endl;
				else
					std::cout << value << " is less than " << value2 << endl;
			}
			else std::cout << "invalid isGreater comparison --inner loop" << endl;
		}
		else
			std::cout << "invalid isGreater comparison " << endl;

	}

};

