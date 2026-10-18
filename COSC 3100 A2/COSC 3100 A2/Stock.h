#ifndef STOCK_H
#define STOCK_H

//*****************************************************************************************************

#include <string>
using namespace std;

//*****************************************************************************************************

class Stock
{
private:
    string companyName;
    string stockSymbol;
    double price;

public:
    Stock(const string& n = "", const string& s = "", double p = 0);
    Stock(const Stock& s);
    void display() const;
    string getName() const;
    string getSymbol() const;
    double getPrice() const;
    bool operator == (const Stock& rhs) const;
    bool operator != (const Stock& rhs) const;
    bool operator < (const Stock& rhs) const;
    bool operator > (const Stock& rhs) const;
};

//*****************************************************************************************************

Stock::Stock(const string& n, const string& s, double p)
{
    companyName = n;
    stockSymbol = s;
    price = p;
}

//*****************************************************************************************************

Stock::Stock(const Stock& s)
{
    companyName = s.companyName;
    stockSymbol = s.stockSymbol;
    price = s.price;
}

//*****************************************************************************************************

void Stock::display() const 
{
    cout << companyName << " (" << stockSymbol << ") - $" << price << endl;
}

string Stock::getName() const 
{
    return companyName;
}

//*****************************************************************************************************

string Stock::getSymbol() const 
{
    return stockSymbol;
}

//*****************************************************************************************************

double Stock::getPrice() const 
{
    return price;
}

//*****************************************************************************************************

bool Stock::operator==(const Stock& rhs) const 
{
    return (companyName == rhs.companyName &&
                stockSymbol == rhs.stockSymbol &&
                price == rhs.price);
}

//*****************************************************************************************************

bool Stock::operator!=(const Stock& rhs) const 
{
    return !(*this == rhs);
}

//*****************************************************************************************************

bool Stock::operator<(const Stock& rhs) const 
{
    return companyName < rhs.companyName;
}

bool Stock::operator>(const Stock& rhs) const
{
    return companyName > rhs.companyName;
}

//*****************************************************************************************************
#endif