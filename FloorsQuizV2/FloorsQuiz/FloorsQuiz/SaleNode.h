#pragma once
#include <iostream>
using namespace std;

class SaleNode
{
private:
    double price;
    SaleNode* saleNext;
public:
    SaleNode(int);
    ~SaleNode();

    double getPrice();
    SaleNode* getSaleNext();

    void setPrice(double);
    void setSaleNext(SaleNode*);
};

