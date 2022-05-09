#pragma once
#include <iostream>
#include <string>

using namespace std;

class Currency {

private:
	int bills;
	double cents;

public:
	//default constructor, no params
	Currency() : bills{ 0 }, cents{ 0 }{};

	//constructor, one param
	Currency(double input)
	{
		//isolate decimal portion of input
		double whole, fractional;
		fractional = std::modf(input, &whole);

		bills = whole;
		cents = fractional;
	}

	//copy constructor
	Currency(const Currency &c)
	{
		bills = c.bills;
		cents = c.cents;
	}

	//destuctor
	~Currency()
	{
	}


	virtual void print() 
	{
		std::cout << "Currency: " << "Bills: " << bills << " Cents: " << cents << endl;
	};
	virtual void add(string currency, double value)
	{
		std::cout << "Base addition" << endl;
	}
	virtual void subtract(string currency, double value)
	{
		std::cout << "Base subtract" << endl;
	}
	int getBills() { return bills; };
	double getCents() { return cents; };
	void setBills(int x) { bills = x; };
	void setCents(double x) { cents = x; };

	virtual void isEqual(string currency, double value)
	{
		std::cout << "Base isEqual" << endl;
	}

	virtual void isGreater(string currency, double value)
	{
		std::cout << "Base isGreater" << endl;
	}


};
